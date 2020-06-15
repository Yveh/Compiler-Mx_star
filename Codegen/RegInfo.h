#pragma


#include <vector>
#include <string>

static std::string regNames[32] = {"zero","ra","sp","gp","tp","t0","t1","t2","s0","s1","a0","a1","a2","a3","a4","a5","a6","a7","s2","s3","s4","s5","s6","s7","s8","s9","s10","s11","t3","t4","t5","t6" };
static int calleeSavedRegNames[12] = {8, 9, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27};
static int allocatableReg[28] = {1, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31};