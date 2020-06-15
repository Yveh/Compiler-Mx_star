#include "TypeChecker.h"

void TypeChecker::createEnv(std::shared_ptr<ASTRoot> node) {
    // class
    for (auto cchild : node->classList) {
        auto obj = std::dynamic_pointer_cast<ASTClassDecl>(cchild);
        if (!Builtin::checkVarName(obj->name))
            issue->issue(obj->pos, "expected unqualified-id");
        else {
            classInfo cinfo;
            if (!env->classTable.insert(obj->name, cinfo))
                issue->issue(obj->pos, "redefinition of '" + obj->name + "'");
        }
    }
    for (auto cchild : node->classList) {
        auto obj = std::dynamic_pointer_cast<ASTClassDecl>(cchild);
        if (!Builtin::checkVarName(obj->name))
            continue;
        // check memberFunction
        classInfo &cinfo = env->classTable.find(obj->name);
        for (auto fchild : obj->funcList) {
            auto func = std::dynamic_pointer_cast<ASTFuncDecl>(fchild);
            if (!Builtin::checkVarName(func->name))
                issue->issue(func->pos, "expected unqualified-id");
            else if (func->name != obj->name && env->classTable.count(func->name))
                issue->issue(func->pos, "redefinition of '" + func->name + "' as function");
            else if (func->retType == typeNull && func->name != obj->name)
                issue->issue(func->pos, "requires a type specifier for function");
            else if (func->retType != typeNull && func->name == obj->name)
                issue->issue(func->pos, "constructor cannot have a return type");
            else {
                funcInfo finfo;
                if (func->retType == typeNull)
                    func->retType = typeVoid;
                finfo.retType = func->retType;
                // check parameters
                for (auto vchild : func->paras) {
                    auto para = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
                    finfo.parasType.push_back(para->varType);
                }
                if (!cinfo.memberFunc.insert(func->name, finfo))
                    issue->issue(func->pos, "redefinition of '" + func->name + "'");
            }
        }
        // check memberVar
        for (auto vchild : obj->varList) {
            auto var = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
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
        auto func = std::dynamic_pointer_cast<ASTFuncDecl>(fchild);
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
                auto para = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
                if (para->varType.isClass() && para->varType.name != "string")
                    para->varType.id = env->classTable.getOrder(para->varType.name);
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

void TypeChecker::typeCheck(std::shared_ptr<ASTRoot> node) {
    visit(node);
}

void TypeChecker::visit(std::shared_ptr<ASTNode> node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(std::shared_ptr<ASTRoot> node)
{
    env->funcTable.beginScope();
    env->varTable.beginScope();
    ASTVisitor::visit(node);
    env->funcTable.endScope();
    env->varTable.endScope();
}

void TypeChecker::visit(std::shared_ptr<ASTStmt> node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(std::shared_ptr<ASTStmtBreak> node) {
    if (inLoop == 0)
        issue->issue(node->pos, "'break' statement not in loop");
}

void TypeChecker::visit(std::shared_ptr<ASTStmtContinue> node) {
    if (inLoop == 0)
        issue->issue(node->pos, "'continue' statement not in loop");
}

void TypeChecker::visit(std::shared_ptr<ASTStmtReturn> node) {
    type_t expectedType;
    hasReturn = true;
    if (inClass > 0)
        expectedType = env->classTable.find(className).memberFunc.find(funcName).retType;
    else
        expectedType = env->funcTable.find(funcName).retType;

    if (node->retValue) {
        auto retValue = std::dynamic_pointer_cast<ASTExpr>(node->retValue);
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

void TypeChecker::visit(std::shared_ptr<ASTStmtFor> node) {
    env->varTable.beginScope();
    inLoop += 1;
    ASTVisitor::visit(node);
    if (node->cond) {
        auto child = std::dynamic_pointer_cast<ASTExpr>(node->cond);
        if (child->exprType != typeBool)
            issue->issue(child->pos, "requires bool type for condition of for-loop");
    }
    env->varTable.endScope();
    inLoop -= 1;
}

void TypeChecker::visit(std::shared_ptr<ASTStmtWhile> node) {
    env->varTable.beginScope();
    inLoop += 1;
    ASTVisitor::visit(node);
    auto child = std::dynamic_pointer_cast<ASTExpr>(node->cond);
    if (child->exprType != typeBool)
        issue->issue(child->pos, "requires bool type for condition of while-loop");
    env->varTable.endScope();
    inLoop -= 1;
}

void TypeChecker::visit(std::shared_ptr<ASTStmtIf> node) {
    visit(std::dynamic_pointer_cast<ASTExpr>(node->cond));
    if (node->thenStmt) {
        env->varTable.beginScope();
        visit(std::dynamic_pointer_cast<ASTStmt>(node->thenStmt));
        env->varTable.endScope();
    }
    if (node->elseStmt) {
        env->varTable.beginScope();
        visit(std::dynamic_pointer_cast<ASTStmt>(node->elseStmt));
        env->varTable.endScope();
    }
    auto child = std::dynamic_pointer_cast<ASTExpr>(node->cond);
    if (child->exprType != typeBool)
        issue->issue(child->pos, "requires bool type for condition of if-statement");
}

void TypeChecker::visit(std::shared_ptr<ASTStmtExpr> node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(std::shared_ptr<ASTClassDecl> node) {
    env->funcTable.beginScope();
    env->varTable.beginScope();
    inClass += 1;
    className = node->name;
    for (auto child : env->classTable.find(node->name).memberFunc)
        env->funcTable.insert(child);
    for (auto child : env->classTable.find(node->name).memberVar) {
        env->varTable.insert(child);
    }
    for (auto child : node->funcList)
        visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
    env->funcTable.endScope();
    env->varTable.endScope();
    inClass -= 1;
}

void TypeChecker::visit(std::shared_ptr<ASTBlock> node) {
    env->varTable.beginScope();
    ASTVisitor::visit(node);
    env->varTable.endScope();
}

void TypeChecker::visit(std::shared_ptr<ASTFuncDecl> node) {
    env->varTable.beginScope();
    hasReturn = false;
    funcName = node->name;
    ASTVisitor::visit(node);
    env->varTable.endScope();
    if (!hasReturn && node->retType != typeVoid && node->name != "main")
        issue->issue(node->pos, "Non-void function must have a return value");
}

void TypeChecker::visit(std::shared_ptr<ASTVarDecl> node) {
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
        node->id.push_back(env->varTable.getOrder(node->name[idx]));
        if (node->initValue[idx]) {
            auto initValue = std::dynamic_pointer_cast<ASTExpr>(node->initValue[idx]);
            if (initValue->exprType != node->varType && !(node->varType.dim > 0 && initValue->exprType == typeNull) &&
                !(node->varType.kind == type_t::ty_class && initValue->exprType == typeNull))
                issue->issue(node->pos, "type of init value doesnot match");
        }
    }
}

void TypeChecker::visit(std::shared_ptr<ASTExpr> node) {
    ASTVisitor::visit(node);
}

void TypeChecker::visit(std::shared_ptr<ASTExprNew> node) {
    ASTVisitor::visit(node);
    if (node->exprType.kind == type_t::ty_void)
        issue->issue(node->pos, "type of variable cannot be void");
    else if (node->exprType.kind == type_t::ty_class && !env->classTable.count(node->exprType.name))
        issue->issue(node->pos, "definition of class '" + node->exprType.name + "' doesnot exist");
    for (auto child : node->paras) {
        auto para = std::dynamic_pointer_cast<ASTExpr>(child);
        if (para) {
            if (para->exprType != typeInt)
                issue->issue(node->pos, "requires index of int type for new-statement");
        }
    }
}

void TypeChecker::visit(std::shared_ptr<ASTExprAssign> node) {
    ASTVisitor::visit(node);
    auto operandL = std::dynamic_pointer_cast<ASTExpr>(node->operandL);
    auto operandR = std::dynamic_pointer_cast<ASTExpr>(node->operandR);
    if (operandL->exprType != operandR->exprType && !(operandL->exprType.dim > 0 && operandR->exprType == typeNull) &&
        !(operandL->exprType.kind == type_t::ty_class && operandR->exprType == typeNull))
        issue->issue(node->pos, "Assignment type doesnot match");
    if (operandL->valueType != lvalue)
        issue->issue(node->pos, "requires lvalue for assignment");
    node->exprType = operandR->exprType;
    node->valueType = rvalue;
}

void TypeChecker::visit(std::shared_ptr<ASTExprBinary> node) {
    ASTVisitor::visit(node);
    auto operandL = std::dynamic_pointer_cast<ASTExpr>(node->operandL);
    auto operandR = std::dynamic_pointer_cast<ASTExpr>(node->operandR);
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

void TypeChecker::visit(std::shared_ptr<ASTExprUnary> node) {
    ASTVisitor::visit(node);
    auto operand = std::dynamic_pointer_cast<ASTExpr>(node->operand);
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

void TypeChecker::visit(std::shared_ptr<ASTExprSubscript> node) {
    ASTVisitor::visit(node);
    auto array = std::dynamic_pointer_cast<ASTExpr>(node->array);
    auto subscript = std::dynamic_pointer_cast<ASTExpr>(node->subscript);
    if (array->exprType.dim == 0)
        issue->issue(node->pos, "requires array for subscript");
    if (subscript->exprType != typeInt)
        issue->issue(node->pos, "requires index of int type for subscript");
    node->exprType = array->exprType;
    node->exprType.dim -= 1;
    node->valueType = lvalue;
}

void TypeChecker::visit(std::shared_ptr<ASTExprFuncCall> node) {
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
            }
            else {
                bool flag = true;
                for (int idx = 0; idx < node->paras.size(); idx++) {
                    auto para = std::dynamic_pointer_cast<ASTExpr>(node->paras[idx]);
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

void TypeChecker::visit(std::shared_ptr<ASTExprMemberAccess> node) {
    auto obj = std::dynamic_pointer_cast<ASTExpr>(node->object);
    visit(obj);
    if (!obj->exprType.isClass() && !(obj->exprType.name == "string") && obj->exprType.dim == 0)
        issue->issue(node->pos, "requires a object for member access");
    else {
        if (node->memberFunc) {
            auto func = std::dynamic_pointer_cast<ASTExprFuncCall>(node->memberFunc);
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
                        auto para = std::dynamic_pointer_cast<ASTExpr>(func->paras[idx]);
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

void TypeChecker::visit(std::shared_ptr<ASTExprVar> node) {
    if (node->isThis) {
        if (inClass == 0)
            issue->issue(node->pos, "'this' not in class");
        node->valueType = rvalue;
        node->exprType = type_t(type_t::ty_class, className, 0);
    }
    else {
        if (!Builtin::checkVarName(node->name))
            issue->issue(node->pos, "expected unqualified-id");
        else if (!env->varTable.count(node->name))
            issue->issue(node->pos, "undefined variable '" + node->name + "'");
        else
            node->exprType = env->varTable.find(node->name).varType;
        node->id = env->varTable.getOrder(node->name);
        node->valueType = lvalue;
    }
}

void TypeChecker::visit(std::shared_ptr<ASTExprLiteral> node) {}


