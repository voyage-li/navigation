#include "graph.h"

AGraph::AGraph(int length)
{
    now_vex = 0;
    vexnum = length;
}

AGraph::~AGraph()
{
}

int AGraph::get_vex()
{
    return vexnum;
}

bool AGraph::input(int x, int y, int info)
{
    if (map.find(x) == map.end())
        map[x] = now_vex++;
    if (map.find(y) == map.end())
        map[y] = now_vex++;

    return true;
}

int AGraph::get_arc(int x, int y)
{
}