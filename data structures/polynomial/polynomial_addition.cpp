#include<iostream>
#include<math.h>
using namespace std;
class Terms
{
    public:
    int coeff,exp,n;

};
class Polynomial
{
    public:
    Terms *ob;
    int n;
    Polynomial(int n)
    {
       this->n=n;
        ob = new Terms[n];
        
    }
    public:
    Polynomial addpoly(Polynomial p1, Polynomial p2) 
    {
        int i=0,j=0,k=0;
        Polynomial res(max(p1.n,p2.n));
        while (i<p1.n&&j<p2.n)
        {
            if (p1.ob[i].exp>p2.ob[j].exp)
                res.ob[k++] = p1.ob[i++];
            else if(p1.ob[i].exp<p2.ob[j].exp)
                res.ob[k++] = p2.ob[j++];
            else 
            {
                res.ob[k] = p1.ob[i];
                res.ob[k].coeff= p1.ob[i].coeff+p2.ob[j].coeff;
                k++;i++;j++;

            }
        }
         while (i<p1.n)
         res.ob[k++]=p1.ob[i++];
          while (j<p2.n)
         res.ob[k++]=p2.ob[j++];
        res.n=k;
        return res;
    }
    void display()
    {
        for(int i=0;i<n;i++)
        {
            if(ob[i].exp==0)
            cout<<abs(ob[i].coeff);
            else if(ob[i].coeff==1)
            cout<<"x^"<<ob[i].exp;
            else
            cout<<abs(ob[i].coeff)<<"x^"<<ob[i].exp;
            if (i < n-1){
            if(ob[i].coeff>0)
                cout << " + ";   
            else        
                cout << " - ";   
            }
        }
        cout<<endl;
    }
    
};
int main()
{
    
    int m,n;
    cout<<"Polynomial 1: no of non-zero terms\n";
    cin>>n;
    Polynomial p1(n);
    cout<<"Enter "<<n<<" coefficients and exponents respectively:\n";
    for(int i=0;i<n;i++)
    {
        cout<<(i+1)<<") coeff: ";
        cin>>p1.ob[i].coeff;
        cout<<" expo(x^(?)): ";
        cin>>p1.ob[i].exp;
    }
    cout<<"Polynomial 2: no of non-zero terms\n";
    cin>>m;
    Polynomial p2(m); 
    cout<<"Enter "<<m<<" coefficients and exponents respectively:\n";
    for(int i=0;i<m;i++)
    {
        cout<<(i+1)<<") coeff: ";
        cin>>p2.ob[i].coeff;
        cout<<" expo(x^(?)): ";
        cin>>p2.ob[i].exp;
    }
    p1.display();
    p2.display();
    Polynomial res = p1.addpoly(p1,p2);
    cout<<"Polynomial after addition\n";
    res.display();
}