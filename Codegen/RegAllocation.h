#pragma once

#include "RVProgram.h"
#include "Liveness.h"

class RegAllocation {
public:

    class Edge {
    public:
        int x, y;
        Edge(int _x, int _y);
        bool operator < (const Edge &rhs) const;
    };

    std::shared_ptr<RVProgram> prog;
    std::shared_ptr<Liveness> LivenessAnalyser;

    int K, stackOffset;
    std::vector<int> selectStack;
    std::set<int> preColored, initial, spillWorkList, freezeWorkList, simplifyWorkList, spilledNodes, coalescedNodes, coloredNodes;
    std::map<int, int> nodeColor, degree, alias, nodeStackOffset;
    std::map<int, std::set<std::shared_ptr<RVMv>>> moveList;
    std::set<std::shared_ptr<RVMv>> workListMoves, activeMoves, coalescedMoves, constrainedMoves, frozenMoves;
    std::set<Edge> adjSet;
    std::map<int, std::set<int>> adjList;

    std::shared_ptr<RVFunction> _func;
    void addEdge(int x, int y);

    void rewriteProgram();
    void assignColors();
    void selectSpill();
    void freezeMoves(int x);
    void freeze();
    bool conservative(std::set<int> nodes);
    void combine(int u, int v);
    bool forAllOK(int u, int v);
    bool OK(int t, int r);
    void addWorkList(int x);
    int getAlias(int x);
    void coalesce();
    std::set<std::shared_ptr<RVMv>> nodeMoves(int x);
    std::set<int> adjacent(int x, int y);
    std::set<int> adjacent(int x);
    void enableMoves(std::set<int> nodes);
    void decrementDegree(int x);
    void simplify();
    bool moveRelated(int x);
    void makeWorkList();
    void build();
    void init();
    void runForFunction();
    void run();
    RegAllocation(std::shared_ptr<RVProgram> _prog);
};