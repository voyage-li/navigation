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
    struct ArcNode *last_ptr;

public:
    std::vector<VNode *> data;
    AGraph();
    ~AGraph();
    bool input(int x, int y, int info);  //输入数据
    bool input_(int x, int y, int info); //输入数据
    int get_vex();                       //返回点数
};
