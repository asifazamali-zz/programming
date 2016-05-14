#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
 int T;
 string str;
 cin>>T;
 cin>>ws;
 vector <int> alph(26);
 while(T--){
	getline(cin,str);
 	fill(alph.begin(),alph.end(),0);
		
 	int sum=0;
	
	if(str.size()%2){
		cout<<"-1\n";
		continue;
	}
        string s1=str.substr(0,str.size()/2);
	string s2=str.substr(str.size()/2);
	for(int i=0;i<s1.size();i++)
		alph[s1[i]-97]++;
 	for(int i=0;i<s2.size();i++){
		if(alph[s2[i]-97]){
			alph[s2[i]-97]--;
		}
		else
			sum++;
        }
	cout<<sum<<"\n";		
		
 }

 return 0;
}
