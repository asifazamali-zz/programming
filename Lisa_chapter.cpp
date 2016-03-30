#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
   int n,k;
   cin>>n>>k;
   vector<int> v(n);
   for(int i=0;i<n;i++)
	cin>>v[i];
   int special=0;
   int prepages=0;
   int curch=0;
   int endch=0;
   int numch=0;
   int curpages=0;
   for(int i=0;i<n;i++){
	numch=v[i];
	curch=0;
	endch=(v[i]>k)?k:v[i];
	while(numch>0){
		curpages+=1;
		//cout<<curch<<" "<<curpages<<" "<<endch<<" "<<special<<" "<<numch<<"\n";
	
 		if(curpages<=endch&&curpages>curch){
			special++;
		}
		curch=endch;
		numch=v[i]-endch;
		endch+=((numch)>k)?k:(numch);
		
	}
   }
   cout<<special<<"\n";
   return 0;
}	
