#include<vector>
#include<algorithm>
#include<iostream>

typedef long long int ll;
using namespace std;
int fill(vector<ll> &v,vector<vector<ll>> &matrix,int i,int j,int M,int N){
   int ind=0,l=i,k=j;
   while(k<N){
     v[ind]=matrix[i][k];
     k++;
     ind++;
   }
   ind--; // for reversal of pointer
   k--;
   while(l<M){
     v[ind]=matrix[l][N-1];
     l++;
     ind++;
   }
   ind--;
   while(k>=i){
     v[ind]=matrix[M-1][k];
     ind++;
     k--;
   }
   ind--;
   l--;
   while(l>j){
     v[ind]=matrix[l][i];
     ind++;
     l--;
   }
   return 0;  

}
int shift_put(vector<ll>&v,vector<vector<ll>>&matrix,int i,int j,int M,int N){
 int ind=0,k=j,l=i;
 while(k<N){
   matrix[i][k]=v[ind];
   ind++;
   k++;
 }
 ind--;
 k--;
 while(l<M){
   matrix[l][N-1]=v[ind];
   ind++;
   l++;
 }
 ind--;
 while(k>=i){
   matrix[M-1][k]=v[ind];
   ind++;
   k--;
 }
 ind--;
 l--;
 while(l>j){
   matrix[l][i]=v[ind];
   ind++;
   l--;
 }
 return 0;
}
int shift(vector<ll> &v,int R,int size){
 vector<ll> m(R);
 int temp=R;
 int i=0;
 while(temp--){
 	m[i]=v[i];
        i++;
 }
 i=0;
 while(i+R<size){
 	v[i]=v[i+R];
	i++;
 }
 int j=0; 
 while(R--){
	v[i]=m[j];
	i++;
	j++;
 }
}


int main(){
 int M,N,R;
 cin>>M>>N>>R;
 int size=2*M+2*N-4;
 vector<ll> row(size);
 vector<vector<ll>> matrix(M);
 for(int i=0;i<M;i++){
   matrix[i].resize(N);
   for(int j=0;j<N;j++){
 	cin>>matrix[i][j];
   }
 }
 int starti=0,startj=0,endi=M,endj=N;
 while(starti<endi&& startj<endj){
 size=2*(endi-starti)+2*(endj-startj)-4;
 row.resize(size);
 fill(row,matrix,starti,startj,endi,endj);
 //cout<<row.size()<<"\n";
 //for(int i=0;i<row.size();i++)
//	cout<<row[i]<<" ";
 shift(row,R%size,size);
 //cout<<"\n"; 
 //for(int i=0;i<row.size();i++)
//	cout<<row[i]<<" ";
 //cout<<"\n"; 
 shift_put(row,matrix,starti,startj,endi,endj);
 starti++;
 startj++;
 endi--;
 endj--;
 }
for(int i=0;i<M;i++){
   for(int j=0;j<N;j++){
 	cout<<matrix[i][j]<<" ";

   }
   cout<<"\n";
 } 
 
return 0;
}
