#include <iostream>
#include "QueType.h"

using namespace std;


class FullQueue
{};

class EmptyQueue
{};

typedef int ItemType;

class QueType
{
public:
    QueType();
    // Class constructor.
    // Because there is a default constructor, the precondition 
    // that the queue has been initialized is omitted.
    QueType(int max);
    // Parameterized class constructor.
    ~QueType();
    // Class destructor.
    void MakeEmpty();
    // Function: Initializes the queue to an empty state.
    // Post: Queue is empty.
    bool IsEmpty() const;
    // Function: Determines whether the queue is empty.
    // Post: Function value = (queue is empty)
    bool IsFull() const;
    // Function: Determines whether the queue is full.
    // Post: Function value = (queue is full)
    void Enqueue(ItemType newItem);
    // Function: Adds newItem to the rear of the queue.
    // Post: If (queue is full) FullQueue exception is thrown
    //       else newItem is at rear of queue.
    void Dequeue(bool right);
    // Function: Removes front item from the queue and returns it in item.
    // Post: If (queue is empty) EmptyQueue exception is thrown
    //       and item is undefined
    //       else front element has been removed from queue and
    //       item is a copy of removed element.
    void printall();

private:
    int front;
    int ffront;
    int rear;
    int rrear;
    ItemType* items;
    int maxQue;
};

QueType::QueType()          // Default class constructor
// Post: maxQue, front, and rear have been initialized.
//       The array to hold the queue elements has been dynamically
//       allocated.
{
    maxQue = 101;
    front = maxQue - 1;
    rear = maxQue - 1;
    rrear = maxQue - 1;
    ffront = 0;
    items = new ItemType[maxQue];
}
QueType::~QueType()         // Class destructor
{
    delete[] items;
}

void QueType::MakeEmpty()
// Post: front and rear have been reset to the empty state.
{
    front = maxQue - 1;
    rear = maxQue - 1;
}

bool QueType::IsEmpty() const
// Returns true if the queue is empty; false otherwise.
{
    return (rear == front);
}

bool QueType::IsFull() const
// Returns true if the queue is full; false otherwise.
{
    return (front + 1) == rrear ;
}

void QueType::Enqueue(ItemType newItem)
{
    
    if (IsFull())
        throw FullQueue();
    else
    {
        if (newItem <= 50) {
            front = (front + 1) % maxQue;
            items[front] = newItem;
        }
        else {
            items[rear] = newItem;
            rear = (rear - 1) % maxQue;
        }
    }
}

void QueType::Dequeue(bool right)
{
    if (IsEmpty())
        throw EmptyQueue();
    else
    {
        if (right == true) {
            ffront = (ffront + 1) % maxQue;
        }
        else {
            rrear = (rrear - 1) % maxQue;
        }
    }
}
void QueType::printall() {
    cout << endl;
    cout << "First Queue" << endl;;
    for (int i = ffront; i <= front; i++) {
        cout << items[i] << '\t';
    }
    cout << endl;
    cout << " Second Queue;" << endl;
    cout << endl;
    for (int k = rrear; k > rear; k--) {
        cout << items[k] << '\t';
    }
}

int main() {
    //test driver

    QueType Que;
    bool side;
    for (int i = 0; i < 5; i++) {
        Que.Enqueue(i);
    }
    for (int i = 100; i > 95; i--) {
        Que.Enqueue(i);
    }
    Que.printall();

    side = false;
    Que.Dequeue(side);
    
    Que.printall();
    
    side = true;
    Que.Dequeue(side);
    Que.printall();


    return 0;
}




