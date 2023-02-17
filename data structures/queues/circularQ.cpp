// Develop a C++ Program to perform the following operations on Circular 
// Queue of Characters (Array Implementation of Queue with maximum 
// size MAX)
// a. Insert an Element on to Circular Queue
// b. Delete an Element from Circular Queue
// c. Demonstrate Overflow and Underflow situations on Circular Queue
// d. Display the status of Circular Queue
#include<iostream>
using namespace std;
#define MAX 3
class CircularQ
{
    private:
    char *arr; 
    int front,rear,count;
    public:
    CircularQ()
    {
        front = 0;
        rear = MAX - 1;
        count = 0;
        arr = new char[MAX];
    }
    void enqueue(char x)
    {
        if(isFull())
        cout << "Circular queue full." << endl;
        else
        {
            cout << "Element '" << x << "' inserted successfully." << endl;
            rear = (rear + 1) % MAX;
            arr[rear] = x;
            count++;
            display();
        }
    }
    void dequeue()
    {
        if (isEmpty())
            cout << "Circular queue empty." << endl;
        else
        {
            cout << "Element '" << arr[front] << "'deleted successfully." <<
            endl;
            front = (front + 1) % MAX;
            count--;
            display();
        }
    }
    void display()
    {
        if (isEmpty())
            cout << "Circular queue empty." << endl;
        else
        {
            cout << "Circular queue: ";
            for (int i = 0; i < count; i++)
            cout << arr[(front + i) % MAX] << " ";
            cout << endl;
        }
    }
    bool isFull()
    {return (count == MAX);}
    bool isEmpty()
    {return (count == 0);}
};
int main()
{
    CircularQ cq;
    while (1)
    {
        cout << endl;
        cout << "1. Insert an element in the circular queue." << endl;
        cout << "2. Delete an element from the circular queue." << endl;
        cout << "3. Display queue." << endl;
        cout << "4. Exit." << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                char x; cout << "Enter the element to be inserted: ";
                cin >> x; cq.enqueue(x); break;
            case 2:
                cq.dequeue(); break;
            case 3: 
                cq.display();break;
            case 4:exit(0);
            default: cout << "Invalid choice. Please try again." << endl;break;
        }
    }
    return 0;
}