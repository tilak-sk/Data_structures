#include<iostream>
using namespace std;
int main()
{
    int i=1,ivalue,j=1;    
    cout<<"------------------------------\n";
    cout<<"j: "<<(j)<<"\n";
    int jvalue=j++;
    cout<<"jvalue = (j++): "<<(jvalue)<<"\n";
    cout<<"j: "<<(j)<<"\n";
    cout<<"j++: "<<(j++)<<"\n";
    cout<<"j: "<<(j)<<"\n";
    cout<<"------------------------------\n";
    cout<<"i: "<<(i)<<"\n";
    ivalue = ++i;
    cout<<"ivalue = ++i: "<<(ivalue)<<"\n";
    cout<<"++i: "<<(++i)<<"\n";
    cout<<"i: "<<(i)<<"\n";
    cout<<"------------------------------\n";

}