#include "graph.h"

AGraph::AGraph()
{
    vexnum = 0;
    data.resize(100000000, nullptr);
};

AGraph::~AGraph()
{
}

int AGraph::get_vex()
{
    return vexnum;
}

bool AGraph::input(int x, int y, int info)
{
    std::cout << "\r" << x << " " << y << " " << info;
    if (data[x] == nullptr)
    {
        vexnum++;
        struct VNode *first_init = new VNode;
        first_init->vex_data = x;
        first_init->firstarc = nullptr;
        data[x] = first_init;
    }
    struct ArcNode *p = new ArcNode;
    p->nextarc = nullptr;
    p->weight = info;
    p->adjvex = y;

    struct ArcNode *q = data[x]->firstarc;
    if (q == nullptr)
    {
        data[x]->firstarc = p;
        last_ptr = p;
        return true;
    }
    while (q->nextarc != nullptr)
        q = q->nextarc;
    q->nextarc = p;

    last_ptr = p;
    return true;
}

bool AGraph::input_(int x, int y, int info)
{
    std::cout << "\r" << x << " " << y << " " << info;

    struct ArcNode *p = new ArcNode;
    p->nextarc = nullptr;
    p->weight = info;
    p->adjvex = y;
    last_ptr->nextarc = p;
    last_ptr = p;

    return true;
}
