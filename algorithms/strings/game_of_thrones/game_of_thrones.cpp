#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 string str;
 getline(cin,str);
 vector<int> alph(26);
 for(int i=0;i<str.size();i++)
	alph[str[i]-97]++;	
 int odd=0,even=0;
 for(int i=0;i<26;i++)
	if(alph[i]%2)
		odd++;
	else
		even++;
 if(odd==0||odd==1)
	cout<<"YES\n";
 else
	cout<<"NO\n";
	


 return 0;
}
