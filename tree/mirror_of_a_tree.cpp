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

int mirror(tree *head){
	if(head == NULL)
		return 0;
	mirror(head->left);
	mirror(head->right);
	tree *temp = head->left;
	head->left = head->right;
	head->right = temp;
	return 0;
}






int main(){
	tree *head,*newnode = NULL;
	head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode = new tree(i);
		insert(&(head),newnode);
	}
	print_tree(head);
	cout<<endl;
	mirror(head);
	print_tree(head);
	cout<<endl;
	return 0;
}