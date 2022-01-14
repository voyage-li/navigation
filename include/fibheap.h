#pragma once

#include <bits/stdc++.h>

template <typename T>
struct fib_node
{
    struct fib_node<T> *parent;
    struct fib_node<T> *child;
    struct fib_node<T> *left;
    struct fib_node<T> *right;
    T key;
    int degree;
    fib_node() : parent(nullptr), child(nullptr), left(this), right(this), degree(0) {}
};

template <class T>
class FibHeap
{
private:
    int keyNum;
    int maxDegree;
    struct fib_node<T> *min;
    struct fib_node<T> **cons;
    void removeNode(struct fib_node<T> *node);
    void addNode(struct fib_node<T> *node, struct fib_node<T> *root);
    void consolidate();
    struct fib_node<T> *extractMin();
    void makeCons();
    void link(struct fib_node<T> *node, struct fib_node<T> *root);
    void theEnd(struct fib_node<T> *node);

public:
    FibHeap();
    ~FibHeap();
    void push(T e);
    void pop();
    bool empty();
    int size();
    T top();
};