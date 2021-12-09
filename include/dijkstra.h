#pragma once

#include "graph.h"
#include "my_priority_que.h"

struct node
{
    int begin;
    int distance;
    node(int a, int b)
    {
        begin = a;
        distance = b;
    };
    friend bool operator<(struct node n1, struct node n2)
    {
        return n1.distance > n2.distance;
    }
};

int find_min(int dis[], int len, int vis[]);
void dijkstra(AGraph &G, int x, int y);
void dijkstra_pri(AGraph &G, int x, int y);
