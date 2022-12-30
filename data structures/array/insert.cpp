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
        cout<<"insert: pos? ele?\n";
        int po,sr;
        cin>>po>>sr;
        
        for(int i=n-1;i>=po-1;i--)
        ar[i+1]=ar[i];
        ar[po-1]= sr;
        n++;
    
        cout<<n<<" Array elements after inserting\n";
        for (int i=0;i<n;i++)
            cout<<i+1<<")"<<ar[i]<<"\n";
        

    }
