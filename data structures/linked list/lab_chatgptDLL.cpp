#include<iostream>
using namespace std;
class DLL;
class Node
{
    private:
        int data;
        Node *prev,*next;
        friend class DLL;
};
class DLL
{
    private:
    Node *first,*last,*t;
    int count;
    public:
    DLL()
    {
        first=NULL;
        count=0;
    }
    void insertFirst(int x)
    {
        t = new Node;
        t->data = x;
        t->next = t->prev = NULL;
        if(first==NULL)
            first=last=t;
        else
        {
            t->next=first;
            first->prev=t;
            first=t;
        }
        count++;

    }

        
    void display()
    {
        Node *p=first;
        while(p!=NULL)
        {
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<endl<<"No of nodes: "<<count<<endl; 
    }
};
int main()
{
    DLL ls;
    ls.insertFirst(20);
    ls.insertFirst(30);
    ls.insertFirst(50);

    ls.display();
}
//  if u need refer this program ... and in the answer program use cin.ignore and getline to input user data
// Design a menu driven Program in C++ for the following operations on 
// Doubly Linked List (DLL) of Employee Data with the fields: SSN, Name, 
// Dept, Designation and salary. Perform the following operations.
// a. Create a double linked list of employees data.
// b. Insert a new employee to the left of the node whose key value 
// (employee name) is read as an input. 
// c. Delete a node with given data, if it is found. Otherwise display 
// appropriate error message