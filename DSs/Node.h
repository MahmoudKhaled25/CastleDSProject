#pragma once

template <class T>

struct Node {
	T item;
	Node<T>* next;
	Node<T>* prev;
};