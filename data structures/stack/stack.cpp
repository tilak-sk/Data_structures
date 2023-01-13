#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
    T *st;int size, top;
public:
    Stack()
    {
        size = 10;top =-1;
        st = new T[size];
    }
    Stack(int size)
    {
        this->size=size;
        top =-1;
        st = new T[size];
    }
    void push(T x);
    T pop();
    T peek(int index);
    int stacktop(),isFull(), isEmpty();
    void display();
};
template<class T>
void Stack<T>::push(T x)
{
    if(isFull())
    cout<<"Stack overflow\n";
    else
    {
        top++;st[top] = x;
    }
}
template<class T>
T Stack<T>::pop()
{
    T x=-1;
    if(isEmpty())
    cout<<"Stack underflow\n";
    else
    {
        x=st[top];
        top--;
    }
    return x;
}
template<class T>
T Stack<T>::peek(int index)
{
    T x = -1;
    if(top-index+1 < 0)
        cout<<"Invaid index\n";

    else
    {
        x = st[top-index+1];
        return x;
    }
    return NULL;

}
template<class T>
int Stack<T>::stacktop()
{
 if(isEmpty())
 return -1;
 return st[top];
}
template<class T>
int Stack<T>::isFull()
{
 return top==size-1;
}
template<class T>
int Stack<T>::isEmpty()
{
 return top==-1;
}
template<class T>
void Stack<T>::display()
{
 for(int i=top;i>=0;i--)
//  cout<<st[i]<<" ";
 cout<<pop()<<" ";
 cout<<endl;
}
int main()
{
 Stack<char> stk(5);
 stk.push('a');
 stk.push('b');
 stk.push('c');
 stk.push('d');
 stk.push('e');
 stk.push('f');// overflow becoz size of stack is 5 tats all it can fill
 cout<<"Stack top: "<<(char)stk.stacktop()<<endl; // topmost element of the stack
 cout<<"peek(1)"<<stk.peek(1)<<endl;// e stays at top since e is what u can peek from the above 1st position
 cout<<"peek(5)"<<stk.peek(5)<<endl;// u have pushed a first it stays at last positon
 cout<<"peek(6)"<<stk.peek(6)<<endl;
 stk.display();

 return 0;
}