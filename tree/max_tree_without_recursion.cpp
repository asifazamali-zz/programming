#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct tree{
	int val;
	struct tree *left;
	struct tree *right;
	tree(int x):val(x),left(NULL),right(NULL){}
};

int insert(struct tree **head,struct tree *newnode){
	if(*head == NULL){
		(*head) = newnode;
		return 0;
	}
	if((*head)->val<newnode->val){
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
}

int maximum(struct tree *head){
	queue<struct tree *> q;
	q.push(head);
	int maxx = -1;
	while(!q.empty()){
		struct tree *temp = q.front();
		if(maxx<temp->val)
			maxx = temp->val;
		q.pop();
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
	return maxx;
}

int main(){
	struct tree *head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		struct tree *newnode = new tree(i);
		insert(&head,newnode);
	}
	int maxx = maximum(head);
	cout<<maxx<<endl;
	return 0;
}

