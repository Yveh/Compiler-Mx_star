#include "ASTBuilder.h"

antlrcpp::Any ASTBuilder::visitProg(Mx_starParser::ProgContext *ctx) {
    auto node = std::make_shared<ASTRoot>();
    node->pos = 1;
    for (auto child : ctx->classdeclaration()) {
        visit(child);
        node->classList.push_back(_node);
    }
    for (auto child : ctx->vardeclaration()) {
        visit(child);
        node->varList.push_back(_node);
    }
    for (auto child : ctx->functiondeclaration()) {
        visit(child);
        node->funcList.push_back(_node);
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitClassdeclaration(Mx_starParser::ClassdeclarationContext *ctx) {
    auto node = std::make_shared<ASTClassDecl>();
    node->name = ctx->Identifier()->toString();
    for (auto child : ctx->vardeclaration()) {
        visit(child);
        node->varList.push_back(_node);
    }
    for (auto child : ctx->functiondeclaration()) {
        visit(child);
        node->funcList.push_back(_node);
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitFunctiondeclaration(Mx_starParser::FunctiondeclarationContext *ctx) {
    auto node = std::make_shared<ASTFuncDecl>();
    node->name = ctx->Identifier()->toString();
    for (auto child : ctx->parameter()) {
        visit(child);
        node->paras.push_back(_node);
    }
    if (ctx->typespecifier()) {
        visit(ctx->typespecifier());
        node->retType = _type;
    }
    else
        node->retType = typeNull;
    visit(ctx->block());
    node->stmts = std::move(std::dynamic_pointer_cast<ASTBlock>(_node)->stmts);
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitParameter(Mx_starParser::ParameterContext *ctx) {
    auto node = std::make_shared<ASTVarDecl>();
    visit(ctx->typespecifier());
    node->varType = _type;
    node->name = ctx->Identifier()->toString();
    node->initValue = nullptr;
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitStatement(Mx_starParser::StatementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitBlock(Mx_starParser::BlockContext *ctx) {
    auto node = std::make_shared<ASTBlock>();
    for (auto child : ctx->statement()) {
        visit(child);
        node->stmts.push_back(_node);
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitVardeclaration(Mx_starParser::VardeclarationContext *ctx) {
    auto node = std::make_shared<ASTVarDecl>();
    visit(ctx->typespecifier());
    node->varType = _type;
    node->name = ctx->Identifier()->toString();
    if (ctx->expression()) {
        visit(ctx->expression());
        node->initValue = _node;
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitIfstatement(Mx_starParser::IfstatementContext *ctx) {
    auto node = std::make_shared<ASTStmtIf>();
    visit(ctx->expression());
    node->cond = _node;
    visit(ctx->statement().front());
    node->thenStmt = _node;
    if (ctx->statement().size() > 1) {
        visit(ctx->statement().back());
        node->elseStmt = _node;
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitIterationstatement(Mx_starParser::IterationstatementContext *ctx) {
    if (ctx->While()) {
        auto node = std::make_shared<ASTStmtWhile>();
        visit(ctx->expression());
        node->cond = _node;
        visit(ctx->statement());
        node->stmt = _node;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else {
        auto node = std::make_shared<ASTStmtFor>();
        if (ctx->forinit()) {
            visit(ctx->forinit());
            node->init = _node;
        }
        else
            node->init = nullptr;
        if (ctx->forcond()) {
            visit(ctx->forcond());
            node->cond = _node;
        }
        else
            node->cond = nullptr;
        if (ctx->forincr()) {
            visit(ctx->forincr());
            node->incr = _node;
        }
        else
            node->incr = nullptr;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitForinit(Mx_starParser::ForinitContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitForcond(Mx_starParser::ForcondContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitForincr(Mx_starParser::ForincrContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitJumpstatement(Mx_starParser::JumpstatementContext *ctx) {
    if (ctx->Break()) {
        auto node = std::make_shared<ASTStmtBreak>();
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->Continue()) {
        auto node = std::make_shared<ASTStmtContinue>();
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else {
        auto node = std::make_shared<ASTStmtReturn>();
        if (ctx->expression())
            node->retValue = _node;
        else
            node->retValue = nullptr;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitExpressionstatement(Mx_starParser::ExpressionstatementContext *ctx) {
    auto node = std::make_shared<ASTStmtExpr>();
    visit(ctx->expression());
    node->expr = _node;
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitEmptystatement(Mx_starParser::EmptystatementContext *ctx) {
    return visitChildren(ctx);
}

antlrcpp::Any ASTBuilder::visitExpression(Mx_starParser::ExpressionContext *ctx) {
    if (ctx->Assign()) {
        auto node = std::make_shared<ASTExprAssign>();
        visit(ctx->logicalorexpression());
        node->operandL = _node;
        visit(ctx->expression());
        node->operandR = _node;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->logicalorexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLogicalorexpression(Mx_starParser::LogicalorexpressionContext *ctx) {
    if (ctx->Logic_or()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->logicalorexpression());
        node->operandL = _node;
        visit(ctx->logicalandexpression());
        node->operandR = _node;
        node->op = ASTExprBinary::logic_or;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->logicalandexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLogicalandexpression(Mx_starParser::LogicalandexpressionContext *ctx) {
    if (ctx->Logic_and()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->logicalandexpression());
        node->operandL = _node;
        visit(ctx->orexpression());
        node->operandR = _node;
        node->op = ASTExprBinary::logic_and;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->orexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitOrexpression(Mx_starParser::OrexpressionContext *ctx) {
    if (ctx->Bitwise_or()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->orexpression());
        node->operandL = _node;
        visit(ctx->xorexpression());
        node->operandR = _node;
        node->op = ASTExprBinary::bitwise_or;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->xorexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitXorexpression(Mx_starParser::XorexpressionContext *ctx) {
    if (ctx->Bitwise_xor()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->xorexpression());
        node->operandL = _node;
        visit(ctx->andexpression());
        node->operandR = _node;
        node->op = ASTExprBinary::bitwise_xor;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->andexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAndexpression(Mx_starParser::AndexpressionContext *ctx) {
    if (ctx->Bitwise_and()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->andexpression());
        node->operandL = _node;
        visit(ctx->equalityexpression());
        node->operandR = _node;
        node->op = ASTExprBinary::bitwise_and;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->equalityexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitEqualityexpression(Mx_starParser::EqualityexpressionContext *ctx) {
    if (ctx->Equal() || ctx->NotEqual()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->equalityexpression());
        node->operandL = _node;
        visit(ctx->relationalexpression());
        node->operandR = _node;
        if (ctx->Equal())
            node->op = ASTExprBinary::equal;
        else
            node->op = ASTExprBinary::not_equal;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->relationalexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitRelationalexpression(Mx_starParser::RelationalexpressionContext *ctx) {
    if (ctx->Less() || ctx->Lesseq() || ctx->Greater() || ctx->Greatereq()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->relationalexpression());
        node->operandL = _node;
        visit(ctx->shiftexpression());
        node->operandR = _node;
        if (ctx->Less())
            node->op = ASTExprBinary::less;
        else if (ctx->Lesseq())
            node->op = ASTExprBinary::lesseq;
        else if (ctx->Greater())
            node->op = ASTExprBinary::greater;
        else
            node->op = ASTExprBinary::greatereq;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->shiftexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitShiftexpression(Mx_starParser::ShiftexpressionContext *ctx) {
    if (ctx->Leftshift() || ctx->Rightshift()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->shiftexpression());
        node->operandL = _node;
        visit(ctx->additiveexpression());
        node->operandR = _node;
        if (ctx->Leftshift())
            node->op = ASTExprBinary::leftshift;
        else
            node->op = ASTExprBinary::rightshift;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->additiveexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitAdditiveexpression(Mx_starParser::AdditiveexpressionContext *ctx) {
    if (ctx->Plus() || ctx->Minus()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->additiveexpression());
        node->operandL = _node;
        visit(ctx->multiplicativeexpression());
        node->operandR = _node;
        if (ctx->Plus())
            node->op = ASTExprBinary::plus;
        else
            node->op = ASTExprBinary::minus;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->multiplicativeexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitMultiplicativeexpression(Mx_starParser::MultiplicativeexpressionContext *ctx) {
    if (ctx->Mul() || ctx->Div() || ctx->Mod()) {
        auto node = std::make_shared<ASTExprBinary>();
        visit(ctx->multiplicativeexpression());
        node->operandL = _node;
        visit(ctx->unaryexpression());
        node->operandR = _node;
        if (ctx->Mul())
            node->op = ASTExprBinary::mul;
        else if (ctx->Div())
            node->op = ASTExprBinary::div;
        else
            node->op = ASTExprBinary::mod;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else
        visit(ctx->unaryexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitUnaryexpression(Mx_starParser::UnaryexpressionContext *ctx) {
    if (ctx->Inc() || ctx->Dec() || ctx->Bitwise_not() || ctx->Logic_not() || ctx->Plus() || ctx->Minus()) {
        auto node = std::make_shared<ASTExprUnary>();
        visit(ctx->unaryexpression());
        node->operand = _node;
        if (ctx->Inc())
            node->op = ASTExprUnary::inc_prefix;
        else if (ctx->Dec())
            node->op = ASTExprUnary::dec_prefix;
        else if (ctx->Bitwise_not())
            node->op = ASTExprUnary::bitwise_not;
        else if (ctx->Logic_not())
            node->op = ASTExprUnary::logic_not;
        else if (ctx->Plus())
            node->op = ASTExprUnary::positive;
        else
            node->op = ASTExprUnary::negative;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->postfixexpression())
        visit(ctx->postfixexpression());
    else
        visit(ctx->newexpression());
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitNewexpression(Mx_starParser::NewexpressionContext *ctx) {
    auto node = std::make_shared<ASTExprNew>();
    visit(ctx->simpletypespecifier());
    node->exprType = type_t(_type.kind, _type.name, ctx->Openbra().size());
    for (auto child : ctx->expression()) {
        visit(child);
        node->paras.push_back(_node);
    }
    if (ctx->Openbra().size()) {
        for (int i = ctx->expression().size(); i < ctx->Openbra().size(); ++i)
            node->paras.push_back(nullptr);
        node->isArray = 1;
    }
    else {
        node->isArray = 0;
        node->name = _type.name;
    }
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPostfixexpression(Mx_starParser::PostfixexpressionContext *ctx) {
    if (ctx->Inc() || ctx->Dec()) {
        auto node = std::make_shared<ASTExprUnary>();
        visit(ctx->postfixexpression());
        node->operand = _node;
        if (ctx->Inc())
            node->op = ASTExprUnary::inc_postfix;
        else
            node->op = ASTExprUnary::dec_postfix;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->Openbra()) {
        auto node = std::make_shared<ASTExprSubscript>();
        visit(ctx->postfixexpression());
        node->array = _node;
        visit(ctx->expression().front());
        node->subscript = _node;
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->Openpar()) {
        auto node = std::make_shared<ASTExprFuncCall>();
        visit(ctx->postfixexpression());
        node->func = _node;
        for (auto child : ctx->expression()) {
            visit(child);
            node->paras.push_back(_node);
        }
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->Dot()) {
        auto node = std::make_shared<ASTExprMemberAccess>();
        visit(ctx->postfixexpression());
        node->object = _node;
        node->member = ctx->Identifier()->toString();
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else {
        visit(ctx->primaryexpression());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitPrimaryexpression(Mx_starParser::PrimaryexpressionContext *ctx) {
    if (ctx->This() || ctx->Identifier()) {
        auto node = std::make_shared<ASTExprVar>();
        if (ctx->This()) {
            node->isThis = true;
            node->name = "";
        }
        else {
            node->isThis = false;
            node->name = ctx->Identifier()->toString();
        }
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    else if (ctx->expression()) {
        visit(ctx->expression());
    }
    else if (ctx->literal()) {
        visit(ctx->literal());
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitTypespecifier(Mx_starParser::TypespecifierContext *ctx) {
    visit(ctx->simpletypespecifier());
    _type.dim = ctx->Openbra().size();
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitSimpletypespecifier(Mx_starParser::SimpletypespecifierContext *ctx) {
    if (ctx->Bool())
        _type = typeBool;
    else if (ctx->Int())
        _type = typeInt;
    else if (ctx->Void())
        _type = typeVoid;
    else if (ctx->String())
        _type = typeString;
    else {
        _type = type_t(type_t::ty_class, ctx->Identifier()->toString(), 0);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitLiteral(Mx_starParser::LiteralContext *ctx) {
    if (ctx->booleanliteral())
        visit(ctx->booleanliteral());
    else {
        auto node = std::make_shared<ASTExprLiteral>();
        if (ctx->Integerliteral()) {
            node->ivalue = atoi(ctx->Integerliteral()->toString().c_str());
            node->exprType = typeInt;
        }
        else if (ctx->Stringliteral()) {
            node->svalue = ctx->Stringliteral()->toString();
            node->exprType = typeString;
        }
        else {
            node->exprType = typeNull;
        }
        _node = std::dynamic_pointer_cast<ASTNode>(node);
    }
    return nullptr;
}

antlrcpp::Any ASTBuilder::visitBooleanliteral(Mx_starParser::BooleanliteralContext *ctx) {
    auto node = std::make_shared<ASTExprLiteral>();
    node->exprType = typeBool;
    node->bvalue = ctx->True() != nullptr;
    _node = std::dynamic_pointer_cast<ASTNode>(node);
    return nullptr;
}

std::shared_ptr<ASTRoot> ASTBuilder::build(antlr4::tree::ParseTree *tree) {
    visit(tree);
    return std::dynamic_pointer_cast<ASTRoot>(_node);
}



