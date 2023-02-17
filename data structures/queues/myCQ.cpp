#include<iostream>
using namespace std;
#define MAX 3
class CircularQ
{
    private:
    int size,front,rear,count;
    char *Q;
    public:
    CircularQ()
    {
        front=rear=0;
        size=MAX+1;
        count=0;
        Q=new char[size];
    }
    void enQ(char x) 
    {
        if(isFull())
            cout<<"Circular Queue is full\n";
        else
        {
            rear=(rear+1)%size;
            Q[rear]=x;cout<<"'"<<x<<"' inserted \n";
            count++;
            display();
        }
    }
    void deQ()
    {
        if(isEmpty())
            cout<<"Circular Queue is empty\n";
        else
        {
            front=(front+1)%size;
            char x=Q[front];count--;
            cout<<"'"<<x<<"' deleted \n";display();
        }
        
    }
    void display()
    {
        if(isEmpty())
            cout<<"Circular Queue is empty\n";
        else
        {
            cout<<"Circular queue: ";
            for(int i=1;i<=count;i++)
                cout<<Q[(front+i)%size]<<" ";
            cout<<endl;
        }
    }
    bool isEmpty()
    {return front==rear;}
    bool isFull()
    {return front==(rear+1)%size;}
};
int main()
{
    CircularQ cq;
    cout<<"CIRCULAR QUEUE\n";
     while (1)
    {
        
        cout <<"------------------\n";;
        cout << "1. Insert a character\n";
        cout << "2. Delete a character\n";
        cout << "3. Display queue\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
            case 1:
                char x; cout << "Enter the character to be inserted: ";
                cin >> x; cq.enQ(x); break;
            case 2:
                cq.deQ(); break;
            case 3: 
                cq.display();break;
            case 4:exit(0);
            default: cout << "Invalid choice. Please try again." << endl; 
        }
    }
}