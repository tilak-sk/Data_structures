#include<iostream>
using namespace std;
int main()
{
    // string st;
    char *st= new char[100];
    int i,vow = 0,cons = 0;
    cout<<"Enter a sentence:\n";
    // getline(cin,st);
    gets(st);
 for(i=0;st[i]!='\0';i++)
    {
        if(st[i]<=90 && st[i]>=65)// upper case to lower case
            st[i]=st[i]+32;
        if(st[i]=='a'||st[i]=='e'||st[i]=='o'||st[i]=='i'||st[i]=='u')
            vow++;
        else if(st[i]>=97 && st[i]<=122 )
        cons++;
    }
    cout<<"no of vowels: "<<vow<<"\n";
    cout<<"no of consonants: "<<cons<<"\n";
    delete []st;
}

