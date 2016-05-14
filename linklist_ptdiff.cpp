#include <iostream>
#include <vector>
using namespace std;

struct ListNode{
	int data;
	struct ListNode *ptrdiff;

};

struct ListNode* createNode(int data){
	struct ListNode *newnode = (struct ListNode*) malloc(sizeof(struct ListNode));
	newnode->data =data;
	newnode-> ptrdiff = NULL;

}
struct ListNode* nextNode(struct ListNode* curr,struct ListNode* prev){
	return ((struct ListNode*) ((long int) curr->ptrdiff ^ (long int)prev));
}
int printContents(struct ListNode *head){
	struct ListNode *temp ,*prev,*next;
	temp= head;
	//cout<<"printContents"<<head;
	prev = NULL;
	while(temp){
		cout<<temp->data<<"-->";
		//prev = temp;
		next = nextNode(temp,prev);
		prev = temp;
		temp = next;
		//cout<<temp<<endl;
	}
	return 0;
}

int appendNode(struct ListNode **head,int data){
	struct ListNode *newnode = createNode(data);
	cout<<newnode->data<<newnode<<endl;	
	if(*head == NULL){
		*head = newnode;
		//cout<<newnode->data<<endl;
		return 0;
	}
	cout<<*head<<endl;
		
	struct ListNode *curr,*prev,*next;
	curr= *head,prev = NULL;
	//cout<<curr->ptrdiff<<prev<<endl;
	while(curr){
		//prev = curr;
		cout<<curr->ptrdiff<<prev<<endl;
		next = nextNode(curr,prev);
		prev = curr;
		curr = next;
		cout<<prev<<" "<<curr<<endl;
	}
	curr = prev;
	curr->ptrdiff = ((struct ListNode*) ((long int)prev->ptrdiff ^ (long int) newnode));
	prev = ((struct ListNode*)((long int)curr->ptrdiff ^(long int)newnode));
	newnode->ptrdiff = ((struct ListNode*)((long int)newnode->ptrdiff ^ (long int)curr));
	cout<<curr->data<<'\n';
	cout<<"newnode->ptrdiff"<<newnode->ptrdiff<<'\n';
	return 0;
}

int main(){
	int N=5;
	int i;
	struct ListNode *head = NULL;
	for(i=0;i<N;i++){
		appendNode(&head,i);
		//printContents(head);
	}
	printContents(head);
	cout<<"\n";
	return 0;
}