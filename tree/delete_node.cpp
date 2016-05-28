/*check for first_node,last_node,inbetween node*/


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
}

struct tree* delete_node(struct tree *head,int data,struct tree *prev){
	//cout<<head->val<<" "<<data;
	if(head->val == data){
		//cout<<head->val<<" "<<data<<" "<<prev->val<<endl;
		return prev;
	}
	if(head->val < data && head->right)
		return delete_node(head->right,data,head);
	if(head->val > data && head->left)
		return delete_node(head->left,data,head);
	return NULL;		
}

struct tree *last_node(struct tree *head){
	queue<struct tree*> q;
	struct tree *prev = NULL;
	q.push(head);
	while(!q.empty()){
		struct tree *temp = q.front();
		q.pop();
		if(temp->left){
			prev = temp;
			q.push(temp->left);
		}
		if(temp->right){
			prev = temp;
			q.push(temp->right);
		}	
	}
	return prev;
}

int print_tree(struct tree *head){
	queue<struct tree*> q;
	q.push(head);
	while(!q.empty()){
		struct tree *temp = q.front();
		q.pop();
		cout<< temp->val<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}

int del(struct tree **head,int data){
	struct tree *del_node = NULL;
	if((*head)->val == data){
		struct tree *last_prev = last_node(*head);
		//cout<<"head"<<endl;
		//cout<<"inside else"<<endl;
		struct tree *last = NULL;
		if(last_prev->right){
			last = last_prev->right;
			//cout<<last->val<<endl;
			last_prev->right = NULL;
		}
		else{
			last = last_prev->left;
			//cout<<last->val<<endl;
			last_prev->left = NULL;
		}
		last->left = (*head)->left;
		last->right = (*head)->right;
		free(*head);
		*head = last;
		return 0;
	}
	else{
		del_node = delete_node(*head,data,NULL);
		if(del_node == NULL){
			cout<<"node not found"<<endl;
		}
		else{	
			//cout<<"node_found"<<endl;
			struct tree *last_prev = last_node(*head);
			//cout<<"inside else"<<endl;
			struct tree *last = NULL;
			if(last_prev == del_node){
				if(last_prev->right && del_node->right && last_prev->right->val == del_node->right->val){
					free(last_prev->right);
					last_prev->right = NULL;
					return 0;
				}
				else{
					free(last_prev->left);
					last_prev->left = NULL;
					
				}							
			}
			else{
				if(last_prev->right){

					last = last_prev->right;
					//cout<<last->val<<endl;
					last_prev->right = NULL;
				}
				else{
					last = last_prev->left;
					//cout<<last->val<<endl;
					last_prev->left = NULL;
				}
			}	
			//cout<<del_node->val<<endl;
			// if(del_node->right)
			// 	cout<<"del_right"<<del_node->right->val<<endl;
			// else
			// 	cout<<"del_left"<<del_node->left->val<<endl;

			if(del_node->left && del_node->left->val == data){
				last->left = del_node->left->left;
				last->right = del_node->left->right;
				cout<<"left"<<endl;
				//if(del_node->left !=last){
				free(del_node->left);
				del_node->left = last;
				//}
				// else
				// 	free(del_node->left);	
				
			}
			else{
				//cout<<last->val<<endl;
				last->right = del_node->right->right;
				last->left = del_node->right->left;
				cout<<"right"<<endl;
				//if(del_node->right !=last){
				free(del_node->right);
				del_node->right = last;
				// }
				// else
				// 	free(del_node->right);	

			}
		}	
		//free(last);
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
	print_tree(head);
	cout<<endl<<endl;
	
	del(&head,9);
	cout<<"after delete"<<endl;
	print_tree(head);
	cout<<endl<<endl;
	return 0;


		
}



