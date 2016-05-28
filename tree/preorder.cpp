#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct tree{
	int val;
	struct tree *left;
	struct tree *right;
	tree(int x): val(x),left(NULL),right(NULL) {}
};



int insert(struct tree **head,struct tree *newnode){
	if(*head == NULL){
		(*head) = newnode;
		return 0;
	}
	if(((*head)->val)> (newnode->val)){
		//cout<<(*head)->val<<" >"<<newnode->val<<endl;
		if((*head)->left == NULL)
			(*head)->left = newnode;
		else
			insert(&((*head)->left),newnode);
	}
	else{
		//cout<<(*head)->val<<" <="<<newnode->val<<endl;
		
		if((*head)->right == NULL)
			(*head)->right = newnode;
		else
			insert(&((*head)->right),newnode);
	}
	return 0;
}


int preorder_non_recursive(struct tree *head){
	stack<struct tree*> s;
	if(head == NULL){
		return 0;
	}
	while(1){
	  	while(head){
	  		cout<<head->val<<" ";
	  		s.push(head);
	  		head = head->left;
	  	} 
	  	if(s.empty())
	  		break; 	
	  	head = (s.top())->right;
	  	//cout<<head->val<<" ";
	  	s.pop();
					
	}
}


int inorder_non_recursive(struct tree *head){
	stack<struct tree*> s;
	if(head == NULL)
		return 0;
	while(1){
		while(head){
	  		//cout<<head->val<<" ";
	  		s.push(head);
	  		head = head->left;
	  	} 
	  	if(s.empty())
	  		break; 	
	  	head = (s.top());
	  	cout<<head->val<<" ";
	  	head = head->right;
	  	s.pop();
					
	
	}
}


/* for non_recursive_post_order maintain a prev pointer such that each node should visit twice */

int print_preorder(struct tree *head){
	if(head == NULL)
		return 0;
	cout<<head->val<<" ";
	print_preorder(head->left);
	print_preorder(head->right);
	return 0;
}

int print_postorder(struct tree *head){
	if(head == NULL)
		return 0;
	print_postorder(head->left);
	print_postorder(head->right);
	cout<<head->val<<" ";
	return 0;
}

int print_inorder(struct tree *head){
	if(head == NULL)
		return 0;
	print_inorder(head->left);
	cout<<head->val<<" ";
	print_inorder(head->right);
	return 0;
}

int main(){
	struct tree *head = NULL;
	vector<int> vec={3,2,1,5,6,7,8,9,5,1};
	// for(int i = 1;i< 7;i++){
	// 	vec.push_back(i);
	// }
	//int ctr=1;

	for(auto i: vec){
		struct tree *newnode = new tree(i);
		insert(&head,newnode);
		
	}

 	cout<<endl<<endl;
	print_preorder(head);
	cout<<endl<<endl;
	preorder_non_recursive(head);
	cout<<endl<<endl;
	print_postorder(head);
	cout<<endl<<endl;
	print_inorder(head);
	cout<<endl<<endl;
	inorder_non_recursive(head);
	return 0;
}