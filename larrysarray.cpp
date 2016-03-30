#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool rules(vector<int> &v,int i){
	bool result;
	if(v[i]<v[i+1]){
	    if(v[i+1]<v[i+2])
		result=true;
	    else if(v[i+1]>v[i+2]&&v[i+2]<v[i])
		result=false;
 	    else
		result= true;
	}
	else {
		if(v[i+1]>v[i+2])
			result =false;
		else if(v[i+1]<v[i+2]&&v[i+2]<v[i])
			result= false;
		else
			result= true;
	}
	//cout<<"result: "<<result;
	return result;
}
bool check(vector<int> &v,int i,bool &NS){
//	cout<<i<<"check \n";
	if(NS==false && rules(v,i)==false)
		NS=true;
	else if(NS==true && rules(v,i)==false)
		NS=false;
	else if(NS==false && rules(v,i)==true)
		NS=false;
	else
		NS=true;
return false;
}	

int main(){
 int T,N;
 cin>>T;
 while(T--){
  cin>>N;
  vector<int> v(N);
  int i=0;
  bool NS=true;
  int temp=N;
  while(temp--){
	cin>>v[i];
	i++;
  }
 // for(int i=0;i<N;i++)
//	cout<<v[i];
  for(i=0;i<=(N-3);i++){
   check(v,i,NS);
 //  cout<<"inside for\n";
  }  
  if(NS==true)
	cout<<"NO\n";
  else
 	cout<<"YES\n";
 }
 return 0;
}
