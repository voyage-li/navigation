#include "Heap.h"

template <class T>
void Heap<T>::swap(T &a, T &b)
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
bool Heap<T>::empty()
{
    return (length == 0);
}

template <class T>
int Heap<T>::size()
{
    return length;
}

template <class T>
void Heap<T>::push(T e)
{
    data.push_back(e);
    length++;
    swim(length);
}

template <class T>
void Heap<T>::pop()
{
    swap(data[1], data[length--]);
    data.pop_back();
    sink(1);
}

template <class T>
T Heap<T>::top()
{
    if (!empty())
        return data[1];
    return data[0];
}

template <class T>
void Heap<T>::swim(int k)
{
    while (k > 1 && data[k] < data[k / 2])
    {
        swap(data[k], data[k / 2]);
        k /= 2;
    }
}

template <class T>
void Heap<T>::sink(int k)
{
    while (k * 2 <= length)
    {
        int j = 2 * k;
        if (j < length && (data[j] > data[j + 1])) //找到左右子树中更小的
            j++;
        if (data[k] < data[j])
            break;
        swap(data[k], data[j]);
        k = j;
    }
}