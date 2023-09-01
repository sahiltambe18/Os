#include<iostream>
#include <queue>
using namespace std;

struct Process{
	int id;
	int at;
	int bt;
	int wt;
	int tat;
};



int main(){

	int n ,total;
	int i = 0 ;
	int pos= 0;
	int count = 0;
	Process p[10] ,ep[10] , exe;
	
	
	cout<<"enter number of processes"<<endl;
	cin>>n;
	for(int j = 0; j<n ; j++){
		p[j].id = j;
		cout<<"enter arrival time of processes"<<endl;
		cin>>p[j].at;
		cout<<"enter burst time of process"<<endl;
		cin>>p[j].bt;
	}
	
	ep[0] = p[0];
	pos++;
	i++;
	total = ep[0].bt;
	
	for(int j = 0 ; j < total ; j++){
		exe = ep[0];
		exe.bt--;
		count++;
		
		
		if(exe.bt==0){
			//delete exe
		}
		
		if(p[i+1].at <= count){
			ep[pos++] = p[i++];
			for(int x = i ; x < n ; x++){
				if(p[x].at <= count){
					ep[pos++] = p[i++];
				}
			}
			//sort
		}
		
		
		
		
	}

//Process p = NULL;
int n = 5;

	for(int i = 0 ; i < n ; i++){
		cout<<"d";
		cin>>n;
	}
	return 0;
}
