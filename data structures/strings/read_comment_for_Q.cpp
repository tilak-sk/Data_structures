//upper characters to lower and vice versa#include<iostream>
#include<iostream>
using namespace std;

int main()
{
    char *ch;int i;
    cout<<"Enter a sentence:\n";
    gets(ch);

    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]<=90 && ch[i]>=65)// upper case to lower case
            ch[i]=ch[i]+32;
        else if(ch[i]>=97 && ch[i]<=122)//lower case to upper case
            ch[i]=ch[i]-32;
    }
    cout<<ch<<"\n";
    

}