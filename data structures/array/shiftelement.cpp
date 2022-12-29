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
        ar[i] = (i+1)*10;
    }
    void leftshift()

    {
    int temp = ar[0];
    for(int i=0;i<len-1;i++)
        ar[i]= ar[i+1];
        ar[len-1]=temp;
    
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
    ob.leftshift();
    

    ob.disp();
    
    
}