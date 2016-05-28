#include <iostream>
#include <vector>
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
	if((*head)->val<newnode->val){
		if((*head)->right == NULL){
			(*head)->right = newnode;
		}
		else
			insert(&(*head)->right,newnode);
	}
	else{
		if((*head)->left == NULL)
			(*head)->left = newnode;
		else{
			insert(&(*head)->left,newnode);
		}
	}
}

int find(struct tree *head,int searchdata){
	if(head == NULL)
		return 0;
	if(head->val == searchdata){
		return 	1;
	}
	if(head->val<searchdata){
		return find(head->right,searchdata);
	}
	else{
		return find(head->left,searchdata);
	}
	return 0;

}

int main(){
	struct tree *head = NULL;
	vector<int> vec = {3,2,1,5,6,7,8,9,5,1};
	for(auto i: vec){
		struct tree *newnode = new tree(i);
		insert(&head,newnode);
	}
	int result = find(head,17);
	cout<<result<<endl;
}