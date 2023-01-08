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
    cout<<"Enter "<<n<<" coeff and exponents respectively:\n";
    for(i=0;i<n;i++)
    {
        cout<<(i+1)<<") coeff: ";
        cin>>ob[i].coeff;
        cout<<" expo(x^(?)): ";
        cin>>ob[i].exp;
    }
    
    // for(i=0;i<n;i++)
    // {
    //     if(ob[i].exp!=0)
    //     cout<<ob[i].coeff<<"x^"<<ob[i].exp;
    //     else
    //     cout<<ob[i].coeff;
    //     if (i < n-1)
    //     cout << " + ";
        
    // }OR
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

    delete []ob;
}

