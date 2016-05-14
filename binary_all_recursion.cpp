#include <iostream>
#include <vector>
using namespace std;
int A[3]= {1,1,1};

int printAll(int n){
	if(n<1){
		for(int i=2;i>=0;i--)
			cout<<A[i];
		cout<<'\n';
	return 0;
	}
	
	A[n-1]=0;
	printAll(n-1);
	A[n-1]=1;
	printAll(n-1);
	return 0;

}

int main(){
	int n=3;
	printAll(n);
}