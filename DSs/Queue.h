#pragma once
#include "Node.h"

template <class T>
class Queue
{
    Node<T>* front;
    Node<T>* rear;
    int count;

public:
    Queue(){
        front = rear = nullptr;
        count = 0;
    }

    bool IsEmpty(){ return front == nullptr; }

    int  GetCount() { return count; }

    void Enqueue(const T& item){
        Node<T>* top = new Node<T>();
        top->item = item;
        top->next = nullptr;

        if (front == nullptr) {
            front = rear = top;
        }
        else{
            rear->next = top;
            rear = top;
        }
        count++;
    }

    bool Dequeue(T& item){
        if (front == nullptr) {
            return false;
        }

        item = front->item;
        Node<T>* t = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete t;
        count--;
        return true;
    }

    bool Peek(T& item){
        if (front == nullptr)
            return false;
        item = front->item;
        return true;
    }

    ~Queue(){
        while (front){
            Node<T>* t = front;
            front = front->next;
            delete t;
        }
    }
};
