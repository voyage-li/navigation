#pragma once

#include <bits/stdc++.h>

template <class T>
class Heap
{
private:
    std::vector<T> data;
    int length;

public:
    Heap();
    ~Heap();
    inline void swim(int k);      //上浮
    inline void sink(int k);      //下沉
    inline void push(T e);        //入堆
    inline void pop();            //出堆
    inline T top();               //返回堆顶元素
    inline bool empty();          //判断是否为空
    inline int size();            //返回大小
    inline void swap(T &a, T &b); //交换元素
};