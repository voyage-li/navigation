#pragma once

#include "graph.h"
#include "Heap.h"
#include "pair_heap.h"
#include "fibheap.h"

struct node
{
    int begin;
    int distance;
    node()
    {
        begin = 0;
        distance = 0;
    };
    node(int a, int b)
    {
        begin = a;
        distance = b;
    };
    friend bool operator>(struct node n1, struct node n2)
    {
        return n1.distance < n2.distance;
    }
    friend bool operator<(struct node n1, struct node n2)
    {
        return n1.distance > n2.distance;
    }
};

struct cmp
{
    bool operator()(struct node x, struct node y)
    {
        return x.distance > y.distance; //结构体中，x小的优先级高 （意即大于号出来的是小根堆）
    }
};

int find_min(std::unordered_map<int, int> &dis_map, int vis[]);
clock_t dijkstra(AGraph &G, int x, int y);               //朴素算法
clock_t dijkstra_heap(AGraph &G, int x, int y);          //手写二叉堆
clock_t dijkstra_fibheap(AGraph &G, int x, int y);       //手写 Fibonacci堆
clock_t dijkstra_pair_heap(AGraph &G, int x, int y);     //手写配对堆（递归 merge）
clock_t dijkstra_pair_heap_0(AGraph &G, int x, int y);   //手写配对堆（队列 merge）
clock_t dijkstra_heap_gnu(AGraph &G, int x, int y);      // pbds库 优先队列
clock_t dijkstra_pair_heap_gnu(AGraph &G, int x, int y); // pbds库 配对堆
clock_t dijkstra_thin_heap_gnu(AGraph &G, int x, int y); // pbds库 Fibonacci堆
