#pragma once
#include "Node.h"

template <class T>
class LinkedList
{
    Node<T>* head;
    Node<T>* tail;
    int count;

public:

    LinkedList() {
        head = tail = nullptr;
        count = 0;
    }

    bool isEmpty() { return head == nullptr; }

    int getCount() { return count;}

    void Insert(const T& item) {
        Node<T>* temp = new Node<T>(item);

        if (head == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        count++;
    }

    bool Remove(const T& item) {
        Node<T>* temp = head;

        while (temp) {
            if (temp->item == item) {

                if (head == tail) {
                    head = tail = nullptr;
                }
                else if (temp == head) {
                    head = head->next;
                    head->prev = nullptr;
                }
                else if (temp == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }

                delete temp;
                count--;
                return true;
            }

            temp = temp->next;
        }

        return false;
    }

    bool RemoveAt(int id) {
        if (id < 0 || id >= count)
            return false;

        Node<T>* temp = head;

        for (int i = 0; i < id; i++) {
            temp = temp->next;
        }

        if (head == tail) {
            head = tail = nullptr;
        }
        else if (temp == head) {
            head = head->next;
            head->prev = nullptr;
        }
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        count--;

        return true;
    }

    bool getAt(int id, T& item) {
        if (id < 0 || id >= count)
            return false;

        Node<T>* temp = head;

        for (int i = 0; i < id; i++) {
            temp = temp->next;
        }

        item = temp->item;
        return true;
    }


    ~LinkedList() {
        while (head) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }

        head = tail = nullptr;
        count = 0;
    }
};