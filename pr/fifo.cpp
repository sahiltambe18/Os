#include<iostream>
#include<vector>
using namespace std;

void fifo(int frameSize , int *fRef , int refCount){
    vector<int> v (frameSize , -1);
    int pageFault = 0;
    for (int i = 0; i < refCount; i++)
    {
        int ref = fRef[i];
        int hit = 0;
        for (auto r : v)
        {
            if (r==ref)
            {
                hit = 1;
                break;
            }
        }
        
        if (!hit)
        {
            v[pageFault%frameSize] = ref;
            pageFault++;
        }
        for (auto j : v)
        {
            cout<<j;
        }
        if (hit)
        {
            cout<<"hit";
        }else{
            cout<<"miss";
        }
        
        
    }
    
}

int main( )
  {

return 0 ;
}