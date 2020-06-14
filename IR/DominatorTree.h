#pragma once

#include <vector>
#include <memory>

#include "IR.h"
#include "IRProgram.h"

class DominatorTree {
public:
    std::vector<int> ufs, home, sdom, idom, fa;
    std::map<int, int> id;
    std::vector<std::vector<int>> c;
    std::vector<std::shared_ptr<IRBlock>> ref;
    int ord;
    void dfs(std::shared_ptr<IRBlock> node);
    void dfs2(std::shared_ptr<IRBlock> node);
    int F(int x);
    int gethome(int x);
    void calc();
    void build(std::shared_ptr<IRBlock> node);
    void createDomTree(std::shared_ptr<IRProgram> prog);
};
