#include <iostream>
#include <vector>
#include <stack>
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
	if((*head)->val <newnode->val){
		if((*head)->right)
			insert(&(*head)->right,newnode);
		else
			(*head)->right = newnode;
	}
	else{
		if((*head)->left)
			insert(&(*head)->left,newnode);
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

int print_vec(vector<int> vec,int count){
	for(int i=0;i<count;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
	return 0;
}

int all_paths(tree *head,vector<int> &vec,stack<tree *> &s,int &count){
	if(head == NULL){
		//s.pop();
		//if(head->left == NULL && head->right== NULL)
			//print_vec(vec,count);
		// for(auto i:vec)
		// 	cout<<i<<" ";
		// cout<<endl;
		return 0;
	}
	//s.push(head);
	vec[count]=head->val;
	// cout<<count<<" "<<head->val<<endl;
	//cout<<head->val<<" ";
	all_paths(head->left,vec,s,++count);
	count--;
	all_paths(head->right,vec,s,++count);
	if(head->left == NULL && head->right == NULL){
		print_vec(vec,count);
	}
	count--;
	return 0;
}

int main(){
	tree *head = NULL;
	tree *newnode = NULL;
	vector<int> vec ={3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode = new tree(i);
		insert(&head,newnode);
	}
	print_tree(head);
	cout<<endl;
	stack<tree *>s;
	int count =0;
	all_paths(head,vec,s,count);
	return 0;
}