#include "TypeChecker.h"

void TypeChecker::createEnv(std::shared_ptr<ASTRoot> node, SematicIssue *issue) {
    for (auto fchild : node->funcList) {
        auto func = std::dynamic_pointer_cast<ASTFuncDecl>(fchild);
        if (!Builtin::checkVarName(func->name))
            issue->issue(func->pos, "expected unqualified-id");
        funcInfo finfo;
        finfo.funcType = type_t(type_t::ty_class, func->name, 0);
        finfo.retType = func->retType;
        if (finfo.retType == typeNull)
            issue->issue(func->pos, "requires a type specifier for function");
        for (auto pchild : func->paras) {
            auto para = std::dynamic_pointer_cast<ASTVarDecl>(pchild);
            if (!Builtin::checkVarName(para->name))
                issue->issue(para->pos, "expected unqualified-id");
            varInfo vinfo;
            vinfo.varType = para->varType;
            if (!finfo.paras.insert(para->name, vinfo))
                issue->issue(para->pos, "redefinition of parameter '" + para->name + "'");
            finfo.parasType.push_back(para->varType);
            finfo.parasName.push_back(para->name);
        }
        if (!env->funcTable.insert(func->name, finfo))
            issue->issue(func->pos, "redefinition of function '" + func->name + "'");
    }
    for (auto cchild : node->classList) {
        auto obj = std::dynamic_pointer_cast<ASTClassDecl>(cchild);
        if (!Builtin::checkVarName(obj->name))
            issue->issue(obj->pos, "expected unqualified-id");
        classInfo cinfo;
        cinfo.classType = type_t(type_t::ty_class, obj->name, 0);
        for (auto fchild : obj->funcList) {
            auto func = std::dynamic_pointer_cast<ASTFuncDecl>(fchild);
            if (!Builtin::checkVarName(func->name))
                issue->issue(func->pos, "expected unqualified-id");
            funcInfo finfo;
            finfo.funcType = type_t(type_t::ty_class, func->name, 0);
            finfo.retType = func->retType;
            if (finfo.retType == typeNull && func->name != obj->name)
                issue->issue(func->pos, "requires a type specifier for function");
            if (finfo.retType != typeNull && func->name == obj->name)
                issue->issue(func->pos, "constructor cannot have a return type");
            for (auto vchild : func->paras) {
                auto para = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
                if (!Builtin::checkVarName(para->name))
                    issue->issue(para->pos, "expected unqualified-id");
                varInfo vinfo;
                vinfo.varType = para->varType;
                if (!finfo.paras.insert(para->name, vinfo))
                    issue->issue(para->pos, "redefinition of parameter '" + para->name + "'");
                finfo.parasType.push_back(para->varType);
                finfo.parasName.push_back(para->name);
            }
            if (!cinfo.memberFunc.insert(func->name, finfo))
                issue->issue(func->pos, "redefinition of member function '" + func->name + "'");
        }
        for (auto vchild : obj->varList) {
            auto var = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
            if (!Builtin::checkVarName(var->name))
                issue->issue(var->pos, "expected unqualified-id");
            varInfo vinfo;
            vinfo.varType = var->varType;
            if (cinfo.memberFunc.count(var->name))
                issue->issue(var->pos, "redefinition of '" + var->name + "' as different kind of symbol");
            if (!cinfo.memberVar.insert(var->name, vinfo))
                issue->issue(var->pos, "redefinition of '" + var->name + "'");
        }
        if (env->funcTable.count(obj->name))
            issue->issue(obj->pos, "redefinition of '" + obj->name + "' as different kind of symbol");
        else if (!env->classTable.insert(obj->name, cinfo))
            issue->issue(obj->pos, "redefinition of '" + obj->name + "'");
    }
    if (env->funcTable.count("main") == 0)
        issue->issue(0, "no main function");
}
