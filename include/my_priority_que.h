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
    void swim(int k);
    void sink(int k);
    void push_back(T e);
    void pop();
    T top();
    bool empty();
    int size();
};