#include "RVProgram.h"

bool RVProgram::hasVar(int _id) {
    return ref_reg.count(_id);
}

RVReg RVProgram::getVar(int _id) {
    return ref_reg[_id];
}

bool RVProgram::checkGlobal(int _id) {
    return ref_global.count(_id);
}

RVReg RVProgram::getGlobal(int _id) {
    return ref_global[_id];
}

void RVProgram::outputIR(std::ostream &ofs) {
    ofs << "\t.text" << std::endl;
    for (auto func : functions) {
        ofs << "\t.globl\t" << func->name << std::endl;
        ofs << "\t.p2align\t1" << std::endl;
        ofs << "\t.type\t" << func->name << ",@function" << std::endl;
        ofs << func->name << ":" << std::endl;
        for (auto blk : func->blocks)
            outputBlock(blk, ofs);
        ofs << std::endl;
    }
    for (auto var : ref_global) {
        ofs << "\t.type\t" << var.second.to_string() << ",@object" << std::endl;
        ofs << "\t.section\t.data" << std::endl;
        ofs << "\t.globl\t" << var.second.to_string() << std::endl;
        ofs << "\t.p2align\t2" << std::endl;
        ofs << var.second.to_string() <<  ":" << std::endl;
        ofs << "\t.zero\t" << var.second.size << std::endl;
        ofs << "\t.size\t" << var.second.to_string() << ", " << var.second.size << std::endl << std::endl;
    }
    for (int i = 0; i < constString.size(); ++i) {
        ofs << "\t.type\t" << ".str." << i << " ,@object" << std::endl;
        ofs << "\t.section\t.rodata" << std::endl;
        ofs << ".str." << i << ":" << std::endl;
        ofs << "\t.asciz\t\"" << StringTrans(constString[i]) + "\"" << std::endl;
        ofs << "\t.size\t" << ".str." << i << ", " << constString.size() + 1 << std::endl << std::endl;
    }
}

void RVProgram::outputBlock(std::shared_ptr<RVBlock> blk, std::ostream &ofs) {
    ofs << "." << blk->funcName << "_.bb" << blk->label << ":" << std::endl;
    for (auto inst : blk->insts)
        ofs << "\t" << inst->to_string() << std::endl;
}

std::string RVProgram::StringTrans(std::string s) {
    std::string ret;
    for (int i = 0; i < s.length(); ++i) {
        switch (s[i]) {
//            case '\n':
//                ret += "\\n";
//                break;
//            case '\t':
//                ret += "\\t";
//                break;
//            case '\\':
//                ret += "\\\\";
//                break;
//            case '"':
//                ret += "\\\"";
//                break;
            default:
                ret += s[i];
                break;
        }
    }
    return ret;
}
