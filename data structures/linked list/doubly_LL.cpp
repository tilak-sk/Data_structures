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
    void insert(int x)
    {
        t=new Node;
        t->data=x;
        t->next=t->prev=NULL;
        if(first==NULL)
            first=last=t;
        else
        {
            last->next=t;
            t->prev=last;
            last=t;
        }
        count++;
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
    void insertPos(int x, int pos)
    {
        if(pos<=0 || pos>count+1)
            cout<<"Invalid position\n";
        else if(pos==1)
            insertFirst(x);
        else if(pos==count+1)
            insert(x);
        else
        {
            t = new Node;
            t->data = x;
            t->next = t->prev = NULL;
            Node *p=first;
            for(int i=0; i<pos-2;i++)
                p=p->next;
            t->prev=p;
            t->next=p->next;
            p->next->prev=t;
            p->next=t;
            count++;
        } 
    }
    void deleteFirst()
    {
        if(count==0)
        {
            cout<<"Nothing to delete List is empty\n";
            return;
        }
        if(first->next!=NULL)
        {
            Node *p=first;
            first=first->next;
            first->prev=NULL;
            delete p;
        }
        else
        delete first;
        count--;
    }
    void deletePos(int pos)
    {
        if(count==0)
        {
            cout<<"Nothing to delete List is empty\n";
            return;
        }
        if(pos==1)
        deleteFirst();
        else if(pos<1 || pos>count)
            cout<<"Invalid position\n";
        else if(pos==count) 
        {
            
            Node *p=last;
            last=last->prev;
            last->next=NULL;
            count--; 
            delete p;
        }
        else
        {
            Node *p=first;
            for(int i=0; i<pos-1; i++)
                p=p->next;
            p->prev->next=p->next;
            p->next->prev=p->prev;
            count--;
            delete p;
        }
    }
    void display()
    {
        if(count==0)
        {
            cout<<"List is empty\n";
            return;
        }
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
    ls.insert(20);
    ls.insert(30);
    ls.insert(50);
    ls.insertFirst(10);
    ls.insertPos(40,4);
    ls.insertPos(60,6);
    ls.display();
    ls.deleteFirst();
    ls.display();
    ls.deletePos(4);
    ls.display();
}