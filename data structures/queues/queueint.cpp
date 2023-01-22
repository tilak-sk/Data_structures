#include<iostream>
using namespace std;
class Queue
{
    private:
    int size, front, rear;
    int *Q;
    public:
    Queue()
    {
        front = rear= -1;
    }
    bool isFull()
    {
        return rear==size-1;
    }
    bool isEmpty()
    {
        return front==rear;
    }
    void createQ()
    {
        cout<<"Enter the size: ";
        cin>>size;
        Q = new int[size];
    }
    void enqueue(int x)
    {
        if(isFull())//before inserting check whether the queue is full or not
            cout<<"Queue is full\n";
        else
        {
            rear++;
            Q[rear] = x;
        }
    }
    void dequeue()
    {
        if(isEmpty())
            cout<<"Queue is empty\n";
        else
        {
            front++;
            
        }
    }
    void display()
    {
        for(int i = front+1; i<=rear; i++)
            cout<<Q[i]<<" ";
        cout<<endl;

    }
    
    
};

int main()
{
    Queue q1;
    q1.createQ();
    q1.dequeue();
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.enqueue(40);
    q1.enqueue(50);
    q1.enqueue(60);
    q1.dequeue();
    q1.display();

}