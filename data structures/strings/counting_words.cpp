#include<iostream>
using namespace std;
int main()
{
    char*ch;
    int i,wc = 1;
    cout<<"Enter a sentence:\n";
    gets(ch);
 for(i=0;ch[i]!='\0';i++)
    {
        if(ch[i]==' ')
            wc++;
    }
    cout<<"no of words: "<<wc<<"\n";
    

}