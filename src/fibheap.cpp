#include "fibheap.h"

template <class T>
FibHeap<T>::FibHeap()
{
    keyNum = 0;
    maxDegree = 0;
    min = nullptr;
    cons = nullptr;
}

template <class T>
FibHeap<T>::~FibHeap()
{
    theEnd(min);
}

template <class T>
void FibHeap<T>::theEnd(struct fib_node<T> *node)
{
    if (node == nullptr)
        return;
    struct fib_node<T> *p = node;
    if (p != p->left)
    {
        p = p->left;
        while (p != node)
        {
            struct fib_node<T> *q = p;
            p = p->left;
            removeNode(q);
            q->left = q;
            q->right = q;
            theEnd(q);
        }
    }
    p = node->child;
    theEnd(p);
    delete node;
}

template <class T>
bool FibHeap<T>::empty()
{
    return (keyNum == 0);
}

template <class T>
int FibHeap<T>::size()
{
    return keyNum;
}

template <class T>
void FibHeap<T>::push(T e)
{
    struct fib_node<T> *temp = new struct fib_node<T>;
    temp->key = e;
    temp->left = temp;
    temp->right = temp;
    if (keyNum == 0)
        min = temp;
    else
    {
        addNode(temp, min);
        if (min->key < temp->key)
            min = temp;
    }
    keyNum++;
}

template <class T>
void FibHeap<T>::link(struct fib_node<T> *node, struct fib_node<T> *root)
{

    removeNode(node);

    if (root->child == NULL)
        root->child = node;
    else
        addNode(node, root->child);

    node->parent = root;
    root->degree++;
}

template <class T>
void FibHeap<T>::pop()
{
    if (min == nullptr)
        return;
    keyNum--;
    struct fib_node<T> *p = min;
    struct fib_node<T> *child = nullptr;
    while (p->child != nullptr)
    {
        child = p->child;
        removeNode(child);
        if (child->right == child)
            p->child = nullptr;
        else
            p->child = child->right;
        addNode(child, min);
        child->parent = nullptr;
    }
    removeNode(p);
    if (p->right == p)
        min = nullptr;
    else
    {
        min = p->right;
        consolidate();
    }
    delete p;
}

template <class T>
struct fib_node<T> *FibHeap<T>::extractMin()
{
    struct fib_node<T> *p = min;
    if (p == p->right)
        min = NULL;
    else
    {
        removeNode(p);
        min = p->right;
    }
    p->left = p;
    p->right = p;
    return p;
}

template <class T>
void FibHeap<T>::removeNode(struct fib_node<T> *node)
{
    node->left->right = node->right;
    node->right->left = node->left;
}

template <class T>
void FibHeap<T>::addNode(struct fib_node<T> *node, struct fib_node<T> *root)
{
    node->left = root->left;
    root->left->right = node;
    node->right = root;
    root->left = node;
}

template <class T>
void FibHeap<T>::makeCons()
{
    int old = maxDegree;

    maxDegree = (log(keyNum) / log(2.0)) + 1;
    if (old >= maxDegree)
        return;

    cons = (struct fib_node<T> **)realloc(cons, sizeof(struct fib_node<T> *) * (maxDegree + 1));
}

template <class T>
void FibHeap<T>::consolidate()
{
    int i, d, D;
    struct fib_node<T> *x, *y;

    makeCons();
    D = maxDegree + 1;

    for (i = 0; i < D; i++)
        cons[i] = NULL;

    while (min != NULL)
    {
        x = extractMin();
        d = x->degree;

        while (cons[d] != NULL)
        {
            y = cons[d];

            if (x->key < y->key)
            {
                struct fib_node<T> *temp = y;
                y = x;
                x = temp;
            }

            link(y, x);
            cons[d] = NULL;
            d++;
        }
        cons[d] = x;
    }
    min = NULL;

    for (i = 0; i < D; i++)
    {
        if (cons[i] != NULL)
        {
            if (min == NULL)
                min = cons[i];
            else
            {
                addNode(cons[i], min);
                if ((cons[i])->key > min->key)
                    min = cons[i];
            }
        }
    }
}

template <class T>
T FibHeap<T>::top()
{
    return min->key;
}
