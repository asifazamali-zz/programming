#include <iostream>
using namespace std;


int getMaxConnectedComponents(int input[][5],int directions[][2],int size,int &maxsize,int can_enter[][5],int i,int j,int L,int C){
	if(i>=L || j>=C || i<0 || j<0 || can_enter[i][j])
		return 0;
	
	size++;
	cout<<i<<j<<size<<endl;
	can_enter[i][j]=1;
	if(maxsize<size){
		maxsize = size;
	}
	for(int i=0;i<8;i++){
		int newx = i+directions[i][0];
		int newy = j+directions[i][1];
		if(newx<L && newy<C && newx>=0 && newy>=0 && input[newx][newy])
					getMaxConnectedComponents(input,directions,size,maxsize,can_enter,newx,newy,L,C);

	}

}

int main(){
	int directions[][2]= {{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1},{1,0},{-1,0}};
	int input[][5]={
		{1,1,0,0,0},
		{0,1,1,0,0},
		{0,0,1,0,1},
		{1,0,0,0,1},
		{0,1,0,1,1}
	};
	int maxsize=0;
	int can_enter[][5]={
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
		{0,0,0,0,0}
	};
	int i,j,size=0,L=5,C=5;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			getMaxConnectedComponents(input,directions,size,maxsize,can_enter,i,j,L,C);
		}
	}
	cout<<maxsize<<endl;
	return 0;
}