#include "IRProgram.h"

void IRProgram::outputIR(std::ostream &ofs) {
    for (auto obj : object) {
        ofs << "%" << obj->name << " [";
        bool first = true;
        for (auto member : obj->member) {
            if (!first)
                ofs << ", ";
            ofs << member.to_string();
            first = false;
        }
        ofs << "]" << std::endl;
    }
    for (auto operand : globalVar) {
        ofs << operand.to_string() << " " << operand.get_id() << std::endl;
    }
    for (int i = 0; i < constString.size(); ++i) {
        ofs << "str." << i << " = \"" << constString[i] << "\"" << std::endl;
    }
    for (auto function : func) {
        if (function->isBuiltin)
            continue;
        ofs << "def @" << function->name << "(";
        bool first = true;
        for (auto para : function->paras) {
            if (!first)
                ofs << ", ";
            ofs << para.to_string() << " " << para.get_id();
            first = false;
        }
        ofs << ") {" << std::endl;
        for (auto blk : function->blocks)
            outputBlock(blk, ofs);
        ofs << "}" << std::endl;
    }
}

std::shared_ptr<IRFunction> IRProgram::getFunc(std::string name) {
    return func[ref_func[name]];
}

bool IRProgram::hasFunc(std::string name) {
    return ref_func.count(name);
}

std::shared_ptr<IRClass> IRProgram::getClass(std::string name) {
    return object[ref_class[name]];
}

void IRProgram::outputBlock(std::shared_ptr<IRBlock> blk, std::ostream &ofs) {
    ofs << "LAB " << blk->label << ":" << std::endl;
    for (auto inst : blk->insts) {
        ofs << "\t" << inst->to_string() << ";" << std::endl;
    }
}

bool IRProgram::hasVar(int x) {
    return ref_var.count(x);
}

IROperand IRProgram::getVar(int x) {
    return ref_var[x];
}

void IRProgram::getAllBlocks() {
    for (auto function : func) {
        if (function->isBuiltin)
            continue;
        function->vis.clear();
        function->getAllBlocks(function->inBlock);
    }
}
