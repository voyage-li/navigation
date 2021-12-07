#include "graph.h"

AGraph::AGraph(int length)
{
    now_vex = 0;
    vexnum = length;
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
    std::cout << "\r\t\t\t\t\t\t\r" << x;
    if (map.find(x) == map.end())
    {
        map[x] = now_vex++;
        struct VNode *first_init = new VNode;
        first_init->vex_data = x;
        first_init->firstarc = nullptr;
        data.push_back(first_init);
    }
    if (map.find(y) == map.end())
    {
        map[y] = now_vex++;
        struct VNode *first_init = new VNode;
        first_init->vex_data = y;
        first_init->firstarc = nullptr;
        data.push_back(first_init);
    }
    struct ArcNode *p = new ArcNode;
    p->nextarc = nullptr;
    p->weight = info;
    p->adjvex = map[y];

    struct ArcNode *q = data[map[x]]->firstarc;
    if (q == nullptr)
    {
        data[map[x]]->firstarc = p;
        return true;
    }
    while (q->nextarc != nullptr)
        q = q->nextarc;
    q->nextarc = p;

    return true;
}
