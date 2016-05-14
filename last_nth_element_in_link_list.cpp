#include<iostream>
#include<vector>
using namespace std;


struct ListNode{
	int data;
	struct ListNode *next;
};
int append(struct ListNode **head,int data){
	struct ListNode *newnode = new ListNode;
	newnode->data =data;
	newnode->next = NULL;
	if(*head == NULL){
		*head = newnode;
		return 0;
	}
	struct ListNode *curr= *head;
	while(curr->next){
		curr = curr->next;

	}
	curr->next = newnode;
	return 0;
}

int length(struct ListNode **head){
	struct ListNode *curr = *head;
	int size=0;
	while(curr){
		curr = curr->next;
		size++;

	}
	return size;
}
int getpelement(struct ListNode **head,int p){
	int count =1;
	struct ListNode *curr = *head;
	while(count<p && curr->next){
		curr = curr->next;
		count++;
	}
	return curr->data;
}
int main(){
	int i;
	struct ListNode *head =NULL;
	for(i =0; i<5;i++){
		append(&head,i);
	}
	int len = length(&head);
	cout<<len;
	int p=3;
	cout<<getpelement(&head,len-p);
	return 0;
}