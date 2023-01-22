#include <iostream>
#include <stack>
using namespace std;
class Convert
{
    private:
    string infix;
    string postfix;
    stack<char> st;
public:
    Convert()
    {
        infix = "";
        postfix = "";
        input();
        InfixToPostfix();
        cout << "Postfix Expression : " << postfix << endl;
    }
    void input()
    {
        cout << "Enter a Infix Expression : ";
        getline(cin,infix);
    }
    bool isOperator(char c)
    {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
    return true;
    }
    else
    {
    return false;
    }
    }
    int precedence(char c)
    {
    if (c == '^')
    return 3;
    else if (c == '*' || c == '/')
    return 2;
    else if (c == '+' || c == '-')
    return 1;
    else
    return -1;
    }
    void InfixToPostfix()
    {
    for (int i = 0; i < infix.length(); i++)
    {
    if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >=
    'a' && infix[i] <= 'z'))
    {
    postfix += infix[i];
    }
    else if (infix[i] == '(')
    {
    st.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
    while ((st.top() != '(') && (!st.empty()))
    {
    char temp = st.top();
    st.pop();
    postfix += temp;
    }
    if (st.top() == '(')
    {
    st.pop();
    }
    }
    else if (isOperator(infix[i]))
    {
    if (st.empty())
    {
    st.push(infix[i]);
    }
    else
    {
    if (precedence(infix[i]) > precedence(st.top()))
    {
    st.push(infix[i]);
    }
    else if ((precedence(infix[i]) ==
    precedence(st.top())) && (infix[i] == '^'))
    {
    st.push(infix[i]);
    }
    else
    {
    while ((!st.empty()) && (precedence(infix[i])
    <= precedence(st.top())))
    {
    postfix += st.top();
    st.pop();
    }
    st.push(infix[i]);
    }
    }
    }
}
while(!st.empty())
{
char ch = st.top();
st.pop();
postfix += ch ;
}
}
};
int main()
{
Convert c;
return 0;
}

