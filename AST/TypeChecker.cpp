#include "TypeChecker.h"

void TypeChecker::createEnv(ASTRoot* node) {
    // class
    for (auto cchild : node->classList) {
        auto obj = dynamic_cast<ASTClassDecl*>(cchild.get());
        if (!Builtin::checkVarName(obj->name))
            issue->issue(obj->pos, "expected unqualified-id");
        else {
            classInfo cinfo;
            if (!env->classTable.insert(obj->name, cinfo))
                issue->issue(obj->pos, "redefinition of '" + obj->name + "'");
        }
    }
    for (auto cchild : node->classList) {
        auto obj = dynamic_cast<ASTClassDecl*>(cchild.get());
        if (!Builtin::checkVarName(obj->name))
            continue;
        // check memberFunction
        classInfo &cinfo = env->classTable.find(obj->name);
        for (auto fchild : obj->funcList) {
            auto func = dynamic_cast<ASTFuncDecl*>(fchild.get());
            if (!Builtin::checkVarName(func->name))
                issue->issue(func->pos, "expected unqualified-id");
            else if (func->name != obj->name && env->classTable.count(func->name))
                issue->issue(func->pos, "redefinition of '" + func->name + "' as function");
            else if (func->retType == typeNull && func->name != obj->name)
                issue->issue(func->pos, "requires a type specifier for function");
            else if (func->retType != typeNull && func->name == obj->name)
                issue->issue(func->pos, "constructor cannot have a return type");
            else {
                if (func->retType == typeNull)
                    func->retType = typeVoid;
                funcInfo finfo;
                finfo.retType = func->retType;
                // check parameters
                for (auto vchild : func->paras) {
                    auto para = dynamic_cast<ASTVarDecl *>(vchild.get());
                    finfo.parasType.push_back(para->varType);
                }
                if (!cinfo.memberFunc.insert(func->name, finfo))
                    issue->issue(func->pos, "redefinition of '" + func->name + "'");
            }
        }
        // check memberVar
        for (auto vchild : obj->varList) {
            auto var = dynamic_cast<ASTVarDecl*>(vchild.get());
            for (int idx = 0; idx < var->name.size(); idx++) {
                if (!Builtin::checkVarName(var->name[idx]))
                    issue->issue(var->pos, "expected unqualified-id");
                else if (env->classTable.count(var->name[idx]))
                    issue->issue(var->pos, "redefinition of '" + var->name[idx] + "' as variable");
                else {
                    varInfo vinfo;
                    vinfo.varType = var->varType;
                    if (!cinfo.memberVar.insert(var->name[idx], vinfo))
                        issue->issue(var->pos, "redefinition of '" + var->name[idx] + "'");
                }
            }
        }
    }
    // check function
    for (auto fchild : node->funcList) {
        auto func = dynamic_cast<ASTFuncDecl*>(fchild.get());
        if (!Builtin::checkVarName(func->name))
            issue->issue(func->pos, "expected unqualified-id");
        else if (env->classTable.count(func->name))
            issue->issue(func->pos, "redefinition of '" + func->name + "' as function");
        else if (func->retType == typeNull)
            issue->issue(func->pos, "requires a type specifier for function");
        else {
            funcInfo finfo;
            finfo.retType = func->retType;
            // check parameters
            for (auto vchild : func->paras) {
                auto para = dynamic_cast<ASTVarDecl *>(vchild.get());
                finfo.parasType.push_back(para->varType);
            }
            if (!env->funcTable.insert(func->name, finfo))
                issue->issue(func->pos, "redefinition of '" + func->name + "'");
        }
    }

    if (env->funcTable.count("main") == 0)
        issue->issue(0, "no main function");
    else {
        if (env->funcTable.find("main").retType != typeInt)
            issue->issue(0, "main function must return int value");
        if (env->funcTable.find("main").parasType.size() > 0)
            issue->issue(0, "main function should not have parameters.");
    }
}

void TypeChecker::typeCheck(ASTRoot* node) {
    visit(node);
}

void TypeChecker::visit(ASTNode* node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(ASTRoot* node)
{
    env->funcTable.beginScope();
    env->varTable.beginScope();
    ASTVisitor::visit(node);
    env->funcTable.endScope();
    env->varTable.endScope();
}

void TypeChecker::visit(ASTStmt* node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(ASTStmtBreak* node) {
    if (env->inLoop == 0)
        issue->issue(node->pos, "'break' statement not in loop");
}

void TypeChecker::visit(ASTStmtContinue* node) {
    if (env->inLoop == 0)
        issue->issue(node->pos, "'continue' statement not in loop");
}

void TypeChecker::visit(ASTStmtReturn* node) {
    type_t expectedType;
    env->hasReturn = true;
    if (env->inClass > 0)
        expectedType = env->classTable.find(env->className).memberFunc.find(env->funcName).retType;
    else
        expectedType = env->funcTable.find(env->funcName).retType;

    if (node->retValue) {
        auto retValue = dynamic_cast<ASTExpr*>(node->retValue.get());
        visit(retValue);
        node->retType = retValue->exprType;
    }
    else {
        node->retType = typeVoid;
    }

    if (node->retType != expectedType && !(expectedType.dim > 0 && node->retType == typeNull) &&
        !(expectedType.kind == type_t::ty_class && node->retType == typeNull))
        issue->issue(node->pos, "invalid function return type");
}

void TypeChecker::visit(ASTStmtFor* node) {
    env->varTable.beginScope();
    env->inLoop += 1;
    ASTVisitor::visit(node);
    if (node->cond) {
        auto child = dynamic_cast<ASTExpr*>(node->cond.get());
        if (child->exprType != typeBool)
            issue->issue(child->pos, "requires bool type for condition of for-loop");
    }
    env->varTable.endScope();
    env->inLoop -= 1;
}

void TypeChecker::visit(ASTStmtWhile* node) {
    env->varTable.beginScope();
    env->inLoop += 1;
    ASTVisitor::visit(node);
    auto child = dynamic_cast<ASTExpr*>(node->cond.get());
    if (child->exprType != typeBool)
        issue->issue(child->pos, "requires bool type for condition of while-loop");
    env->varTable.endScope();
    env->inLoop -= 1;
}

void TypeChecker::visit(ASTStmtIf* node) {
    visit(dynamic_cast<ASTExpr*>(node->cond.get()));
    if (node->thenStmt) {
        env->varTable.beginScope();
        visit(dynamic_cast<ASTStmt*>(node->thenStmt.get()));
        env->varTable.endScope();
    }
    if (node->elseStmt) {
        env->varTable.beginScope();
        visit(dynamic_cast<ASTStmt*>(node->elseStmt.get()));
        env->varTable.endScope();
    }
    auto child = dynamic_cast<ASTExpr*>(node->cond.get());
    if (child->exprType != typeBool)
        issue->issue(child->pos, "requires bool type for condition of if-statement");
}

void TypeChecker::visit(ASTStmtExpr* node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(ASTClassDecl* node) {
    env->funcTable.beginScope();
    env->varTable.beginScope();
    env->inClass += 1;
    env->className = node->name;
    for (auto child : env->classTable.find(node->name).memberFunc)
        env->funcTable.insert(child);
    for (auto child : env->classTable.find(node->name).memberVar)
        env->varTable.insert(child);
    for (auto child : node->funcList)
        visit(dynamic_cast<ASTFuncDecl*>(child.get()));
    env->funcTable.endScope();
    env->varTable.endScope();
    env->inClass -= 1;
}

void TypeChecker::visit(ASTBlock* node) {
    env->varTable.beginScope();
    ASTVisitor::visit(node);
    env->varTable.endScope();
}

void TypeChecker::visit(ASTFuncDecl* node) {
    env->varTable.beginScope();
    env->inFunc = true;
    env->hasReturn = false;
    env->funcName = node->name;
    ASTVisitor::visit(node);
    env->varTable.endScope();
    if (!env->hasReturn && node->retType != typeVoid && node->name != "main")
        issue->issue(node->pos, "Non-void function must have a return value");
    env->inFunc = false;
}

void TypeChecker::visit(ASTVarDecl* node) {
    ASTVisitor::visit(node);
    for (int idx = 0; idx < node->name.size(); idx++) {
        if (!Builtin::checkVarName(node->name[idx]))
            issue->issue(node->pos, "expected unqualified-id");
        varInfo vinfo;
        vinfo.varType = node->varType;
        if (node->varType.kind == type_t::ty_void)
            issue->issue(node->pos, "type of variable cannot be void");
        else if (node->varType.kind == type_t::ty_class && !env->classTable.count(node->varType.name))
            issue->issue(node->pos, "definition of class '" + node->varType.name + "' doesnot exist");
        else if (!env->varTable.insert(node->name[idx], vinfo))
            issue->issue(node->pos, "redefinition of '" + node->name[idx] + "'");
        if (node->initValue[idx]) {
            auto initValue = dynamic_cast<ASTExpr *>(node->initValue[idx].get());
            if (initValue->exprType != node->varType && !(node->varType.dim > 0 && initValue->exprType == typeNull) &&
                !(node->varType.kind == type_t::ty_class && initValue->exprType == typeNull))
                issue->issue(node->pos, "type of init value doesnot match");
        }
    }
}

void TypeChecker::visit(ASTExpr* node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(ASTExprNew* node) {
    ASTVisitor::visit(node);
    if (node->exprType.kind == type_t::ty_void)
        issue->issue(node->pos, "type of variable cannot be void");
    else if (node->exprType.kind == type_t::ty_class && !env->classTable.count(node->exprType.name))
        issue->issue(node->pos, "definition of class '" + node->exprType.name + "' doesnot exist");
    for (auto child : node->paras) {
        auto para = dynamic_cast<ASTExpr *>(child.get());
        if (para) {
            if (para->exprType != typeInt)
                issue->issue(node->pos, "requires index of int type for new-statement");
        }
    }
}

void TypeChecker::visit(ASTExprAssign* node) {
    ASTVisitor::visit(node);
    auto operandL = dynamic_cast<ASTExpr*>(node->operandL.get());
    auto operandR = dynamic_cast<ASTExpr*>(node->operandR.get());
    if (operandL->exprType != operandR->exprType && !(operandL->exprType.dim > 0 && operandR->exprType == typeNull) &&
        !(operandL->exprType.kind == type_t::ty_class && operandR->exprType == typeNull))
        issue->issue(node->pos, "Assignment type doesnot match");
    if (operandL->valueType != lvalue)
        issue->issue(node->pos, "requires lvalue for assignment");
    node->exprType = operandR->exprType;
    node->valueType = rvalue;
}

void TypeChecker::visit(ASTExprBinary* node) {
    ASTVisitor::visit(node);
    auto operandL = dynamic_cast<ASTExpr*>(node->operandL.get());
    auto operandR = dynamic_cast<ASTExpr*>(node->operandR.get());
    if (node->op == ASTExprBinary::logic_or || node->op == ASTExprBinary::logic_and) {
        if (operandL->exprType != typeBool || operandR->exprType != typeBool)
            issue->issue(node->pos, "type error in binary arithmetic");
        else {
            node->exprType = operandL->exprType;
            node->valueType = rvalue;
        }
    }
    else if (node->op == ASTExprBinary::bitwise_or || node->op == ASTExprBinary::bitwise_xor ||
             node->op == ASTExprBinary::bitwise_and ||node->op == ASTExprBinary::minus ||
             node->op == ASTExprBinary::mul || node->op == ASTExprBinary::div ||
             node->op == ASTExprBinary::mod || node->op == ASTExprBinary::leftshift ||
             node->op == ASTExprBinary::rightshift) {
        if (operandL->exprType != typeInt || operandR->exprType != typeInt)
            issue->issue(node->pos, "type error in binary arithmetic");
        else {
            node->exprType = operandL->exprType;
            node->valueType = rvalue;
        }
    }
    else if (node->op == ASTExprBinary::plus) {
        if (!(operandL->exprType == typeString && operandR->exprType == typeString) &&
            !(operandL->exprType == typeInt && operandR->exprType == typeInt))
            issue->issue(node->pos, "type error in binary arithmetic");
        else {
            node->exprType = operandL->exprType;
            node->valueType = rvalue;
        }
    }
    else if (node->op == ASTExprBinary::equal || node->op == ASTExprBinary::not_equal) {
        if (!(operandL->exprType == typeString && operandR->exprType == typeString) &&
            !(operandL->exprType == typeInt && operandR->exprType == typeInt) &&
            !(operandL->exprType == typeBool && operandR->exprType == typeBool) &&
            !(operandL->exprType.dim > 0 && operandR->exprType == typeNull) &&
            !(operandL->exprType == typeNull && operandR->exprType.dim > 0) &&
            !(operandL->exprType.kind == type_t::ty_class && operandR->exprType == typeNull) &&
            !(operandL->exprType == typeNull && operandR->exprType.kind == type_t::ty_class) &&
            !(operandL->exprType == typeNull && operandR->exprType == typeNull))
            issue->issue(node->pos, "type error in binary arithmetic");
        else {
            node->exprType = typeBool;
            node->valueType = rvalue;
        }
    }
    else {
        if (!(operandL->exprType == typeString && operandR->exprType == typeString) &&
            !(operandL->exprType == typeInt && operandR->exprType == typeInt))
            issue->issue(node->pos, "type error in binary arithmetic");
        else {
            node->exprType = typeBool;
            node->valueType = rvalue;
        }
    }
}

void TypeChecker::visit(ASTExprUnary* node) {
    ASTVisitor::visit(node);
    auto operand = dynamic_cast<ASTExpr*>(node->operand.get());
    if (node->op == ASTExprUnary::inc_postfix || node->op == ASTExprUnary::dec_postfix ||
        node->op == ASTExprUnary::inc_prefix || node->op == ASTExprUnary::dec_prefix) {
        if (operand->exprType != typeInt)
            issue->issue(node->pos, "type error in unary arithmetic");
        else if (operand->valueType != lvalue)
            issue->issue(node->pos, "requires lvalue for ++ and --");
        else {
            node->exprType = typeInt;
            if (node->op == ASTExprUnary::inc_prefix || node->op == ASTExprUnary::dec_prefix)
                node->valueType = lvalue;
            else
                node->valueType = rvalue;
        }
    }
    else if (node->op == ASTExprUnary::positive || node->op == ASTExprUnary::negative ||
        node->op == ASTExprUnary::bitwise_not) {
        if (operand->exprType != typeInt)
            issue->issue(node->pos, "type error in unary arithmetic");
        else {
            node->exprType = typeInt;
            node->valueType = rvalue;
        }
    }
    else {
        if (operand->exprType != typeBool)
            issue->issue(node->pos, "type error in unary arithmetic");
        else {
            node->exprType = typeBool;
            node->valueType = rvalue;
        }
    }
}

void TypeChecker::visit(ASTExprSubscript* node) {
    ASTVisitor::visit(node);
    auto array = dynamic_cast<ASTExpr*>(node->array.get());
    auto subscript = dynamic_cast<ASTExpr*>(node->subscript.get());
    if (array->exprType.dim == 0)
        issue->issue(node->pos, "requires array for subscript");
    if (subscript->exprType != typeInt)
        issue->issue(node->pos, "requires index of int type for subscript");
    node->exprType = array->exprType;
    node->exprType.dim -= 1;
    node->valueType = lvalue;
}

void TypeChecker::visit(ASTExprFuncCall* node) {
    ASTVisitor::visit(node);
    if (!Builtin::checkVarName(node->name))
        issue->issue(node->pos, "expected unqualified-id");
    else {
        if (!env->funcTable.count(node->name))
            issue->issue(node->pos, "function" + node->name + "doesnot exist");
        else {
            funcInfo expectedFunc = env->funcTable.find(node->name);
            if (node->paras.size() != expectedFunc.parasType.size()) {
                issue->issue(node->pos, "number of function parameters doesnot match");
            } else {
                bool flag = true;
                for (int idx = 0; idx < node->paras.size(); idx++) {
                    auto para = dynamic_cast<ASTExpr *>(node->paras[idx].get());
                    if (para->exprType != expectedFunc.parasType[idx] && !(para->exprType == typeNull && expectedFunc.parasType[idx].dim > 0) &&
                        !(para->exprType == typeNull && expectedFunc.parasType[idx].kind == type_t::ty_class)) {
                        flag = false;
                        break;
                    }
                }
                if (!flag) {
                    issue->issue(node->pos, "type of function parameters doesnot match");
                } else {
                    node->exprType = expectedFunc.retType;
                    node->valueType = rvalue;
                }
            }
        }
    }
}

void TypeChecker::visit(ASTExprMemberAccess* node) {
    auto obj = dynamic_cast<ASTExpr*>(node->object.get());
    visit(obj);
    if (!obj->exprType.isClass() && obj->exprType.dim == 0)
        issue->issue(node->pos, "requires a object for member access");
    else {
        if (node->memberFunc) {
            auto func = dynamic_cast<ASTExprFuncCall *>(node->memberFunc.get());
            if (!Builtin::checkVarName(func->name))
                issue->issue(node->pos, "expected unqualified-id");
            else if (!env->classTable.find(obj->exprType.dim > 0 ? "" : obj->exprType.name).memberFunc.count(func->name))
                issue->issue(node->pos,
                             "class '" + (obj->exprType.dim > 0 ? "" : obj->exprType.name) + "' doesnot have function named '" + func->name + "'");
            else {
                funcInfo expectedFunc = env->classTable.find(obj->exprType.dim > 0 ? "" : obj->exprType.name).memberFunc.find(func->name);
                if (func->paras.size() != expectedFunc.parasType.size()) {
                    issue->issue(node->pos, "number of function parameters doesnot match");
                }
                else {
                    bool flag = true;
                    for (int idx = 0; idx < func->paras.size(); idx++) {
                        auto para = dynamic_cast<ASTExpr *>(func->paras[idx].get());
                        visit(para);
                        if (para->exprType != expectedFunc.parasType[idx] && !(para->exprType == typeNull && expectedFunc.parasType[idx].dim > 0) &&
                            !(para->exprType == typeNull && expectedFunc.parasType[idx].kind == type_t::ty_class)) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) {
                        issue->issue(node->pos, "type of function parameters doesnot match");
                    }
                    else {
                        node->exprType = expectedFunc.retType;
                        node->valueType = rvalue;
                    }
                }
            }
        }
        else {
            if (!env->classTable.find(obj->exprType.name).memberVar.count(node->memberVar)) {
                issue->issue(node->pos,
                             "class '" + obj->exprType.name + "' doesnot have function named '" + node->memberVar +
                             "'");
            }
            else {
                node->exprType = env->classTable.find(obj->exprType.name).memberVar.find(node->memberVar).varType;
                node->valueType = lvalue;
            }
        }
    }
}

void TypeChecker::visit(ASTExprVar* node) {
    if (node->isThis) {
        if (env->inClass == 0)
            issue->issue(node->pos, "'this' not in class");
        node->valueType = rvalue;
        node->exprType = type_t(type_t::ty_class, env->className, 0);
    }
    else {
        if (!Builtin::checkVarName(node->name))
            issue->issue(node->pos, "expected unqualified-id");
        else if (!env->varTable.count(node->name))
            issue->issue(node->pos, "undefined variable '" + node->name + "'");
        else
            node->exprType = env->varTable.find(node->name).varType;
        node->valueType = lvalue;
    }
}

void TypeChecker::visit(ASTExprLiteral* node) {}



