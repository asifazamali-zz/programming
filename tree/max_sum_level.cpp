/*finding level with max sum */

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
	if((*head)->val<newnode->val){
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

int max_level_sum(tree *head){
	int maxx=0,maxlevel=-1,level=-1,summ=-1;
	queue<tree *> q;
	q.push(head);
	q.push(NULL);
	while(!q.empty()){
		tree *temp = q.front();
		q.pop();
		if(temp == NULL){
			level++;
			if(maxx<summ){
				maxx= summ;
				maxlevel= level;
				summ =0;
			}
			if(!q.empty())
				q.push(NULL);
		}
		else{
			summ += temp->val;
			if(temp->left)
				q.push(temp->left);
			if(temp->right)
				q.push(temp->right);
		}	
	}
	return level;
}

int main(){
	tree *head = NULL;
	tree *newnode = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		newnode = new tree(i);
		insert(&head,newnode);
	}
	int res = max_level_sum(head);
	cout<<res<<endl;
	return 0;
}