#include<iostream>

using namespace std;



int main(){
	int need [5][3];
	int total[] = {10,5,7};
	int available[3],new_available[3] , p , req[3];

	int allocated[5][3] = { { 0, 1, 0 }, 
                     		{ 2, 0, 0 }, 
                     		{ 3, 0, 2 }, 
                     		{ 2, 1, 1 }, 
                    		{ 0, 0, 2 } }; 
 
  	int max[5][3] = { { 7, 5, 3 }, 
                   	{ 3, 2, 2 }, 
                   	{ 9, 0, 2 }, 
                   	{ 2, 2, 2 }, 
                   	{ 4, 3, 3 } };
                   	
	// need matrix 
        for(int i = 0 ; i < 5 ; i++){
        	for(int j = 0 ; j < 3 ; j++){
        		need[i][j] = max[i][j] - allocated[i][j];
        	}
        }
        
        // available matrix
        available[0] = total[0];
        available[1] = total[1];
        available[2] = total[2];
        
        for(int i = 0 ; i < 5 ; i++){
        	for(int j = 0 ; j < 3 ; j++){
        		available[j] -= allocated[i][j];
        	}
        }
        
        cout<<available[0]<<" "<<available[1]<<" "<<available[2]<<endl;
        
        cout<<"process id\n";
        cin>>p;
        cout<<"enter resorces\n";
        for(int i = 0 ; i < 3 ; i++){
        	cout<<"enter resorces\n";
        	cin>>req[i];
        }
        
        for(int i = 0 ; i < 5 ; i++){
        	if(p == i){
        		if(req[0]<= need[i][0] && req[1] <= need[i][1] && req[2] <= need[i][2]){
        			if(req[0]<= available[0] && req[1] <= available[1] && req[2] <= available[2]){
        				availa
        			}	
        		}
        	}
        }
                   	
	return 0;
}
