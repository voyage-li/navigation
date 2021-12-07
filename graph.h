#pragma once

#include <bits/stdc++.h>

typedef struct ArcNode
{
    int adjvex;
    int weight;
    struct ArcNode *nextarc;
} ArcNode;
//顶点
struct VNode
{
    int vex_data;
    ArcNode *firstarc;
};

class AGraph
{
private:
    int vexnum;
    int now_vex;

public:
    std::vector<VNode *> data;
    std::unordered_map<int, int> map;
    AGraph(int length);
    ~AGraph();
    bool input(int x, int y, int info); //输入数据
    int get_vex();                      //返回点数
    // int operator[](int x);
};
