#include<iostream>
#include<vector>

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

int printList(struct ListNode *head){
	while(head){
		cout<<head->data<<endl;
		head = head->next;
	}
	return 0;
}

struct ListNode* reverseInPair(struct ListNode *head){
	if(head == NULL || head->next==NULL){
		return 0;
	}
	else{
		struct ListNode *temp;
		temp = head->next;
		head->next = temp->next;
		temp->next = head;
		head = temp;
		head->next->next = reverseInPair(head->next->next);
		return head;
	}
}

// struct ListNode * reversePairIter(struct ListNode *head){
	
// }

int main(){
	struct ListNode *head=NULL;
	int i=0;
	for(i=0;i<6;i++){
		append(&head,i);
	}
	printList(head);
	struct ListNode *result =reverseInPair(head);
	cout<<endl;
	printList(result);
	return 0;
}