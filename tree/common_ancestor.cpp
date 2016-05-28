#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tree{
	int val;
	tree *left,*right;
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

tree * common_ancestor(tree *head,tree *a,tree *b){
	if(head == NULL){
		return 0;
	}
	if(head == a || head == b)
		return head;
	tree *left = common_ancestor(head->left,a,b);
	tree *right = common_ancestor(head->right,a,b);
	if(left && right){
		return head;
	}	
	else{
		return (left?left:right);
	}
}

int main(){
	tree *head = NULL;
	vector<int> vec={3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		tree *newnode = new tree(i);
		insert(&head,newnode);
	}
	print_tree(head);
	cout<<endl;
	tree *temp = common_ancestor(head,head->left,head->right);
	cout<<temp->val<<endl;
	return 0;
}