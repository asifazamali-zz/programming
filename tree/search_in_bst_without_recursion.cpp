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
	if((*head)->val< newnode->val){
		if((*head)->right == NULL)
			(*head)->right = newnode;
		else
			insert(&(*head)->right,newnode);
	}
	else{
		if((*head)->left)
			insert(&(*head)->left,newnode);
		else
			(*head)->left = newnode;
	}
}



int print_tree(struct tree *head){
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
	return 0;
}

int find(struct tree *head,int searchdata){
	if(head == NULL){
		return 0;
	}
	queue<struct tree *> q;
	q.push(head);
	while(!q.empty()){
		struct tree *temp = q.front();
		q.pop();
		if(temp == NULL)
			return 0;
		
		if(temp->val == searchdata)
			return 1;
		if(temp->val < searchdata){
			q.push(temp->right);
		}
		else{
			q.push(temp->left);
		}
	}
	return 0;
}

int main(){
	struct tree *head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		struct tree *newnode = new tree(i);
		insert(&head,newnode);
	}
	// print_tree(head);
	// cout<<endl;
	int result = find(head,17);
	cout<<result<<endl;
}