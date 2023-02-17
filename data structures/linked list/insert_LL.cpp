#include<iostream>
using namespace std;
class LL;
class Node
{
    private:
    int data;
    Node *next;
    friend class LL;
};
class LL
{
    Node *first,*p,*t,*q;
    int count;
    public:
    LL()
    {
        first=NULL;
        t=p=q=NULL;
        count=0;
    }
    void Insert(int x);
    void Insert(int x,int pos);
    void Display();
    int Delete(int pos);
};
void LL::Insert(int x)
{
    t = new Node;
    if(first==NULL)
    {

        first=t;
        first->data=x;
        first->next=NULL;
    }
    else
    {
        t->data=x;
        t->next=first;
        first = t;
    }
    count++;
}
void LL::Display()
{
    p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void LL::Insert(int x, int pos)
{
    p=first;
    for(int i=0;p!=NULL && i<pos-2;i++)
        p=p->next;
    t = new Node;
    t->data=x;
    t->next=p->next;
    p->next=t;
}
int LL::Delete(int pos)
{
    p=first;int x=-1;
    if(p==NULL||pos>count)
    cout<<"LIST is empty or Invalid position\n";
    else
    if(pos==1)
    {
        first=first->next;
        x=p->data;
        delete p;count--;
        return x;
    }
    else
    {
        for(int i=0;i<pos-1&&p;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;count--;
        return x;
    }
    
    return x;
}
int main()
{
    LL ob;
    ob.Delete(3);
    ob.Insert(50);
    ob.Insert(40);
    ob.Insert(30);
    ob.Insert(20);
    ob.Insert(10);
    ob.Display();
    ob.Insert(33,3);
    ob.Display();
    ob.Delete(3);
    ob.Delete(6);
    ob.Display();

}