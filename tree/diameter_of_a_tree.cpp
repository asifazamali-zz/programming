#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct tree{
	int val;
	struct tree *left;
	struct tree *right;
	tree(int x):val(x),left(NULL),right(NULL){};
};

int insert(struct tree **head,struct tree *newnode){
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
		if((*head)->left)
			insert(&(*head)->left,newnode);
		else
			(*head)->left = newnode;
	}
}

int print_tree(struct tree *head){
	struct tree *temp = NULL;
	queue<struct tree*> q;
	q.push(head);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		cout<<temp->val<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return 0;
}

int max_length(struct tree *head){
	int left=0,right =0;
	if(head->left == NULL && head->left == NULL)
		return 1;
	if(head->left)
		left = max_length(head->left);
	if(head->right)
		right = max_length(head->right);
	return (left>right)?(left+1):(right+1);
}

int diameter(struct tree *head){
	int left =0;
	int right = 0;
	if(head->left == NULL && head->right == NULL){
		return 1;
	}
	if(head->left)
		left = max_length(head->left);
	if(head->right)
		right = max_length(head->right);
	return left+right+1;
}
int main(){
	struct tree *head = NULL;
	struct tree *newnode = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode =new tree(i);
		insert(&head,newnode);
	}
	print_tree(head);
	cout<<endl;
	int dia = diameter(head);
	cout<<dia<<endl;
}