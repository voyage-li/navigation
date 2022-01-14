#pragma once

#include <bits/stdc++.h>

template <class T>
class pair_node
{
public:
    T val;
    int left;
    int right;
    pair_node()
    {
        left = 0;
        right = 0;
    }
    pair_node(T e)
    {
        val = e;
        left = 0;
        right = 0;
    }
};
template <class T>
class pair_heap
{
private:
    std::vector<pair_node<T>> data;
    int length; //已经到达的vector地址
    int _size;  //实际存储的大小
    inline void merge(int x, int y);
    inline int merges(int x, int y);
    int root;
    inline int pop_();

public:
    pair_heap();
    ~pair_heap();
    inline void push(T e);
    inline void pop();
    inline void _pop();
    inline T top();
    inline bool empty();
    inline int size();
};