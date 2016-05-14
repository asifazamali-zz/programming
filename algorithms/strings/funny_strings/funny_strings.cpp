#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(){
 int T;
 cin>>T;
 cin>>ws;
 while(T--){
	string str;
	int flag=0;
 	getline(cin,str);
	int N=str.size();
	for(int i=1;i<str.size();i++){
		if(abs(str[i]-str[i-1])!=abs(str[N-i-1]-str[N-i]))
		{
			//cout<<str[i]<<str[i-1]<<str[N-i-1]<<str[N-i]<<"\n";
			flag=1;
			break;
		}

	}			
	if(flag==1)
		cout<<"Not Funny"<<"\n";
	else
		cout<<"Funny"<<"\n";
 
 }


 return 0;
}
