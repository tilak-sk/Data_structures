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
    cout<<endl;  
}
void insert(int x,int pos)
{
    Node *t,*p;
    if(pos==0)
    {
        t = new Node;
        t->data=x;
        t->next = first;
        first = t;
    }
    else if(pos>0)
    {
        p = first;
        for(int i=0;i<pos-1 && p;i++)
            p=p->next;
        if(p)
        {
            t = new Node;
            t->data=x;
            t->next = p->next;
            p->next = t;
        }
        

    }
};
int main()
{
    int a[] = {10,80,30,40,50};
    create(a,5);
    display(first);
    // insert(11,0);
    insert(20,2);display(first);
    // insert(55,5);
    

    
    
}