#include<iostream>
using namespace std;
class Reverse_Array{
    int *ar,len=0;
    
    public:    
    void array()
    {
        len = 6;
        ar = new int[len];
        
        for(int i=0;i<len;i++)
        ar[i] = i+1;
    }
    void reverse()
    {
    int tar[len];
    int i,j=0;
    for(i=len-1;i>=0;i--){
        tar[i] = ar[j];
        j++;
    }
    for(i=0;i<len;i++)
    ar[i] = tar[i];
    }
    void disp()
    {
         for(int i=0;i<len;i++)
        cout<<" "<<ar[i];
        cout<<endl;
    }
    
};
int main()
{
    
    Reverse_Array ob;
    ob.array();
    ob.disp();
    ob.reverse();
    ob.disp();
    
    
}