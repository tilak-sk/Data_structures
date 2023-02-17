#include <iostream>
using namespace std;

template <typename T>
class CircularQueue {
private:
    T *queue; 
    int front, rear, capacity; 

public:
    CircularQueue(int size) 
    { 
        queue = new T[size+1]; 
        front = rear = -1; 
        capacity = size; 
    } 

    ~CircularQueue() { delete[] queue; }

    bool isEmpty() { return front == rear; }

    bool isFull() { return (rear + 1) % capacity == front; }

    void push(T element) 
    { 
        if (isFull()) { 
            cout << "Queue is full" << endl; 
            return; 
        } 
        rear = (rear + 1) % capacity; 
        queue[rear] = element; 
    } 
    T pop() 
    { 
        if (isEmpty()) { 
            cout << "Queue is empty" << endl; 
            return -1; 
        } 

        T element = queue[front]; 
            front = (front + 1) % capacity; 
        return element; 
    } 

    T rearElement() 
    { 
        if (isEmpty()) { 
            cout << "Queue is empty" << endl; 
            return -1; 
        } 
        return queue[rear]; 
    } 

    T frontElement() 
    { 
        if (isEmpty()) { 
            cout << "Queue is empty" << endl; 
            return -1; 
        } 
        return queue[front+1]; 
    } 

    void doubleCapacity() {
        T *temp = new T[capacity * 2];
        int j = front;
        for (int i = 0; i < capacity; i++) {
            temp[i] = queue[j];
            j = (j + 1) % capacity;
        }
        delete[] queue;
        queue = temp;
        front = 0;
        rear = capacity - 1;
        capacity *= 2;
    }
    void display()
    {
        for(int i=front+1;i!=rear+1;i=(i + 1) % capacity) 
        {
            cout << queue[i] << " ";
        }
    }
};
int main() {
    CircularQueue<int> q(5); 
    q.push(1); 
    q.push(2); 
    q.push(3); 
    q.push(4); 
    q.push(5);
    q.display(); 
    cout << "Rear element is: " << q.rearElement() << endl; 
    cout << "Front element is: " << q.frontElement() << endl; 
    q.pop(); 
    cout << "Front after pop is: " << q.frontElement() << endl; 
    // q.doubleCapacity();
    return 0; 
} 
