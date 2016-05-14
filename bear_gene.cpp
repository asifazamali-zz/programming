#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool validity_check(map<char,int> dict,int limit){
	if(dict['A']<=limit && dict['G']<= limit && dict['C']<=limit && dict['T']<=limit)
		return true;
	else
		return false;
}
int main(){
	int size,length,out=999999;
	cin>>size;
	string str;
	cin>>str;
	int each_character_occurence = (size/4);
	//cout<< each_character_occurence<<"each_character_occurence\n";
	map<char,int> dict;
	int max_index =0;
	int i,N=str.length();
	for(i=N-1;i>=0;i--){
		dict[str[i]]++;
		bool result = validity_check(dict,each_character_occurence);
		//cout<< result <<endl;
		if(!(result)){
			max_index = i+1;
			dict[str[i]]--;
			//cout<<"breaking"<<endl;
			break;
		}
	}
	int min_index;
	for(min_index=-1;max_index<N && min_index<max_index && min_index<N-1 ;min_index++){
		//cout<<str[min_index+1];
		while(!validity_check(dict,each_character_occurence) && max_index<N){
			dict[str[max_index]]--;
			max_index++;
		}
		if(max_index>N || !validity_check(dict,each_character_occurence))
			break;

		length = max(0,max_index- min_index -1);
		if(out>length){
			out = length;
		}

		dict[str[min_index+1]]++;
		
	}
	cout<< out<< endl;
	return 0;
}