#include <iostream>
#include <vector>

using namespace std;

struct ListNode{
	int data;
	struct ListNode *next;
};


int push(struct ListNode **head,int data){
	struct ListNode *newnode = new ListNode;
	struct ListNode *curr;
	newnode->data = data;
	if(*head ==NULL){
		*head = newnode;
		return 0;
	}
	newnode->next = *head;
	*head = newnode;
}

int pop(struct ListNode **head){
	struct ListNode *curr = *head;
	if(*head == NULL){
		cout<<"Stack is empty\n";
		return 0;

	}
	int data = (*head)->data;
	*head = (*head)->next;
	return data;
}
int main(){
	int i;
	struct ListNode *head;
	for(i=0;i<5;i++){
		push(&head,i);
	}
	for(i=0;i<5;i++){
		cout<<pop(&head);
	}
	return 0;
}