// Design a menu driven Program in C++ for the following operations on Singly Linked List of Student 
// Data with the fields: USN, Name, Branch, Sem, PhNo. Perform the following operations on the 
// linked list. 
// a. Insert a student at the front of the list. 
// b. Delete a node with specified student name. 
// c. Display the list and count the number of nodes in it.
#include<iostream>
#include<string>
using namespace std;
class LL;
class Node
{
    private:
    string usn,name,branch,sem,phno;
    Node *next;
    friend class LL;
    
};
class LL
{
    private:
    Node *first;
    Node *t,*last;
    int count;
    public:
    LL()
    {
        count=0;
        first = NULL;
    }
    void insert();
    void Delete(string nm);
    void display();
};
void LL::insert()
{
       
    cout<<"Enter student details: \n";
    if(first == NULL)
    {
        first = new Node;
        cout<<"USN: ";getline(cin,first->usn);
        cout<<"Name: ";getline(cin,first->name);
        cout<<"Branch: ";getline(cin,first->branch);
        cout<<"SEM: ";getline(cin,first->sem);
        cout<<"Ph no.: ";getline(cin,first->phno);
        first->next=NULL;
        last = first;
    }
    else
    {
        t = new Node;
        cout<<"USN: ";getline(cin,t->usn);
        cout<<"Name: ";getline(cin,t->name);
        cout<<"Branch: ";getline(cin,t->branch);
        cout<<"SEM: ";getline(cin,t->sem);
        cout<<"Ph no.: ";getline(cin,t->phno);
        t->next=first;
        first = t;
        
    } 
    cout<<endl;
    count++;
}
void LL::Delete(string nm)
{
    Node *p=first,*q=NULL;
    if(first->name==nm)
    {
        first = first->next;
        delete p;count--;
    }
    else
    {
        while(p!=NULL)
        {
            if(p->name==nm)
            {
                q->next=p->next;
                delete p;
                count--;
                break;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
    }
    if(p==NULL)
    cout<<"No such name exists in the student record\n";
    else
    cout<<"DELETED\n";

}
void LL::display()
{
    
    Node *p = first;
    if(p!=NULL)
    {
        for(int i=0;i<count;i++)
        {
            
            cout<<"Student "<<i+1<<endl;
            cout<<"USN: "<<p->usn<<endl;
            cout<<"Name: "<<p->name<<endl;
            cout<<"Branch: "<<p->branch<<endl;
            cout<<"SEM: "<<p->sem<<endl;
            cout<<"Ph no.: "<<p->phno<<endl;
            cout<<"------------------------------------\n";
            p=p->next;
        }
        cout<<"No. of nodes:"<<count<<endl;
    }
    else
        cout<<"Student record is empty\n";
}
int main()
{
    int ch;string del;
    LL ls;
    cout<<"LINKED LIST\n";
    while(1)
    {
        cout<<"------------------------------------\n";
        cout<<"1.Insert a student\n2.Delete a student\n3.Display student record\n4.Exit\n";
        cin>>ch;
        cin.ignore();
        switch (ch)
        {
        case 1:
            ls.insert();break;
        case 2:
            cout<<"Enter the student name:";getline(cin,del);
            ls.Delete(del);break;
        case 3:
            ls.display();break;
        case 4:
            cout<<"EXITING!";exit(0);   
        default:
            cout<<"Invalid choice! Try again.";            
        }
    }
}