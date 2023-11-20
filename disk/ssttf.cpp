#include<iostream>
#include<vector>
using namespace std;

int nearest(int seq[] , int n , int current, vector<bool> visited){
    int min = INT_MAX;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        int diff = abs(current-seq[i]);
        if(diff < min && !visited[i]){
            min = diff;
            ans = i;
        }
    }
    return ans;
}

int main( )
  {
    int sequence[] = {176, 79, 34, 60, 92, 11, 41, 114};
    int n = 8;
    int current = 50;
    vector<bool> vis(n,false);

    
    bool quit = true;
    do{
        quit = true;
        int next = nearest(sequence , n , current , vis);
        cout<<"next is "<<sequence[next]<<" "<<abs(current - sequence[next])<<" \n";
        vis[next] = true;
        current = sequence[next] ;

        for (auto i : vis)
        {
            if (i==false)
            {
                quit = false;
            }
            
        }
        
        
    }while(!quit);
    

return 0 ;
}