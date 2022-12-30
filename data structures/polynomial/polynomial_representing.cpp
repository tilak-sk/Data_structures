// code to represent polynomial
#include<iostream>

using namespace std;
class Terms
{
    public:
    int coeff,exp,n;
};
int main()
{
    
    Terms *ob;
    int n,i;
    cout<<"No of non zero terms\n";
    cin>>n;
    ob = new Terms[n];
    cout<<"Enter "<<n<<"coeff and exponents respectively:\n";
    for(i=0;i<n;i++)
    {
        cout<<(i+1)<<") coeff: ";
        cin>>ob[i].coeff;
        cout<<" expo(x^(?)): ";
        cin>>ob[i].exp;
    }
    
    for(i=0;i<n;i++)
    {
        if(ob[i].exp!=0)
        cout<<ob[i].coeff<<"x^"<<ob[i].exp;
        else
        cout<<ob[i].coeff;
        if (i < n-1)
        cout << " + ";
        
    }
    delete []ob;
}

