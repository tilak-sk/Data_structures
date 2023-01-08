
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
    // for(i=0;i<n;i++)
    // {
    //     if(ob[i].exp!=0)
    //     cout<<ob[i].coeff<<"x^"<<ob[i].exp;
    //     // I have included the below statement(33) so that x^0 does not print which may look odd
    //     else
    //     cout<<ob[i].coeff;
    //     if (i < n-1)
    //     cout << " + "; 
    // } or more efficient way to display for differing signs
    for(int i=0;i<n;i++)
    {
        if(ob[i].exp==0)
            cout<<abs(ob[i].coeff);//absolute value i.e minus sign if found only value is printed
        else if(abs(ob[i].coeff)==1)
            cout<<"x^"<<ob[i].exp;
        else
            cout<<abs(ob[i].coeff)<<"x^"<<ob[i].exp;
        if (i < n-1)// why n-1 becoz  after printing last term any other sign further cannot be represented
        {
            if(ob[i+1].coeff>0)//why ob[i+1] beoz u should have knowledge of next terms's sign to print
                cout << " + ";   
            else        
                cout << " - ";   
        }
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

