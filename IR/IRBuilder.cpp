#include "IRBuilder.h"
#include "IR.h"
#include "Env.h"

IROperand::type_t IRBuilder::RegFromMx(type_t type) {
    if (type.kind == type_t::ty_void)
        return IROperand::Void;
    else if (type.kind == type_t::ty_bool)
        return IROperand::Reg8;
    else if (type.kind == type_t::ty_int)
        return IROperand::Reg32;
    else if (type.kind == type_t::ty_class)
        return IROperand::Reg32;
    else
        return IROperand::Void;
}

IROperand::type_t IRBuilder::ImmFromMx(type_t type) {
    if (type.kind == type_t::ty_void)
        return IROperand::Void;
    else if (type.kind == type_t::ty_bool)
        return IROperand::Imm8;
    else if (type.kind == type_t::ty_int)
        return IROperand::Imm32;
    else if (type.kind == type_t::ty_class)
        return IROperand::Imm32;
    else
        return IROperand::Void;
}

IROperand IRBuilder::loadOperand(IROperand x) {
    if (x.pointer) {
        IROperand ret;
        if (x.size() == 4)
            ret = IROperandReg32(prog->newLabel());
        else
            ret = IROperandReg8(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRLoad>(ret, x));
        return ret;
    }
    else {
        return x;
    }
}

void IRBuilder::createIR(std::shared_ptr<ASTRoot> node) {
    prog->object.push_back(std::make_shared<IRClass>("string"));
    prog->ref_class["string"] = prog->object.size() - 1;

    prog->object.push_back(std::make_shared<IRClass>(""));
    prog->ref_class[""] = prog->object.size() - 1;

    auto func = std::make_shared<IRFunction>("malloc");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("getInt");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("toString");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("print");
    func->isBuiltin = true;
    func->retType = IROPerandVoid();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("println");
    func->isBuiltin = true;
    func->retType = IROPerandVoid();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("printInt");
    func->isBuiltin = true;
    func->retType = IROPerandVoid();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("printlnInt");
    func->isBuiltin = true;
    func->retType = IROPerandVoid();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("getString");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_length");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_substring");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_parseInt");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_ord");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_strcat");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_equal");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_less");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    func = std::make_shared<IRFunction>("string_greater");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;

    //TODO: read the first i32 before array pointer
    func = std::make_shared<IRFunction>("_size");
    func->isBuiltin = true;
    func->retType = IROperandReg32();
    func->paras.push_back(IROperandReg32());
    prog->func.push_back(func);
    prog->ref_func[func->name] = prog->func.size() - 1;
    visit(node);
}

void IRBuilder::visit(std::shared_ptr<ASTNode> node) {
    ASTVisitor::visit(node);
}

void IRBuilder::visit(std::shared_ptr<ASTRoot> node) {
    for (auto child : node->funcList) {
        auto func = std::dynamic_pointer_cast<ASTFuncDecl>(child);
        prog->func.push_back(std::make_shared<IRFunction>(func->name));
        prog->func.back()->retType = IROperand(RegFromMx(func->retType));
        prog->func.back()->inBlock = std::make_shared<IRBlock>(prog->newLabel());
        prog->func.back()->outBlock = std::make_shared<IRBlock>(prog->newLabel());
        for (auto pchild : func->paras) {
            auto para = std::dynamic_pointer_cast<ASTVarDecl>(pchild);
            IROperand tmp(RegFromMx(para->varType), prog->newLabel());
            prog->func.back()->paras.push_back(tmp);
            IROperand tmp2(RegFromMx(para->varType), prog->newLabel(), 1);
            prog->func.back()->inBlock->insts.push_back(std::make_shared<IRAlloca>(tmp2));
            prog->func.back()->inBlock->insts.push_back(std::make_shared<IRStore>(tmp2, tmp));
            prog->ref_var[para->id[0]] = tmp2;
        }
        prog->ref_func[func->name] = prog->func.size() - 1;
    }

    for (auto child : node->classList) {
        auto obj = std::dynamic_pointer_cast<ASTClassDecl>(child);
        prog->object.push_back(std::make_shared<IRClass>(obj->name));
        for (auto vchild : obj->varList) {
            auto var = std::dynamic_pointer_cast<ASTVarDecl>(vchild);
            prog->object.back()->ref[var->name[0]] = prog->object.back()->member.size();
            prog->object.back()->member.emplace_back(RegFromMx(var->varType));
            prog->object.back()->offset.push_back(prog->object.back()->size);
            prog->object.back()->size += prog->object.back()->member.back().size();
        }
        prog->ref_class[obj->name] = prog->object.size() - 1;
        for (auto fchild : obj->funcList) {
            auto func = std::dynamic_pointer_cast<ASTFuncDecl>(fchild);
            prog->func.push_back(std::make_shared<IRFunction>(obj->name + "_" + func->name));
            prog->func.back()->retType = IROperand(RegFromMx(func->retType));
            prog->func.back()->inBlock = std::make_shared<IRBlock>(prog->newLabel());
            prog->func.back()->outBlock = std::make_shared<IRBlock>(prog->newLabel());
            IROperand tmp = IROperandReg32(prog->newLabel());
            prog->func.back()->paras.push_back(tmp);
            for (auto pchild : func->paras) {
                auto para = std::dynamic_pointer_cast<ASTVarDecl>(pchild);
                IROperand tmp(RegFromMx(para->varType), prog->newLabel());
                prog->func.back()->paras.push_back(tmp);
                IROperand tmp2(RegFromMx(para->varType), prog->newLabel(), 1);
                prog->func.back()->inBlock->insts.push_back(std::make_shared<IRAlloca>(tmp2));
                prog->func.back()->inBlock->insts.push_back(std::make_shared<IRStore>(tmp2, tmp));
                prog->ref_var[para->id[0]] = tmp2;
            }
            prog->ref_func[obj->name + "_" + func->name] = prog->func.size() - 1;
        }
    }

    auto mainFunc = prog->getFunc("main");
    _block = mainFunc->inBlock;
    for (auto child : node->varList) {
        auto var = std::dynamic_pointer_cast<ASTVarDecl>(child);
        for (int idx = 0; idx < var->id.size(); ++idx) {
            IROperand tmp = IROperandReg32(prog->newLabel(), 1);
            prog->globalVar.push_back(tmp);
            if (var->initValue[idx]) {
                visit(std::dynamic_pointer_cast<ASTExpr>(var->initValue[idx]));
                _block->insts.push_back(std::make_shared<IRStore>(tmp, loadOperand(_opr)));
            }
            prog->ref_var[var->id[idx]] = tmp;
        }

    }
    for (auto child : node->funcList)
        if (std::dynamic_pointer_cast<ASTFuncDecl>(child)->name == "main") {
            visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
        }
    for (auto child : node->funcList)
        if (std::dynamic_pointer_cast<ASTFuncDecl>(child)->name != "main") {
            visit(std::dynamic_pointer_cast<ASTFuncDecl>(child));
        }
    for (auto child : node->classList) {
        auto obj = std::dynamic_pointer_cast<ASTClassDecl>(child);
        _inClass = true;
        _objPointer = prog->getClass(obj->name);
        for (auto fchild : obj->funcList) {
            visit(std::dynamic_pointer_cast<ASTFuncDecl>(fchild));
        }
        _inClass = false;
    }
}


void IRBuilder::visit(std::shared_ptr<ASTStmt> node) {
    if (hasReturn || hasContinue || hasBreak)
        return;
    ASTVisitor::visit(node);
}

void IRBuilder::visit(std::shared_ptr<ASTStmtBreak> node) {
    _block->insts.push_back(std::make_shared<IRJump>(breakTo.top()));
    hasBreak = true;
}

void IRBuilder::visit(std::shared_ptr<ASTStmtContinue> node) {
    _block->insts.push_back(std::make_shared<IRJump>(continueTo.top()));
    hasContinue = true;
}

void IRBuilder::visit(std::shared_ptr<ASTStmtReturn> node) {
    if (node->retValue) {
        visit(std::dynamic_pointer_cast<ASTExpr>(node->retValue));
        _opr = loadOperand(_opr);
        retValues.push_back(_opr);
    }
    else {
        _block->insts.push_back(std::make_shared<IRReturn>());
    }
    retBlocks.push_back(_block);
    hasReturn = true;
}

void IRBuilder::visit(std::shared_ptr<ASTStmtFor> node) {
    auto _cond = std::make_shared<IRBlock>(prog->newLabel());
    auto _body = std::make_shared<IRBlock>(prog->newLabel());
    auto _incr = std::make_shared<IRBlock>(prog->newLabel());
    auto _next = std::make_shared<IRBlock>(prog->newLabel());
    if (node->init) {
        visit(std::dynamic_pointer_cast<ASTExpr>(node->init));
    }
    _block->insts.push_back(std::make_shared<IRJump>(_cond));
    _block = _cond;
    if (node->cond) {
        visit(std::dynamic_pointer_cast<ASTExpr>(node->cond));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _body, _next));
    }
    else {
        _block->insts.push_back(std::make_shared<IRJump>(_body));
    }
    continueTo.push(_incr);
    breakTo.push(_next);
    _block = _body;
    if (node->stmt) {
        visit(std::dynamic_pointer_cast<ASTStmt>(node->stmt));
    }
    if (!hasReturn && !hasContinue && !hasBreak)
        _block->insts.push_back(std::make_shared<IRJump>(_incr));
    _block = _incr;
    if (node->incr) {
        visit(std::dynamic_pointer_cast<ASTExpr>(node->incr));
    }
    _block->insts.push_back(std::make_shared<IRJump>(_cond));
    continueTo.pop();
    breakTo.pop();
    hasBreak = hasContinue = hasReturn = false;
    _block = _next;
}

void IRBuilder::visit(std::shared_ptr<ASTStmtWhile> node) {
    auto _cond = std::make_shared<IRBlock>(prog->newLabel());
    auto _body = std::make_shared<IRBlock>(prog->newLabel());
    auto _next = std::make_shared<IRBlock>(prog->newLabel());
    continueTo.push(_cond);
    breakTo.push(_next);
    _block->insts.push_back(std::make_shared<IRJump>(_cond));
    _block = _cond;
    visit(std::dynamic_pointer_cast<ASTExpr>(node->cond));
    _opr = loadOperand(_opr);
    _block->insts.emplace_back(std::make_shared<IRBr>(_opr, _body, _next));
    _block = _body;
    if (node->stmt) {
        visit(std::dynamic_pointer_cast<ASTStmt>(node->stmt));
    }
    if (!hasReturn && !hasContinue && !hasBreak)
        _block->insts.push_back(std::make_shared<IRJump>(_cond));
    continueTo.pop();
    breakTo.pop();
    hasBreak = hasContinue = hasReturn = false;
    _block = _next;
}

void IRBuilder::visit(std::shared_ptr<ASTStmtIf> node) {
    auto _cond = std::make_shared<IRBlock>(prog->newLabel());
    auto _next = std::make_shared<IRBlock>(prog->newLabel());

    _block->insts.push_back(std::make_shared<IRJump>(_cond));
    _block = _cond;

    if (node->elseStmt) {
        auto _true = std::make_shared<IRBlock>(prog->newLabel());
        auto _false = std::make_shared<IRBlock>(prog->newLabel());
        visit(std::dynamic_pointer_cast<ASTExpr>(node->cond));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _true, _false));
        _block = _true;
        visit(std::dynamic_pointer_cast<ASTStmt>(node->thenStmt));
        if (!hasReturn && !hasContinue && !hasBreak) {
            _block->insts.push_back(std::make_shared<IRJump>(_next));
        }
        bool tmpReturn = hasReturn;
        bool tmpBreak = hasBreak;
        bool tmpContinue = hasContinue;

        _block = _false;
        hasReturn = hasBreak = hasContinue = false;
        visit(std::dynamic_pointer_cast<ASTStmt>(node->elseStmt));
        if (!hasReturn && !hasContinue && !hasBreak) {
            _block->insts.push_back(std::make_shared<IRJump>(_next));
        }
        hasReturn = tmpReturn && hasReturn;
        hasContinue = tmpContinue && hasContinue;
        hasBreak = tmpBreak && hasBreak;
        _block = _next;
    }
    else {
        auto _true = std::make_shared<IRBlock>(prog->newLabel());
        visit(std::dynamic_pointer_cast<ASTExpr>(node->cond));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _true, _next));
        _block = _true;
        visit(std::dynamic_pointer_cast<ASTStmt>(node->thenStmt));
        if (!hasReturn && !hasContinue && !hasBreak) {
            _block->insts.push_back(std::make_shared<IRJump>(_next));
        }
        hasReturn = hasContinue = hasBreak = false;
        _block = _next;
    }
}

void IRBuilder::visit(std::shared_ptr<ASTStmtExpr> node) {
    ASTVisitor::visit(node);
}

void IRBuilder::visit(std::shared_ptr<ASTBlock> node) {
    ASTVisitor::visit(node);
}

void IRBuilder::visit(std::shared_ptr<ASTFuncDecl> node) {
    std::shared_ptr<IRFunction> func;
    if (_inClass) {
        func = prog->getFunc(_objPointer->name + "_" + node->name);
        _obj = func->paras[0];
    }
    else
        func = prog->getFunc(node->name);
    if (node->name != "main")
        _block = func->inBlock;
    hasReturn = hasBreak = hasContinue = false;
    retValues.clear();
    retBlocks.clear();
    for (auto child : node->stmts)
        visit(std::dynamic_pointer_cast<ASTStmt>(child));
    if (!hasReturn) {
        retBlocks.push_back(_block);
        retValues.push_back(IROperand(ImmFromMx(node->retType), 0));
    }
    for (int i = 0; i < retBlocks.size(); ++i)
        retBlocks[i]->insts.push_back(std::make_shared<IRJump>(func->outBlock));
    if (func->retType.is_void()) {
        func->outBlock->insts.push_back(std::make_shared<IRReturn>());
    }
    else {
        IROperand tmp(RegFromMx(node->retType), prog->newLabel());
        auto phi = std::make_shared<IRPhi>(tmp);
        phi->blocks = retBlocks;
        phi->values = retValues;
        func->outBlock->insts.push_back(phi);
        func->outBlock->insts.push_back(std::make_shared<IRReturn>(tmp));
    }
}

void IRBuilder::visit(std::shared_ptr<ASTVarDecl> node) {
    for (int idx = 0; idx < node->name.size(); idx++) {
        IROperand dst = IROperand(RegFromMx(node->varType), prog->newLabel(), 1);
        prog->ref_var[node->id[idx]] = dst;
        _block->insts.push_back(std::make_shared<IRAlloca>(dst));
        if (node->initValue[idx]) {
            visit(std::dynamic_pointer_cast<ASTExpr>(node->initValue[idx]));
            _opr = loadOperand(_opr);
            _block->insts.push_back(std::make_shared<IRStore>(dst, _opr));
        }
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExpr> node) {
    ASTVisitor::visit(node);
}


void IRBuilder::createArray(std::shared_ptr<ASTExprNew> node, int deep) {
    if (deep == node->paras.size()) {
        _opr = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRMalloc>(_opr, IROperandImm32(prog->getClass(node->exprType.name)->size)));
        if (prog->hasFunc(node->exprType.name + "_" + node->exprType.name))
            _block->insts.push_back(std::make_shared<IRCall>(prog->getFunc(node->exprType.name + "_" + node->exprType.name), std::vector<IROperand>{}));
    }
    else if (node->paras[deep]) {
        visit(std::dynamic_pointer_cast<ASTExpr>(node->paras[deep]));
        _opr = loadOperand(_opr);
        IROperand size;
        if (deep == node->paras.size() - 1 && node->exprType.size() == 1) {
            size = _opr;
        }
        else {
            size = IROperandReg32(prog->newLabel());
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Mul, size, _opr, IROperandImm32(4)));
        }
        IROperand tmp = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, tmp, size, IROperandImm32(4)));
        IROperand begin0 = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRMalloc>(begin0, tmp));
        _block->insts.push_back(std::make_shared<IRStore>(begin0, _opr));
        IROperand begin = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, begin, begin0, IROperandImm32(4)));

        if (deep + 1 < node->paras.size() && node->paras[deep + 1] == nullptr) {
            _opr = begin;
            return;
        }
        else if (deep + 1 == node->paras.size() && !node->exprType.isClass()) {
            _opr = begin;
            return ;
        }

        IROperand end = IROperandReg32(prog->newLabel(), 1);
        _block->insts.push_back(std::make_shared<IRAlloca>(end));
        tmp = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, tmp, begin0, size));
        _block->insts.push_back(std::make_shared<IRStore>(end, tmp));
        auto _cond = std::make_shared<IRBlock>(prog->newLabel());
        auto _body = std::make_shared<IRBlock>(prog->newLabel());
        auto _next = std::make_shared<IRBlock>(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRJump>(_cond));
        _block = _cond;
        IROperand cond = IROperandReg8(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sle, cond, begin, loadOperand(end)));
        _block->insts.push_back(std::make_shared<IRBr>(cond, _body, _next));
        _block = _body;
        createArray(node, deep + 1);
        if (_opr.type != IROperand::Void) {
            _block->insts.push_back(std::make_shared<IRStore>(loadOperand(end), _opr));
            tmp = IROperandReg32(prog->newLabel());
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sub, tmp, loadOperand(end), IROperandImm32(4)));
            _block->insts.push_back(std::make_shared<IRStore>(end, tmp));
        }
        _block->insts.push_back(std::make_shared<IRJump>(_cond));
        _block = _next;
        _opr = begin;
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExprNew> node) {
    createArray(node, 0);
}

void IRBuilder::visit(std::shared_ptr<ASTExprAssign> node) {
    visit(std::dynamic_pointer_cast<ASTExpr>(node->operandL));
    IROperand tmp = _opr;
    visit(std::dynamic_pointer_cast<ASTExpr>(node->operandR));
    _opr = loadOperand(_opr);
    _block->insts.push_back(std::make_shared<IRStore>(tmp, _opr));
    _opr = tmp;
}

void IRBuilder::visit(std::shared_ptr<ASTExprBinary> node) {
    auto operandL = std::dynamic_pointer_cast<ASTExpr>(node->operandL);
    auto operandR = std::dynamic_pointer_cast<ASTExpr>(node->operandR);

    IROperand dst(RegFromMx(node->exprType), prog->newLabel());

    if (node->op == ASTExprBinary::logic_or) {
        dst.pointer = true;
        _block->insts.push_back(std::make_shared<IRAlloca>(dst));
        auto _true = std::make_shared<IRBlock>(prog->newLabel());
        auto _twice = std::make_shared<IRBlock>(prog->newLabel());
        auto _false = std::make_shared<IRBlock>(prog->newLabel());
        auto _next = std::make_shared<IRBlock>(prog->newLabel());

        visit(std::dynamic_pointer_cast<ASTExpr>(operandL));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _true, _twice));
        _block = _twice;
        visit(std::dynamic_pointer_cast<ASTExpr>(operandR));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _true, _false));

        _true->insts.push_back(std::make_shared<IRStore>(dst, IROperandImm8(1)));
        _true->insts.push_back(std::make_shared<IRJump>(_next));
        _false->insts.push_back(std::make_shared<IRStore>(dst, IROperandImm8(0)));
        _false->insts.push_back(std::make_shared<IRJump>(_next));
        _block = _next;
    }
    else if (node->op == ASTExprBinary::logic_and) {
        dst.pointer = true;
        _block->insts.push_back(std::make_shared<IRAlloca>(dst));
        auto _true = std::make_shared<IRBlock>(prog->newLabel());
        auto _twice = std::make_shared<IRBlock>(prog->newLabel());
        auto _false = std::make_shared<IRBlock>(prog->newLabel());
        auto _next = std::make_shared<IRBlock>(prog->newLabel());

        visit(std::dynamic_pointer_cast<ASTExpr>(operandL));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _twice, _false));
        _block = _twice;
        visit(std::dynamic_pointer_cast<ASTExpr>(operandR));
        _opr = loadOperand(_opr);
        _block->insts.push_back(std::make_shared<IRBr>(_opr, _true, _false));

        _true->insts.push_back(std::make_shared<IRStore>(dst, IROperandImm8(1)));
        _true->insts.push_back(std::make_shared<IRJump>(_next));
        _false->insts.push_back(std::make_shared<IRStore>(dst, IROperandImm8(0)));
        _false->insts.push_back(std::make_shared<IRJump>(_next));
        _block = _next;
    }
    else {
        visit(std::dynamic_pointer_cast<ASTExpr>(operandL));
        IROperand tmp = loadOperand(_opr);
        visit(std::dynamic_pointer_cast<ASTExpr>(operandR));
        _opr = loadOperand(_opr);
        if (node->op == ASTExprBinary::bitwise_or) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Or, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::bitwise_and) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::And, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::bitwise_xor) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Xor, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::equal) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_equal"), std::vector<IROperand>{tmp, _opr}, dst));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Eq, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::not_equal) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                IROperand dstsrc(RegFromMx(node->exprType), prog->newLabel());
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_equal"), std::vector<IROperand>{tmp, _opr}, dstsrc));
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Xor, dst, dstsrc, IROperandImm8(0)));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Ne, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::less) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_less"), std::vector<IROperand>{tmp, _opr}, dst));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Slt, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::lesseq) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                IROperand dstsrc1(RegFromMx(node->exprType), prog->newLabel());
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_equal"), std::vector<IROperand>{tmp, _opr}, dstsrc1));
                IROperand dstsrc2(RegFromMx(node->exprType), prog->newLabel());
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_less"), std::vector<IROperand>{tmp, _opr}, dstsrc2));
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Or, dst, dstsrc1, dstsrc2));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sle, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::greater) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_greater"), std::vector<IROperand>{tmp, _opr}, dst));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sgt, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::greatereq) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                IROperand dstsrc1(RegFromMx(node->exprType), prog->newLabel());
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_equal"), std::vector<IROperand>{tmp, _opr}, dstsrc1));
                IROperand dstsrc2(RegFromMx(node->exprType), prog->newLabel());
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_greater"), std::vector<IROperand>{tmp, _opr}, dstsrc2));
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Or, dst, dstsrc1, dstsrc2));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sge, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::leftshift) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Shl, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::rightshift) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Ashr, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::plus) {
            if (operandL->exprType.name == "string" && operandR->exprType.name == "string") {
                _block->insts.push_back(
                        std::make_shared<IRCall>(prog->getFunc("string_strcat"), std::vector<IROperand>{tmp, _opr}, dst));
            }
            else {
                _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, tmp, _opr));
            }
        }
        else if (node->op == ASTExprBinary::minus) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sub, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::mul) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Mul, dst, tmp, _opr));
        }
        else if (node->op == ASTExprBinary::div) {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sdiv, dst, tmp, _opr));
        }
        else {
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Srem, dst, tmp, _opr));
        }
    }
    _opr = dst;
}

void IRBuilder::visit(std::shared_ptr<ASTExprUnary> node) {
    visit(std::dynamic_pointer_cast<ASTExpr>(node->operand));
    IROperand tmp = loadOperand(_opr), dst = IROperand(RegFromMx(node->exprType), prog->newLabel());
    if (node->op == ASTExprUnary::inc_postfix) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, tmp, IROperandImm32(1)));
        _block->insts.push_back(std::make_shared<IRStore>(_opr, dst));
        _opr = tmp;
    }
    else if (node->op == ASTExprUnary::inc_prefix) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, tmp, IROperandImm32(1)));
        _block->insts.push_back(std::make_shared<IRStore>(_opr, dst));
        _opr = dst;
    }
    else if (node->op == ASTExprUnary::dec_postfix) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sub, dst, tmp, IROperandImm32(1)));
        _block->insts.push_back(std::make_shared<IRStore>(_opr, dst));
        _opr = tmp;
    }
    else if (node->op == ASTExprUnary::dec_prefix) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sub, dst, tmp, IROperandImm32(1)));
        _block->insts.push_back(std::make_shared<IRStore>(_opr, dst));
        _opr = dst;
    }
    else if (node->op == ASTExprUnary::negative) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Sub, dst, IROperandImm32(0), tmp));
        _opr = dst;
    }
    else if (node->op == ASTExprUnary::bitwise_not) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Xor, dst, IROperandImm32(-1), tmp));
        _opr = dst;
    }
    else if (node->op == ASTExprUnary::logic_not) {
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Xor, dst, IROperandImm8(1), tmp));
        _opr = dst;
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExprSubscript> node) {
    visit(std::dynamic_pointer_cast<ASTExpr>(node->array));
    IROperand src1 = loadOperand(_opr);
    visit(std::dynamic_pointer_cast<ASTExpr>(node->subscript));
    _opr = loadOperand(_opr);
    IROperand src2;
    if (node->exprType.dim > 0 || node->exprType.size() == 4) {
        src2 = IROperandReg32(prog->newLabel());
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Mul, src2, _opr, IROperandImm32(4)));
    }
    else {
        src2 = _opr;
    }
    IROperand dst = IROperand(RegFromMx(node->exprType), prog->newLabel(), 1);
    _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, src1, src2));
    _opr = dst;
}

void IRBuilder::visit(std::shared_ptr<ASTExprFuncCall> node) {
    bool flag = false;
    std::shared_ptr<IRFunction> func;
    if (_inClass) {
        if (prog->hasFunc(_objPointer->name + "_" + node->name)) {
            func = prog->getFunc(_objPointer->name + "_" + node->name);
            flag = true;
        }
        else
            func = prog->getFunc(node->name);
    }
    else
        func = prog->getFunc(node->name);

    std::vector<IROperand> paras;
    if (flag)
        paras.push_back(_obj);
    for (auto child : node->paras) {
        visit(std::dynamic_pointer_cast<ASTExpr>(child));
        _opr = loadOperand(_opr);
        paras.push_back(_opr);
    }
    if (func->retType.type == IROperand::Void) {
        _block->insts.push_back(std::make_shared<IRCall>(func, paras));
    }
    else {
        IROperand dst = IROperand(RegFromMx(node->exprType), prog->newLabel(), 0);
        _block->insts.push_back(std::make_shared<IRCall>(func, paras, dst));
        _opr = dst;
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExprMemberAccess> node) {
    auto qwq = std::dynamic_pointer_cast<ASTExpr>(node->object);
    visit(qwq);
    IROperand obj = loadOperand(_opr);
    std::shared_ptr<IRClass> objInfo = prog->getClass(qwq->exprType.name);
    if (node->memberFunc) {
        auto memberFunc = std::dynamic_pointer_cast<ASTExprFuncCall>(node->memberFunc);
        std::vector<IROperand> paras;
        paras.push_back(obj);
        for (auto child : memberFunc->paras) {
            visit(std::dynamic_pointer_cast<ASTExpr>(child));
            _opr = loadOperand(_opr);
            paras.push_back(_opr);
        }
        std::shared_ptr<IRFunction> func;
        if (qwq->exprType.dim > 0)
            func = prog->getFunc("_" + memberFunc->name);
        else
            func = prog->getFunc(objInfo->name + "_" + memberFunc->name);
        if (func->retType.type == IROperand::Void) {
            _block->insts.push_back(std::make_shared<IRCall>(func, paras));
        }
        else {
            IROperand dst = IROperand(RegFromMx(node->exprType), prog->newLabel(), 0);
            _block->insts.push_back(std::make_shared<IRCall>(func, paras, dst));
            _opr = dst;
        }
    }
    else {
        IROperand dst = IROperand(RegFromMx(node->exprType), prog->newLabel(), 1);
        _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, obj, IROperandImm32(objInfo->getOffset(node->memberVar))));
        _opr = dst;
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExprVar> node) {
    if (node->isThis) {
        _opr = _obj;
    }
    else {
        if (prog->hasVar(node->id)) {
            _opr = prog->getVar(node->id);
        }
        else {
            int tmp = _objPointer->getOffset(node->name);
            IROperand dst = IROperand(RegFromMx(node->exprType), prog->newLabel(), 1);
            _block->insts.push_back(std::make_shared<IRBinary>(IRBinary::Add, dst, _obj, IROperandImm32(tmp)));
            _opr = dst;
        }
    }
}

void IRBuilder::visit(std::shared_ptr<ASTExprLiteral> node) {
    if (node->exprType == typeInt) {
        _opr = IROperandImm32(node->ivalue);
    }
    else if (node->exprType == typeBool) {
        _opr = IROperandImm8(node->bvalue);
    }
    else if (node->exprType.name == "string"){
        prog->constString.push_back(node->svalue);
        _opr = IROperandConst(prog->constString.size() - 1);
    }
    else {
        _opr = IROperandImm32(0);
    }
}

IRBuilder::IRBuilder(std::shared_ptr<IRProgram> _prog) : prog(_prog) {
    hasReturn = hasContinue = hasBreak = false;
    _inClass = false;
}
