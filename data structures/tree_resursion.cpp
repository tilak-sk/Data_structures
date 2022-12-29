#include<iostream>
using namespace std;
void rec3(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        rec3(n-1);
        rec3(n-1);        
    }
}
int main()
{
        rec3(3);
}