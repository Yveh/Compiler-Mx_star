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

}

void RVProgram::outputBlock(std::shared_ptr<IRBlock> _blk, std::ostream &ofs) {

}
