#pragma once
#include <bits/stdc++.h>
typedef struct HTNode
{
    long long int num;       //表示第几个元素
    long long int key;       //对应元素的值
    int weight;              //权值
    long long int parent;    //双亲
    long long int child[16]; //孩子
    friend bool operator<(HTNode a, HTNode b)
    {
        return a.weight > b.weight;
    }
} HTNode, *HuffmanTree;

void init(HuffmanTree &HT, std::map<long long int, int> &map, char **&HC, int tree_n);
void select(HuffmanTree &HT, int n);

int judge(int a);