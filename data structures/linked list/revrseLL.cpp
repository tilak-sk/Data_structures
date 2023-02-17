#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    void deallocate()
    {
        delete next;
    }
}*first=NULL; 
void create(int a[],int n)
{
    Node *t,*last;
    int i;
    first = new Node;
    first->data=a[0];
    first->next=NULL;
    last=first;
    for(i=1;i<n;i++)
    {
        t = new Node;
        t->data=a[i];
        t->next=NULL;
        last->next=t; 
        last=t;
    }
    // delete t;
}
void display(Node *p)
{
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }cout<<endl;
    
}
void reverse()
{
    Node *p,*q,*r;
    q=r=NULL;
    p=first;
    while(p)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    delete p,q,r;
}
void deallocate()
{
    delete first;
    Node ob;ob.deallocate();
}
int main()
{
    int a[] = {10,20,30,40,50};
    create(a,5);
    display(first);
    reverse();display(first);
    deallocate();

    
    
}
