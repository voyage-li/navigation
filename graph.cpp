#include "graph.h"

MGraph::MGraph(int length)
{
    now_vex = 0;
    vexnum = length;
    data = new int *[length];
    for (int i = 0; i < length; i++)
        data[i] = new int[length];
    for (int i = 0; i < length; i++)
        for (int j = 0; j < length; j++)
            data[i][j] = INT_MAX;
};

MGraph::~MGraph()
{
    for (int i = 0; i < vexnum; i++)
        delete[] data[i];
    delete[] data;
}

int MGraph::get_vex()
{
    return vexnum;
}

bool MGraph::input(int x, int y, int info)
{
    if (map.find(x) == map.end())
        map[x] = now_vex++;
    if (map.find(y) == map.end())
        map[y] = now_vex++;
    data[map[x]][map[y]] = info;
    return true;
}

int MGraph::get_arc(int x, int y)
{
    return data[map[x]][map[y]];
}