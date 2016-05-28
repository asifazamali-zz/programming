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
		(*head) = newnode;
		return 0;
	}
	if((*head)->val<(newnode->val)){
		if((*head)->right == NULL)
			(*head)->right = newnode;
		else
			insert(&(*head)->right,newnode);
	}
	else{
		if((*head)->left == NULL)
			(*head)->left = newnode;
		else
			insert(&(*head)->left,newnode);
	}
	return 0;
}

int print_level(struct tree *head){
	if(head == NULL){
		return 0;
	}
	queue<struct tree *> q;
	q.push(head);
	while(!q.empty()){
		head = q.front();
		q.pop();
		cout<<head->val<<" ";
		if(head->left)
			q.push(head->left);
		if(head->right)
			q.push(head->right);

	}
}


int main(){
	struct tree *head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		struct tree *newnode = new tree(i);
		insert(&head,newnode);
	}
	print_level(head);
	return 0;
}
