#include<vector>
#include<iostream>
using namespace std;


// int _merge(vector<int> &vec,vector<int> &temp,int start,int mid,int end){
// 	int i=start;
// 	int k=mid;
// 	int j = start;
// 	int inv_count =0;
// 	//cout<<"_merge"<<start<<mid<<end<<'\n';
// 	while(i<=(mid)&& k<=(end)){
// 		if(vec[i]<vec[k]){
// 			temp[j++]=vec[i++];
// 		}	
// 		else{
// 			temp[j++]= vec[k++];
// 			cout<<i<<j<<'\n';
// 			if((j-i)>2){
// 				cout<<"Too chaotic";
// 			}
// 			inv_count +=(mid-i);
// 	//		cout<<inv_count<<'\n';

// 		}
// 	}
// 	while(i<=(mid)){
// 		temp[j++]= vec[i++];
// 	}
// 	while(k<=(end)){
// 		temp[j++] = vec[k++];
// 	}
// 	for(i=start;i<=end;i++){
// 		vec[i]=temp[i];
// 	//	cout<<vec[i]<<' ';
// 	}
	
// 	//cout<<inv_count<<'\n';
// 	return inv_count;
// }

// int _mergeSort(vector<int> &vec,vector<int> &temp,int start,int end){
// 	int mid,inv_count=0;

// 	if(end>start){
// 		mid =(start+end)/2;
// 		//cout<<start<<end<<mid<<"\n";
// 		inv_count = _mergeSort(vec,temp,start,mid);
// 		inv_count+= _mergeSort(vec,temp,mid+1,end);
			
// 		inv_count += _merge(vec,temp,start,mid,end);
// 		// if(inv_count>2){
// 		// cout<<"Too chaotic"<<'\n';
// 		// return -1;
// 		// }
// 	}
// 	return inv_count;
// }


// int mergeSort(vector<int> &vec){
// 	//cout<<"mergeSort"<<vec.size()<<'\n';
// 	vector<int> temp(vec.size());
// 	return _mergeSort(vec,temp,0,vec.size()-1);
// }

// int getinversions(vector<int> &vec){
// 	//cout<<"getinversions";
// 	return mergeSort(vec);
// }
int swap(int &v1,int &v2){
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}
int bubblesort(vector<int> &vec){
	int len = vec.size(),i,j=0;
	vector<int> number_of_bribes(len);
	number_of_bribes.resize(len);
	int swap_flag = true;
	int chaotic_flag = false;
	while(swap_flag){
		swap_flag = false;
		
		for(i=1;i<len;i++){
			// for(j=0;j<len;j++)
			// 	cout<<' '<<vec[j]<<' ';
			// cout<<'\n';
			if(vec[i-1]>vec[i]){
				//cout<<"swapping"<<vec[i-1]<<vec[i]<<'\n';
				number_of_bribes[(vec[i-1])-1]++;				
				if(number_of_bribes[vec[i-1]-1]>2){
					cout<<"Too chaotic\n";
					chaotic_flag = true;
					return -1;
				}
				swap(vec[i-1],vec[i]);
				swap_flag = true;
				// for(j=0;j<len;j++)
				// 	cout<<number_of_bribes[j]<<' ';
				// cout<<'\n';
				// cout<<number_of_bribes[vec[i]]<<"   ";
				// cout<<'\n';
				

			}
		}
	}
	for(i=0;i<len;i++){
		number_of_bribes[0]+=number_of_bribes[i];
		//cout<<number_of_bribes[i]<<' ';
		//cout<<vec[i];
	}	
	return number_of_bribes[0];
}


int getinversions(vector<int> &vec){
	return bubblesort(vec);
}

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,i,j,number_of_bribes=0,too_chaotic=0;
		cin>>n;
		vector<int> vec;
		vec.resize(n);
		for(i=0;i<n;i++)
			cin>>vec[i];
		number_of_bribes = getinversions(vec);
		if(number_of_bribes>0)
			cout<<number_of_bribes<<'\n';	
	// 	for(i=0;i<n;i++){
	// 		too_chaotic =0;
	// 		for(j=i+1;j<n;j++){
	// 			if(vec[i]>vec[j]){
	// 				number_of_bribes++;
	// 				too_chaotic++;
	// 				if(too_chaotic>2){
	// 					cout<<"too_chaotic\n";
	// 					break;
	// 				}
	// 			}
	// 		}
	// 		if(too_chaotic>2){
	// 			break;
	// 		}
	// 	}	
	// 	if(too_chaotic<2)
	// 		cout<<number_of_bribes<<"\n";
	}
}	