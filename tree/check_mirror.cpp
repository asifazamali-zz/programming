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
	return 0;
}

tree * mirror(tree *head){
	if(head == NULL)
		return 0;
	tree *left = mirror(head->left);
	tree *right = mirror(head->right);
	tree *temp = new tree(head->val);
	if(left)
		temp->right = left;
	if(right)
		temp->left = right;
	return temp;
}

int checkMirror(tree *head1,tree *head2){
	//cout<<head1<<" "<<head2<<endl;
	//return 0;
	if(head1== NULL && head2 == NULL)
		return 1;
	if(head1 == NULL || head2 == NULL)
		return 0;
	//cout<<head1->val<<" "<<head2->val<<endl;
	if(head1->val != head2->val){
		//cout<<head1->val<<" "<<head2->val<<endl;
		return 0;
	}	
	// else{
	// 	cout<<head1->val<<" "<<head2->val<<endl;
	// 	//cout<<head1->left->val<<" "<<head2->right->val<<endl;
	return (checkMirror(head1->left,head2->right) && checkMirror(head1->right,head2->left));

	//}
}

int print_tree(tree *head){
	//cout<<"print_tree"<<head<<endl;
	queue<tree*> q;
	q.push(head);
	while(!q.empty()){
		tree *temp = q.front();
		q.pop();
		//cout<<temp<<endl;
		cout<<temp->val<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);

	}
	return 0;
}

int main(){
	tree *head1 = NULL,*head2= NULL,*newnode = NULL;
	vector<int> vec={3,2,1,5,6,7,8,9,5,1};
	for(auto i:vec){
		newnode = new tree(i);
		insert(&head1,newnode);
	}
	print_tree(head1);
	cout<<endl;
	//head2= head1;
	head2 = mirror(head1);
	print_tree(head2);
	//cout<<head2<<endl;
	cout<<endl;
	cout<<checkMirror(head1,head2)<<endl;
	return 0;
}