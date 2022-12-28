#include<iostream>
using namespace std;
int main()
{
    char *ch;int i=0;
    
    cout<<"Enter a sentence:\n";
    gets(ch);//reads complete sentence with spaces
    while(ch[i]!='\0')
    i++;
    cout<<"Length: "<<i<<endl;
}   