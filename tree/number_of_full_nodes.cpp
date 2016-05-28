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

int print_tree(struct tree *head){
	struct tree *temp = NULL;
	if(head == NULL)
		return 0;
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
	//free(temp);
	return 0;
}



int number_of_full_nodes(struct tree *head){
	int res=0;
	struct tree *temp = NULL;
	if(head == NULL){
		return 0;
	}
	queue<struct tree*> q;
	q.push(head);
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp->left && temp->right)
			res++;
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	//free(temp);
	return res;
}

int main(){
	struct tree *head = NULL;
	struct tree *newnode = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode = new tree(i);
		insert(&(head),newnode);
	}
	print_tree(head);
	cout<<endl;
	int res = number_of_full_nodes(head);
	cout<<res;
	//free(head);
	//free(newnode);
	return 0;
}