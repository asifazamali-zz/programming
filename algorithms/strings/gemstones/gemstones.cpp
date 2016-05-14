#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){

  int T;
  int gctr=0;
  cin>>T;
  cin>>ws;
  vector<vector<int>> alph(T);
  int i=0;
  int temp=T;  
  while(temp--){
	string str;
	alph[i].resize(26);
	getline(cin,str);
	for(int k=0;k<str.size();k++){
     		alph[i][(str[k]-97)]++;
	}
	i++;
 }
 for(int i=0;i<26;i++){
	int ctr=0;
   for(int k=0;k<T;k++){	
	//cout<<alph.size()<<" "<<alph[k].size();
	//cout<<alph[k][i];
	if(alph[k][i]==1)	
		ctr++;
	}
	//cout<<"\n";
	if(ctr==T)
		gctr++;
}
 cout<<gctr<<"\n";
 return 0;
}			
