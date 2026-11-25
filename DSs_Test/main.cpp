#include <iostream>
#include "../Project/DSs/Queue.h"
#include "../Project/DSs/LinkedList.h"
using namespace std;

int main()
{
    // ---------- Queue ----------
    Queue<int> q;
    int x;

    cout << "Queue empty? " << q.isEmpty() << endl;          // 1
    cout << "Dequeue from empty: " << q.Dequeue(x) << endl;  // 0

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    cout << "Count: "<<q.getCount() << endl;               // 3

    q.Peek(x);
    cout << "Peek: " << x << endl;                           // 1
    cout << "Count after peek: " << q.getCount() << endl;    // 3

    while (q.Dequeue(x))
        cout << "Dequeued: " << x << endl;                   // 1 2 3

    cout << "Queue empty now? " << q.isEmpty() << endl;      // 1

    // ---------- LinkedList ----------
    LinkedList<int> list;
    int v;

    list.Insert(10);
    list.Insert(20);
    list.Insert(30);
    cout << "\nList count: " << list.getCount() << endl;     // 3

    list.getAt(1, v);
    cout << "Item at 1: " << v << endl;                      // 20
    cout << "Item at 3: " << list.getAt(3, v) << endl;       // 0

    cout << "Remove 20: " << list.Remove(20) << endl;        // 1
    cout << "Remove 99: " << list.Remove(99) << endl;        // 0

    list.getAt(1, v);
    cout << "Item at 1 now: " << v << endl;                  // 30

    cout << "RemoveAt 0: " << list.RemoveAt(0) << endl;      // 1
    cout << "RemoveAt 5: " << list.RemoveAt(5) << endl;      // 0
    cout << "List count: " << list.getCount() << endl;       // 1

    list.RemoveAt(0);
    cout << "List empty now? " << list.isEmpty() << endl;    // 1

    return 0;
}