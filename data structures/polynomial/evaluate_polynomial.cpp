
#include<iostream>
#include<math.h>
using namespace std;
class Terms
{
    public:
    int coeff,exp,n;
};
int main()
{
    
    Terms *ob;
    int n,i,ev=0;
    cout<<"No of non zero terms\n";
    cin>>n;
    ob = new Terms[n];
    cout<<"Enter "<<n<<" coefficients and exponents respectively:\n";
    for(i=0;i<n;i++)
    {
        cout<<(i+1)<<") coeff: ";
        cin>>ob[i].coeff;
        cout<<" expo(x^(?)): ";
        cin>>ob[i].exp;
    }
    //represents the polynomial
    for(i=0;i<n;i++)
    {
        if(ob[i].exp!=0)
        cout<<ob[i].coeff<<"x^"<<ob[i].exp;
        // I have included the below statement(34) so that x^0 does not print which may look odd
        else
        cout<<ob[i].coeff;
        if (i < n-1)
        cout << " + "; 
    }
    cout<<endl;
    int x;
    cout<<"Enter value of x? ";
    cin>>x;
    for(i=0;i<n;i++)
        ev+= (ob[i].coeff*pow(x,ob[i].exp));

    cout<<"Evaluating expression: "<<ev<<endl;

    delete []ob;
}

