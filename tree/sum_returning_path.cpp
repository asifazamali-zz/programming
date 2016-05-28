#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct tree{
	int val;
	tree *left;
	tree *right;
	tree(int x):val(x),left(NULL),right(NULL){};
};

int insert(tree **head,tree *newnode){
	if(*head == NULL){
		*head = newnode;
		return 0;
	}
	if((*head)->val < newnode->val){
		if((*head)->right)
			insert(&(*head)->right,newnode);
		else
			(*head)->right = newnode;
	}
	else{
		if((*head)->left){
			insert(&(*head)->left,newnode);
		}
		else
			(*head)->left = newnode;
	}
	return 0;
}

int print_tree(tree *head){
	queue<tree *> q;
	q.push(head);
	while(!q.empty()){
		tree *temp = q.front();
		q.pop();
		cout<<temp->val<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return 0;
}

int sum_returning_path(tree *head,int sum,int data,bool &flag){
	int left=0,right =0;
	if(head == NULL)
		return 0;
	sum+=head->val;
	//cout<<"flag:"<<flag<<" sum:"<<sum<<endl;
	
	if(sum == data){
		//cout<<"match found"<<endl;
		flag = false;
		return 1;
	}
	if(flag){
		int left =sum_returning_path(head->left,sum,data,flag);
		//cout<<"left"<<head->val<<" "<<left<<" "<<flag<<endl;
		//return res;
		//return 0;
	}
	else
		return 1;
	if(flag){
		//cout<<head->val<<" ";
		
		int right = sum_returning_path(head->right,sum,data,flag);
		//cout<<"right"<<head->val<<" "<<right<<endl;
		return (left+right);
		
		//cout<<" "<<flag<<endl;
		//return 0;
	}
	else
		return 1;
	//cout<<"returning"<<left<<" "<<right<<endl;
	//return (left+right);
}




int main(){
	tree *head = NULL;
	tree *temp = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		temp = new tree(i);
		insert(&head,temp);
	}
	print_tree(head);
	cout<<endl;
	bool flag = true;
	int left = sum_returning_path(head->left,head->val,101,flag);
	int right = sum_returning_path(head->right,head->val,101,flag);
	if(left || right)
		cout<<'1'<<endl;
	else
		cout<<'0'<<endl;
	return 0;
}