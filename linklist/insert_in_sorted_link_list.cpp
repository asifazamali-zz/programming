#include <iostream>
#include <vector>

using namespace std;
struct ListNode{
	int data;
	struct ListNode *next;
};

int insertinsortedlist(struct ListNode **head,int data){
	struct ListNode *newnode = new ListNode;
	newnode->data = data;
	newnode->next = NULL;
	if(*head == NULL){
		*head = newnode;
		return 0;
	}
	struct ListNode *curr = *head;
	struct ListNode *prev = NULL;
	while(curr && curr->data<data){
		prev = curr;
		curr = curr->next;
	}
	newnode->next = curr;
	if(prev == NULL){				/* newnode is first node */
		*head = newnode;
		return 0;
	}
	prev->next = newnode;

	//curr->next = newnode;
	return 0;
}
int printList(struct ListNode *head){
	struct ListNode *curr = head;
	while(curr){
		cout<<curr->data<<endl;
		curr = curr->next;
	}
	return 0;
}
int main(){
	int i=0;
	struct ListNode *head = NULL;
	for(i=5;i>=0;i--){
		insertinsortedlist(&head,i);
	}
	printList(head);
	return 0;
}