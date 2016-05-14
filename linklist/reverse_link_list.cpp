#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int data;
	struct ListNode *next;
};

int append(struct ListNode **head,int data){
	struct ListNode *newnode = new ListNode;
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL){
		*head = newnode;
		return 0;
	}	
	struct ListNode *curr = *head;
	while(curr->next){
		curr = curr->next;
	}
	curr->next = newnode;
	return 0;
}

int reverse(struct ListNode **head){
	struct ListNode *prev,*curr,*next_node;
	prev = NULL;
	curr = *head;
	next_node = curr->next;
	while(next_node){
		curr->next = prev;
		prev = curr;
		curr = next_node;
		next_node = next_node->next;
	}
	curr->next = prev;
	*head = curr;
	return 0;
}
int reverse_recurse(struct ListNode **head,struct ListNode *prev,struct ListNode **curr){
	//cout<<prev<<" "<<*head<<endl;
	if(*head == NULL){
		cout<<"head"<<prev->data<<endl;
		(*curr) = prev;
		cout<<*head<<endl;
		return 0;
	}
	reverse_recurse(&((*head)->next),*head,curr);
	//cout<<prev<<endl;
	(*head)->next = prev;
	//cout<<*head<<" "<<(*head)->next<<" "<<(*head)->data<<endl;
	//cout<< 
	return 0;
}
int printList(struct ListNode *head){
	struct ListNode *temp = head;
	while(temp){
		cout<<temp->data<<endl;
		temp = temp->next;
	}
	return 0;
}

int main(){
	int i=0;
	struct ListNode *head = NULL;
	for(i=0;i<5;i++){
		append(&head,i);
	}
	//printList(head);
	cout<<endl;

	//reverse(&head);
	//printList(head);
	struct ListNode *temp = NULL;
	struct ListNode *curr = NULL;
	reverse_recurse(&head,temp,&curr);
	cout<<endl;
	printList(curr);
	return 0;
}