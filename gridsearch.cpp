#include <iostream> 
#include <vector> 
#include <sstream>
using namespace std;

int gridSearch(vector<vector<int>> &matrix, int i,int j,vector<vector<int>> &grid,int r,int c){
	int k,l;
	//cout<<"gridSearch called\n"<<i<<j;
	for(k=0;k<r;k++){
		j=0;
		for(l=0;l<c;l++){
			if(matrix[i][j]!=grid[k][l]){
			//	cout<<matrix[i][j]<<grid[k][l]<<i<<j<<k<<l;
				return 0;
			}
			
			j++;

		}
		i++;

	}
	return 1;
}


int main(){
	int T,i,j;
	int found =0;
	string str;
	cin>>T;
	// string str("123");
	// stringstream ss(str);
	// int temp;
	// while(ss>>temp)
	// 	cout<<temp<<'\n';
	// cout<<"\n";
	while(T--){
		found =0;
		int R,C;
		cin>>R>>C;
		vector<vector<int>> matrix(R);
		for(i=0;i<R;i++){
			matrix[i].resize(C);
			//cout<<"enter string";
			cin>>str;
			for(j=0;j<C;j++){
				matrix[i][j]=int(str[j]-'0');
				//cout<<str[j]<<" ";
			}
			//ss.clear();

		}
	// for(i=0;i<R;i++){
	// 	for(j=0;j<C;j++){
	// 		cout<<matrix[i][j];
	// 	}
	// 	cout<<"\n";
	// }	
	 	int r,c;
		cin>>r>>c;
		vector<vector<int>> grid(r);
		for(i=0;i<r;i++){
			grid[i].resize(c);
			cin>>str;
			for(j=0;j<c;j++)
				grid[i][j]=int(str[j]-'0');
		}
		for(i=0;i<=R-r;i++){
			for(j=0;j<=C-c;j++){
				found = gridSearch(matrix,i,j,grid,r,c);
				if(found){
					cout<<"YES\n";
					break;
				}
			}
			if(found){
				break;
			}
		}
		if(!found)
			cout<<"NO\n";
	}


}
