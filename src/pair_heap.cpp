#include "pair_heap.h"

template <class T>
pair_heap<T>::pair_heap()
{
    pair_node<T> temp;
    data.push_back(temp);
    length = 0;
    _size = 0;
    root = 0;
}

template <class T>
pair_heap<T>::~pair_heap()
{
}

template <class T>
inline void pair_heap<T>::merge(int x, int y)
{
    if (!x || !y)
        root = x + y;
    else if (x == y)
        root = x;
    else
    {
        if (data[x].val < data[y].val)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        data[y].right = data[x].left;
        data[x].left = y;
        data[x].right = 0;
        root = x;
    }
}

template <class T>
inline void pair_heap<T>::push(T e)
{
    pair_node<T> temp(e);
    data.push_back(temp);
    length++;
    merge(root, length);
    _size++;
}

template <class T>
inline T pair_heap<T>::top()
{
    return data[root].val;
}

template <class T>
inline void pair_heap<T>::pop()
{
    if (_size == 0)
    {
        std::cout << "为空!" << std::endl;
        return;
    }
    if (data[root].left == 0)
        root = 0;
    else if (data[data[root].left].right == 0)
        root = data[root].left;
    else
    {
        std::queue<int> que;
        int now = root;
        que.push(data[now].left);
        now = data[now].left;
        while (data[now].right != 0)
        {
            que.push(data[now].right);
            now = data[now].right;
        }
        int _que_size = que.size();
        while (_que_size >= 2)
        {
            int a = que.front();
            que.pop();
            int b = que.front();
            que.pop();
            merge(a, b);
            que.push(root);
            _que_size--;
        }
    }
    _size--;
}

template <class T>
inline int pair_heap<T>::merges(int x, int y)
{
    if (!x || !y)
        return x + y;
    else if (x == y)
        return x;
    else
    {
        if (data[x].val < data[y].val)
        {
            int temp = x;
            x = y;
            y = temp;
        }
        data[y].right = data[x].left;
        data[x].left = y;
        data[x].right = 0;
        return x;
    }
}

template <class T>
inline void pair_heap<T>::_pop()
{
    root = pop_();
    _size--;
}

template <class T>
inline int pair_heap<T>::pop_()
{
    if (_size == 0)
    {
        std::cout << "为空!" << std::endl;
        return 0;
    }
    if (data[root].left == 0)
        return 0;
    else if (data[data[root].left].right == 0)
        return data[root].left;
    else
    {
        int son1 = data[root].left;
        int son2 = data[data[root].left].right;
        data[root].left = data[data[data[root].left].right].right;
        return merges(merges(son1, son2), pop_());
    }
}

template <class T>
inline bool pair_heap<T>::empty()
{
    return (_size == 0);
}

template <class T>
inline int pair_heap<T>::size()
{
    return _size;
}