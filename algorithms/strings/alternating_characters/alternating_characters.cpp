#include<iostream>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

int main(){
  int T;
  string str;
  int ctr;
  char ch='\0';
  cin>>T;
  cin>>ws;
  while(T--){
  ctr=0;
  getline(cin,str);
  ch=str[0];
  for(int i=0;i<str.size();i++){
	if(str[i]!=ch){	
		ctr--;
		ch=str[i];
	}
	ctr++;
		
  }
 	cout<<--ctr<<"\n";
  }
  return 0;
}
