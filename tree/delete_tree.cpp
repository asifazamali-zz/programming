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

int insert_level(struct tree **head,struct tree *newnode){
	if(*head == NULL){
		*head = newnode;
		return 0;
	}
	queue<struct tree *> q;
	q.push(*head);
	while(true){
		struct tree *temp = q.front();
		q.pop();
		if(temp->left == NULL){
			temp->left = newnode;
			return 0;
		}
		if(temp->right == NULL){
			temp->right = newnode;
			return 0;
		}
		else{
			q.push(temp->left);
			q.push(temp->right);
		}
	}
	return 0;
}

int delete_tree(struct tree *head){
	if(head == NULL){
		return 0;
	}
	if(head->left)
		delete(head->left);
	if(head->right)
		delete(head->right);
	head->left = NULL;
	head->right = NULL;
	free(head);
}

int main(){
	struct tree *head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		struct tree *newnode = new tree(i);
		insert_level(&head,newnode);
	}
	cout<<head->val<<endl;

	delete_tree(head);
	cout<<head->val<<endl;
	if(head== NULL){
		cout<< "tree deleted"<<endl;
	}
	return 0;
}