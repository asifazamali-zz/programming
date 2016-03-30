#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
 int T,N;
 cin>>T;
 while(T--){
	cin>>N;
	int inversions=0;
	vector<int> v(N);
	for(int i=0;i<N;i++)
		cin>>v[i];
	for(int i=0;i<N;i++)
	 for(int j=i+1;j<N;j++){
	   if(v[i]>v[j])
		++inversions;
	}
	if(inversions%2)
	cout<<"YES\n";
	else
	cout<<"NO\n";
 }
 return 0;
}
