#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
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
}
void display(Node *p)
{
    while (p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    
}
int maximum(Node *p)
{
    int m = INT_MIN;
    while(p)
    {
        if(p->data>m)
            m=p->data;
        p=p->next;
    }
    return m;
}
int main()
{
    int a[] = {10,80,30,40,50};
    create(a,5);
    display(first);
    cout<<"\nMaximum element in LL is "<<maximum(first);
    
}
