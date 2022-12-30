#include<iostream>
using namespace std;
class Reverse_Array{
    int *ar,len=0;
    
    public:    
    void array()
    {
        len = 5;
        ar = new int[len];
        
        for(int i=0;i<len;i++)
        ar[i] = i+1;
    }
    void reverse()
    {
    int temp;
    int j =len-1;
    for(int i=0;i<j;i++)
    {
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
        j--;
    }
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