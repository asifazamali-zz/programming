#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int main(){
	string str1,str2;
	getline(cin,str1);
	getline(cin,str2);
	vector<int> alph;
	alph.resize(26);
	int ctr=0;
	for(int i=0;i<str1.size();i++)
		alph[str1[i]-97]++;
	for(int i=0;i<str2.size();i++)
		alph[str2[i]-97]--;
	for(int i=0;i<26;i++){
		cout<<alph[i]<<" ";
		//ctr+= abs(alph[i]);
	}
	cout<<ctr<<"\n";
	return 0;
}
