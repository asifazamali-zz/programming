#include <iostream>
#include <vector>
using namespace std;

int isSortedArray(int A[],int n){
	if(n==0){
		return 1;
	}
	return (A[n-1]<A[n-2])?0:isSortedArray(A,n-1);
}

int main(){
	int A[] ={1,2,3,4,5,7,6,8,9};
	if(isSortedArray(A,9))
		cout<<"Sorted"<<endl;
	else
		cout<<"Unsorted"<<endl;
}