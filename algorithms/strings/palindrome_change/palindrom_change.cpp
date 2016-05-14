#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int main(){
 int T;
 cin>>T;
 cin>>ws;
 while(T--){
	string str;
 	getline(cin,str);
     	int len=str.size();
	//cout<<len<<"\n";
	int start=0,end=len-1;
	int ctr=0;
	while(start<end){
		ctr+=abs(str[start]-str[end]);
		start++;
		end--;
	}
	cout<<ctr<<"\n";
 }
 return 0;
}
