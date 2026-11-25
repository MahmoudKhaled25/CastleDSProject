#pragma once

template <class T>

struct Node {
	T *item;
	Node<T>* next;
	Node<T>* prev;
    Node(T* val)
    {
        item = val;
        next = nullptr;
        prev = nullptr;
    }

    Node()
    {
        item = nullptr;
        next = nullptr;
        prev = nullptr;
    }
};