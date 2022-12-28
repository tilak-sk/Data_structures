#include<iostream>
using namespace std;
int main()
{
    int *ar,n;
    cout<<"enter array size \n";
    cin>>n;
    cout<<"array size: "<<n<<endl;
    ar = new int[n];
    cout<<n<<" Array elements?\n";
    for (int i=0;i<n;i++)
        cin>>ar[i];
    cout<<"Del: pos?\n";
    int po;
    cin>>po;
     
    for(int i=po-1;i<n-1;i++)
    ar[i]=ar[i+1];
    
    n--;
   
    cout<<n<<" Array elements after deleting\n";
    for (int i=0;i<n;i++)
        cout<<i+1<<")"<<ar[i]<<"\n";
    

}
