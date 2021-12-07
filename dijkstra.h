#pragma once

#include "graph.h"

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

void dijkstra_n2(AGraph &G, int x, int y);

void dijkstra_nlogn(AGraph &G, int x, int y);
