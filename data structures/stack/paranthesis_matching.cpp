/* assume an array of characters representing expression
((a+b)*(c-d))
*/
#include<iostream>
#include<string.h>
using namespace std;
class Stack
{
public:
 char *st;
 int size;
 int top;
 Stack()
 {
    size=10;top=-1;
    st=new char[size];
 }
 Stack(string exp)
 {
    size=exp.length();
    top=-1;
    st=new char[size];
 }
 int isBalance(string exp);
 void push(char x);
 int pop();
 int peek(int index);
 int stacktop();
 int isEmpty();
 int isFull();
 void Display();
};

void Stack::push(char x)
{
 if(isFull())
 cout<<"Stack Overflow"<<endl;
 else
 {
 top++;
 st[top]=x;
 }
}

int Stack::pop()
{
 int x=-1;
 if(isEmpty())
 cout<<"Stack underlfow"<<endl;
 else
 {
 x=st[top];
 top--;
 }
 return x;
}

int Stack::peek(int index)
{
 int x=-1;
 if(top-index+1 < 0)
        cout<<"Invaid index\n";

    else
        x = st[top-index+1];
    return x;
    
}

int Stack::stacktop()
{
 if(isEmpty())
 return -1;
 return st[top];
}

int Stack::isFull()
{
 return top==size-1;
}

int Stack::isEmpty()
{
 return top==-1;
}

void Stack::Display()
{
 for(int i=top;i>=0;i--)
 cout<<pop()<<" ";
 cout<<endl;
}
int Stack ::isBalance(string exp) // check braces are correctly enclosed
{
    for (int i=0; i<size;i++)
    {
        if(exp[i]=='(')     
        push(st[i]);
        else if (exp[i]==')')
        {
            if(isEmpty())
                return 0;
            else
            pop();
        }
    }
    if(isEmpty())
        return 1;
    else
        return 0;
}
int main()
{
    // Stack ob;
    string exp="((a+b)*(c-d))";
    Stack ob(exp);// sending character pointer array
    if(ob.isBalance(exp))
        cout<<"\nExpression's braces are correctly enclosed\n";
    else
        cout<<"\nExpression's braces are incorrectly enclosed\n";
}
