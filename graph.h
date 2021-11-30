#pragma once

#include <bits/stdc++.h>

class MGraph
{
private:
    int **data;
    std::unordered_map<int, int> map;
    int vexnum;
    int now_vex;

public:
    MGraph(int length);
    ~MGraph();
    bool input(int x, int y, int info);
    int get_arc(int x, int y);
    int get_vex();
};