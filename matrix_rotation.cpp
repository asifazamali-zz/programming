#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long int ll;
int matrix_rotate(int status,ll &s1,ll &s2,vector<vector<ll> > &matrix,int i,int j,int N,int M,int R,vector<ll> &rot1,vector<ll> &rot2){
    int c;
    int k=0,l=0;
    int temp=R;
    switch(status){
        case 0:
	    
	    while(temp--){
            rot1[k]=matrix[i][i+k];	    
	    k++;
            }
            c=i;
            while((c+R)<=j){
                   matrix[i][c]=matrix[i][c+R];
                   c++;
            }
    //cout<<"s1 "<<s1<<" s2 "<<s2<<endl;
            break;
        case 1:
            c=M-i-R;
            while(temp--){		
            rot2[k]=matrix[c][i];
	    cout<<"case 1 "<<rot2[k]<<"\n";
	    k++;
	    c++;
            //cout<<s2<<endl;
	    }
	    c--;
            while((c-R)>i){
                matrix[c][i]=matrix[c-R][i];
                c--;
            }
	    temp=R;
	    while(temp--){
            matrix[c][i]=rot1[l];
	    l++;
            c--;
            }
            break;
        case 2:
            c=N-i-R;
	    while(temp--){
            rot1[k]=matrix[M-i-1][c];
	    cout<<rot1[k]<<"\n";	
            c++;
	    k++;
	    //cout<<s1<<endl;
            }
	    cout<<"case 2\n"; 
	    while((c-1)>i){
                matrix[M-i-1][c]=matrix[M-i-1][c-R];
		cout<<matrix[M-i-1][c]<<"\n";
                c--;
            }
	    temp=R;
	    while(temp--){
            matrix[M-i-1][c]=rot2[l];
	    c++;
	    l++;
            }
	    break;
        case 3:
            c = i;
	    while(temp--){
	    	rot2[l]=matrix[c][N-i-1];
		cout<<"case 3"<<rot2[l]<<"\n";
		l++;
		c++;
	    }
	    c=c-R;
            while((c+R)<=(M-1-i)){
                matrix[c][N-i-1]=matrix[c+R][N-i-1];
                c++;
            }
	    temp=R;
	    while(temp--){
            matrix[c-1][N-i-1]=rot1[R-k-1];
	    k++;
	    c++;
            }
	    c = N-1-R;
	    l=0;
	    temp=R;
	    while(temp--){
	    	matrix[i][c]=rot2[l];
		l++;
		c++;
	    }
	    break;
        default:
            break;
    }
    return 0;
}
int showMatrix(vector<vector<ll> > matrix){
     for(auto it=matrix.begin();it!=matrix.end();it++){
	for(auto iit=it->begin();iit!=it->end();iit++){
		cout<<*iit<<" ";
     }
	cout<<"\n";
    }
	cout<<"\n";
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M,N,R;
    cin>>M>>N>>R;
    int start=0;
    int end=N-1;
    int i=0;
    vector<vector<ll> > matrix(M);
    vector<ll> rot1(R);
    vector<ll> rot2(R);
    //rot1[0]=1; 
    for(int i=0;i<M;i++){
        matrix[i].resize(N);
        for(int j=0;j<N;j++){
           cin>>matrix[i][j];
        }
    }
    
    while((end-start)>=1){
        ll s1=matrix[i][i];
        ll s2=matrix[i][M-i-1];
        matrix_rotate(0,s1,s2,matrix,start,end,N,M,R,rot1,rot2);
	showMatrix(matrix);
	matrix_rotate(1,s1,s2,matrix,start,end,N,M,R,rot1,rot2);
	showMatrix(matrix);
		
        matrix_rotate(2,s1,s2,matrix,start,end,N,M,R,rot1,rot2);
       	showMatrix(matrix);
	matrix_rotate(3,s1,s2,matrix,start,end,N,M,R,rot1,rot2);
	showMatrix(matrix);
			
        start++;
        end--;
	cout<<"\n\n";
    }
  
//    cout<<endl;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cout<<matrix[i][j]<<' ';

        }
        cout<<endl;
    

    }
    return 0;
}

