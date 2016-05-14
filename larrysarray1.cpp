#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int _merge(vector<int> &vec,vector<int> &temp,int start,int mid,int end){
	int i=start;
	int k=mid;
	int j = start;
	int inv_count =0;
	//cout<<"_merge"<<start<<mid<<end<<'\n';
	while(i<=(mid-1)&& k<=(end)){
		if(vec[i]<=vec[k]){
			temp[j++]=vec[i++];
		}	
		else{
			temp[j++]= vec[k++];
			//cout<<i<<k<<(mid-i)<<'\n';
			inv_count +=(mid-i);
	
		}
	}
	while(i<=(mid-1)){
		temp[j++]= vec[i++];
	}
	while(k<=(end)){
		temp[j++] = vec[k++];
	}
	for(i=start;i<=end;i++){
		vec[i]=temp[i];
	//	cout<<vec[i]<<' ';
	}
	// for(i=start;i<=end;i++)
	// 	cout<< vec[i]<<"  ";
	// cout<<'\n';
	//cout<<inv_count<<'\n';
	return inv_count;
}

int _mergeSort(vector<int> &vec,vector<int> &temp,int start,int end){
	int mid,inv_count=0;

	if(end>start){
		mid =(start+end)/2;
		//cout<<start<<end<<mid<<"\n";
		inv_count = _mergeSort(vec,temp,start,mid);
		inv_count+= _mergeSort(vec,temp,mid+1,end);
			
		inv_count += _merge(vec,temp,start,mid+1,end);
		// if(inv_count>2){
		// cout<<"Too chaotic"<<'\n';
		// return -1;
		// }
	}
	return inv_count;
}


int mergeSort(vector<int> &vec){
	//cout<<"mergeSort"<<vec.size()<<'\n';
	vector<int> temp(vec.size());
	return _mergeSort(vec,temp,0,vec.size()-1);
}

int getinversions(vector<int> &vec){
	//cout<<"getinversions";
	return mergeSort(vec);
}


int main(){
 int T,N;
 cin>>T;
 while(T--){
	cin>>N;
	int inversions=0;
	vector<int> v(N);
	for(int i=0;i<N;i++)
		cin>>v[i];
	inversions = getinversions(v);
	//cout<<inversions<<endl;
	if(inversions%2==0)
	cout<<"YES\n";
	else
	cout<<"NO\n";
 }
 return 0;
}
