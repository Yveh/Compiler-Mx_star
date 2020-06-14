#include <iostream>
#include "DominatorTree.h"
#include "IRProgram.h"

void DominatorTree::build(std::shared_ptr<IRBlock> node) {
    //
    if (node == nullptr)
        return;
    //
    ord = 0;
    dfs(node);
    ufs.resize(ord);
    ufs.clear();
    ref.resize(ord);
    ref.clear();
    sdom.resize(ord);
    sdom.clear();
    idom.resize(ord);
    idom.clear();
    home.resize(ord);
    home.clear();
    fa.resize(ord);
    fa.clear();
    c.resize(ord);
    c.clear();
    dfs2(node);
    for (int i = 0; i < ord; ++i) {
        ufs[i] = i;
        sdom[i] = i;
        idom[i] = 0;
        home[i] = i;
    }
    calc();
    for (int i = 0; i < ord; ++i) {
        ref[i]->idom = ref[idom[i]];
//        printf("LAB %d idom is LAB %d\n", ref[i]->label, ref[idom[i]]->label);
    }
    for (int i = 0; i < ord; ++i) {
        std::shared_ptr<IRBlock> blk = ref[i];
        for (auto pre : blk->pre) {
            std::shared_ptr<IRBlock> x = pre;
            while (x != blk->idom) {
                x->domFrontier.insert(blk);
                x = x->idom;
            }
        }
    }
//    for (int i = 0; i < ord; ++i) {
//        printf("%d: ", ref[i]->label);
//        for (auto x : ref[i]->domFrontier)
//            printf("%d ", x->label);
//        puts("");
//    }
}

int DominatorTree::F(int x) {
    if (ufs[x] == x)
        return x;
    int tmp = ufs[x];
    ufs[x] = F(ufs[x]);
    if (sdom[home[tmp]] < sdom[home[x]])
        home[x] = home[tmp];
    return ufs[x];
}

int DominatorTree::gethome(int x) {
    F(x);
    return home[x];
}

void DominatorTree::dfs(std::shared_ptr<IRBlock> node) {
    id[node->label] = ord++;
    for (auto child : node->next)
        if (!id.count(child->label))
            dfs(child);
}

void DominatorTree::dfs2(std::shared_ptr<IRBlock> node) {
    ref[id[node->label]] = node;
    for (auto child : node->next)
        if (id[child->label] > id[node->label]) {
            dfs2(child);
            fa[id[child->label]] = id[node->label];
        }
}

void DominatorTree::calc() {
    for (int i = ord - 1; i >= 1; --i) {
        int tmp = i;
        for (auto x : ref[tmp]->pre)
            if (id[x->label])
                sdom[tmp] = std::min(sdom[tmp], sdom[gethome(id[x->label])]);
        c[sdom[tmp]].push_back(tmp);
        ufs[tmp] = fa[tmp];
        tmp = fa[tmp];
        for (auto x : c[tmp]) {
            int tnp = gethome(x);
            if (sdom[tnp] == tmp)
                idom[x] = tmp;
            else
                idom[x] = tnp;
        }
        c[tmp].clear();
    }
    for (int i = ord - 1; i >= 1; --i) {
        int tmp = i;
        if (sdom[tmp] != idom[tmp])
            idom[tmp] = idom[idom[tmp]];
        //ref[idom[tmp]].domedge.push_back(tmp);
    }
}

void DominatorTree::createDomTree(std::shared_ptr<IRProgram> prog) {
    for (auto child : prog->func) {
        if (child->isBuiltin)
            continue;
        build(child->inBlock);
    }
}
