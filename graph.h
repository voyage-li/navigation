#pragma once

#include <bits/stdc++.h>

struct ArcNode
{
    int adjvex;
    struct ArcNode *nextarc;
};

struct VNode
{
    int weight;
    struct ArcNode *firstarc;
};

class AGraph
{
private:
    std::vector<VNode> data;
    std::unordered_map<int, int> map;
    int vexnum;
    int now_vex;

public:
    AGraph(int length);
    ~AGraph();
    bool input(int x, int y, int info);
    int get_arc(int x, int y);
    int get_vex();
};