#include<stack>
#include<iostream>
#include<string>
using namespace std;
class convert
{
private:
string infix, postfix;
stack<char>st;
public:
    convert()
    {
        infix = "";
        postfix = "";
        input();
        InfixtoPostfix();
        cout<<"Postfix expression: "<<postfix<<endl;
    }
    void input()
    {
        cout<<"Enter a Infix expression:";
        getline(cin,infix);
    }
    bool isOperator(char x)
    {
        if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^')
            return true;
        else
            return false;
    }
    int precedence(char x)
    {
        if(x=='+'||x=='-')
            return 1;
        else if(x=='*'||x=='/')
            return 2;
        else if(x=='^')
            return 3;
        return -1;
    }
    void InfixtoPostfix()
    {
        int i;
        for (i=0;i<infix.length();i++)
        {
            if((infix[i]>='A'&&infix[i]<='Z')||(infix[i]>='a'&&infix[i]<='z'))
            postfix +=infix[i];
            else if(infix[i]=='(')
            st.push(infix[i]);
            else if(infix[i]==')')
            {
                while ((st.top()!='(')&&(!st.empty()))
                {
                    char temp = st.top();
                    st.pop();
                    postfix += temp;                    
                }
                if(st.top()=='(' )
                    st.pop();
                
            }
            else if(isOperator(infix[i]))
            {
                if(st.empty())
                st.push(infix[i]);
            }
            else
            {
                if(precedence(infix[i]) > precedence(st.top()))
                st.push(infix[i]);
                else if((precedence(infix[i]) == precedence(st.top()))&&(infix[i]=='^'))
                st.push(infix[i]);
                else
                {
                    while ((!st.empty())&&(precedence(st.top())>=precedence(infix[i])))
                    {
                        postfix +=st.top();
                        st.pop();                        
                    }
                    st.push(infix[i]);
                    
                }
            }
        }
    
        while (!st.empty())
        {
            char ch = st.top();
            st.pop();
            postfix += ch;        
        }
    }
};
int main()
{
    
    convert c;
    return 0;
}