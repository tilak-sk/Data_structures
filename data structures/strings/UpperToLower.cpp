#include<iostream>
using namespace std;
int main()
{
    char *ch;int i;
    cout<<"Enter a word:\n";
    cin>>ch;
    for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]<=90 && ch[i]>=65)
            ch[i]=ch[i]+32;
    }
    cout<<ch<<"\n";


}