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

int insert(struct tree **head, struct tree *newnode){
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

int areidentical(struct tree *head1,struct tree *head2){
	if(head1== NULL && head2 == NULL)
		return 1;
	if(head1== NULL || head2== NULL)
		return 0;
	return (head1->val == head2->val && areidentical(head1->left,head2->left) && areidentical(head1->right,head2->right));
}

int main(){
	struct tree *head1= NULL,*head2 = NULL;
	struct tree *newnode = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode = new tree(i);
		insert(&(head1),newnode);
	}
	vector<int> vec1 = {3,2,1,2,6,7,8,9,5,1};
	
	for(auto i:vec1){
		newnode = new tree(i);
		insert(&(head2),newnode);
	}
	int res= areidentical(head1,head2);
	cout<<res<<endl;
	return 0;
}