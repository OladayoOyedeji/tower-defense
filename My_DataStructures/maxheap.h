#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <vector>
#include <string>

// File: maxheap.h
// This file contains the function templates for the max heap.

// template < typename T >
// int left(int i);
// template < typename T >
// int right(int i);
// template < typename T >
// int parent(int i);
// template < typename T >
// void maxheap_insert(std::vector<int> & heap, int value);
// template < typename T >
// T maxheap_delete(std::vector<T> & heap);
// template < typename T >
// T maxheap_max(std::vector<T> & heap);
// template < typename T >
// void maxheap_heapify_up(std::vector<T> & heap, int i);
// template < typename T >
// void maxheap_heapify_down(std::vector<T> & heap, int i);
// template < typename T >
// void maxheap_build(std::vector<T> & heap);
// template < typename T >
// void maxheap_heapsort(std::vector<T> & heap);

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

int parent(int i)
{
    return (i - 2) / 2;
}

template < typename T >
void maxheap_heapify_up(std::vector<T> & heap, int i)
{
    T t = heap[i];
    
    while (1)
    {
        int p = parent(i);
        if (p < 0)
        {
            heap[i] = t;
            break;
        }
        if (t > heap[p])
        {
            heap[i] = heap[p];
            i = p;
        }
        else
        {
            heap[i] = t;
            break;
        }
    }
}
template < typename T >
void maxheap_heapify_up(std::vector<T> & heap, int i,
                        bool (*cmp)(const T&, const T&))
{
    T t = heap[i];
    
    while (1)
    {
        int p = parent(i);
        if (p < 0)
        {
            heap[i] = t;
            break;
        }
        if (cmp(t, heap[p]))
        {
            heap[i] = heap[p];
            i = p;
        }
        else
        {
            heap[i] = t;
            break;
        }
    }
}

template < typename T >
void maxheap_heapify_down(std::vector<T> & heap, int i)
{
    T t = heap[i];
    int j;
    while (1)
    {
        int l = left(i);
        int r = right(i);
        if (l >= heap.size())
        {
            j = l;
        }
        else
        {
            if (r >= heap.size())
            {
                j = l;
            }
            else if (heap[l] > heap[r])
            {
                j = l;
            }
            else
            {
                j = r;
            }
        }
        if (j < heap.size() && heap[j] > t)
        {
            heap[i] = heap[j];
            i = j;
        }
        else
        {
            heap[i] = t;
            break;
        }
    }
}

template <typename T>
void maxheap_heapify_down(std::vector<T> & heap, int i, int size)
{
    T t = heap[i];
    int j;
    while (1)
    {
        int l = left(i);
        int r = right(i);
        if (l >= size)
        {
            j = l;
        }
        else
        {
            if (r >= size)
            {
                j = l;
            }
            else if (heap[l] > heap[r])
            {
                j = l;
            }
            else
            {
                j = r;
            }
        }
        if (j < size && heap[j] > t)
        {
            heap[i] = heap[j];
            i = j;
        }
        else
        {
            heap[i] = t;
            break;
        }
    }
}

template < typename T >
void maxheap_build(std::vector<T> & heap)
{
    for (int i = heap.size()/2; i >= 0; --i)
    {
        maxheap_heapify_down(heap, i);
    }
}

template < typename T >
void maxheap_insert(std::vector<T> & heap, T value)
{
    heap.push_back(value);
    
    maxheap_heapify_up(heap, heap.size() - 1);
}

template < typename T >
T maxheap_delete(std::vector<T> & heap)
{
    T v = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.resize(heap.size() - 1);

    maxheap_heapify_down(heap, 0);
    return v;
}

template < typename T >
T maxheap_max(std::vector<T> & heap)
{
    return heap[0];
}


template < typename T >
void maxheap_heapsort(std::vector<T> & heap)
{
    maxheap_build(heap);
    for (int i = heap.size() - 1; i > 0; --i)
    {
        T t = heap[0];
        heap[0] = heap[i];
        heap[i] = t;
        maxheap_heapify_down(heap, 0, i);
    }
}

template <typename T>
std::ostream & operator<<(std::ostream & cout, const std::vector<T> & v)
{
    std::string delim = "";
    cout << '{';
    for (int i = 0; i < v.size(); ++i)
    {
        std::cout << delim << v[i];
        delim = ", ";
    }
    cout << '}';
    return cout;
}

// Etc.
#endif
