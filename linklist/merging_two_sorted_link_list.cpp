#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int data;
	struct ListNode *next;
};

int insertSorted(struct ListNode **head,int data){
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
	if(prev == NULL){
		*head = newnode;
		return 0;
	}
	prev->next = newnode;
	
	return 0;	
}

int printlist(struct ListNode *head){
	while(head){
		cout<<head->data<<endl;
		head = head->next;
	}
	return 0;
}

struct ListNode* mergeList(struct ListNode *head1,struct ListNode *head2){
	struct ListNode *result = NULL;
	if(head1== NULL && head2 == NULL){
		return head1;
	}
	if(head2 !=NULL && head1 == NULL ){
		result = head2;
		return result;
		//result->next = head2->next;
	}
	if(head1!=NULL && head2 == NULL){
		result = head1;
		return result;
		//result->next = head
	}
	// if(head2 == NULL)
	// 	return head2;

	if(head1->data<head2->data){
		result = head1;
		result->next = mergeList(head1->next,head2);
	}
	else{
		result = head2;
		result->next = mergeList(head2->next,head1);
	}
	return result;
}

struct ListNode* mergeLoop(struct ListNode *head1,struct ListNode *head2){
	struct ListNode *newnode = new ListNode;
	newnode->next = NULL;
	struct ListNode *tmp = newnode;
	while(head1 && head2){
		if(head1->data<head2->data){
			tmp->next = head1;
			tmp = head1;
			head1 = head1->next;
		}
		else{
			tmp->next = head2;
			tmp = tmp->next;
			head2 = head2->next;
		}
		
	}
	if(head1!= NULL)
		tmp->next = head1;
	else
		tmp->next = head2;
	tmp = newnode->next;
	free(newnode);
	return tmp;
}

int main(){
	int i=0;
	struct ListNode *head1 = NULL;
	struct ListNode *head2 = NULL;
	for(i=10;i>=0;i--){
		if(i%2 ==0){
			insertSorted(&head1,i);
		}
		else{
			insertSorted(&head2,i);
		}
	}
	printlist(head1);
	cout<<endl;
	printlist(head2);
	struct ListNode *result = mergeLoop(head1,head2);
	//mergeList(head1,head2);
	cout<<endl;
	printlist(result);
	cout<<endl;
	return 0;

}