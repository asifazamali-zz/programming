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
	getline(cin,str);
	int start=0;
	int end=str.size()-1;
	int pos=-1;
	int flag=1;
	while(start!=end){
		if(str[start]!=str[end]){
	//		cout<<str[start]<<str[end]<<start<<end<<"\n";
			if(pos!=-1){		
				cout<<(str.size()-pos-1)<<"\n";
				flag=0;
				break;
			}
			pos=start;
			end++;
		}
	if(!flag)
		break;
			
	start++;
	end--;
	}
	if(flag){
	if(pos==-1)
		cout<<"-1\n";
	else
		cout<<pos<<"\n";
	}	
 }	


 return 0;
}
