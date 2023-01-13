#include <iostream>
using namespace std;

class Stack
{
private:
 int *st;
 int size;
 int top;
public:
 Stack(){size=10;top=-1;st=new int[size];}
 Stack(int size){this->size=size;top=-1;st=new int[this->size];}
 void push(int x);
 int pop();
 int peek(int index);
 int stacktop();
 int isEmpty();
 int isFull();
 void Display();
};

void Stack::push(int x)
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

int main()
{
 Stack stk(5);
 stk.push(1);
 stk.push(2);
 stk.push(3);
 stk.push(4);
 stk.push(5);
 stk.push(6);
cout<<"Stack top: "<<(char)stk.stacktop()<<endl; // topmost element of the stack
 cout<<"peek(1)"<<stk.peek(1)<<endl;// e stays at top since e is what u can peek from the above 1st position
 cout<<"peek(5)"<<stk.peek(5)<<endl;// u have pushed a first it stays at last positon
 cout<<"peek(6)"<<stk.peek(6)<<endl;
 stk.Display();



 return 0;
}
