#include<iostream>
using namespace std;
int main()
{
    char*st1= new char[100];
    char*st2 = new char[100];
    string s1,s2;
    int l1,l2,i,j,alp;
    cout<<"Enter two strings:\n";
    gets(st1);
    gets(st2);
    s1=st1;
    s2=st2;
    //covert to lower case so that comparison becomes easier
    for(l1=0;st1[l1]!='\0';l1++){
        if(st1[l1]<=90 && st1[l1]>=65)
            st1[l1]=st1[l1]+32;
    }
    for(l2=0;st2[l2]!='\0';l2++){
        if(st2[l2]<=90 && st2[l2]>=65)
            st2[l2]=st2[l2]+32;
    }

    
    for(i=0,j=0;(i<l1||j<l2);i++,j++)//this can also be written for(i=0,j=0;(st1[i]!='\0'||st2[j]!='\0');i++,j++)
    {
        if(st1[i]==st2[j])
        {
            alp=1;
        continue;
        }
        else {
            if(st1[i]>st2[j])
            {
                cout<<"Strings according to alphabetical order: \n"<<s2<<"\n"<<s1<<"\n";
                 alp=0;
                break;
            }
            else
            {
                cout<<"Strings according to alphabetical order: \n"<<s1<<"\n"<<s2<<"\n";
                 alp=0;
                break;
            }
        }
    }
    if(alp)
    cout<<"Both Strings are same: "<<s1<<" "<<s2<<"\n";
   
    delete []st1;
    delete []st2;

}