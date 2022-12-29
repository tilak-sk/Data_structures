#include<iostream>
using namespace std;
int main()
{
    char* st=new char[100];char t;
    int i,j;
    cout<<"Enter a string:\n";
    gets(st);
 for(i=0;st[i]!='\0';i++)
    {}
    i=i-1;
    for(j=0;j<i;j++,i--){
    t=st[i];
    st[i]=st[j];
    st[j]=t;
    }
    
    cout<<"reversed string: "<<st<<"\n";
    delete []st;

}