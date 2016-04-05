#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<ctype.h>
#include<math.h>
using namespace std;
int main(){
 char str[1000];

 cin.getline(str,1000);
 cout<<str;
 vector<int> alph;
 alph.resize(26);
 int sum=0;
 for(int i=0;i<str.size();i++){
     if(str[i]!=' '){
     if(!alph[tolower(str[i])-97]){
	alph[tolower(str[i])-97]+=1;
	sum++;
     }
    }
 } 
 if(sum==26)
	cout<<"panagram"<<"\n";
 else
	cout<<"not panagram\n";	


/// return 0;
}
