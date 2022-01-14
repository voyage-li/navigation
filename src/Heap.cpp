#include "Heap.h"

template <class T>
inline void Heap<T>::swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

template <class T>
Heap<T>::Heap()
{
    T temp;
    data.push_back(temp);
    length = 0;
}

template <class T>
Heap<T>::~Heap()
{
}

template <class T>
inline bool Heap<T>::empty()
{
    return (length == 0);
}

template <class T>
inline int Heap<T>::size()
{
    return length;
}

template <class T>
inline void Heap<T>::push(T e)
{
    data.push_back(e);
    length++;
    swim(length);
}

template <class T>
inline void Heap<T>::pop()
{
    swap(data[1], data[length--]);
    data.pop_back();
    sink(1);
}

template <class T>
inline T Heap<T>::top()
{
    if (!empty())
        return data[1];
    return data[0];
}

template <class T>
inline void Heap<T>::swim(int k) //上浮
{
    while (k > 1 && data[k] > data[k / 2])
    {
        swap(data[k], data[k / 2]);
        k /= 2;
    }
}

template <class T>
inline void Heap<T>::sink(int k) //下沉
{
    while (k * 2 <= length)
    {
        int j = 2 * k;
        if (j < length && (data[j] < data[j + 1])) //找到左右子树中更小的
            j++;
        if (data[k] > data[j])
            break;
        swap(data[k], data[j]);
        k = j;
    }
}