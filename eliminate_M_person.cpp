#include <iostream>
#include <vector>
using namespace std;
struct ListNode{
	int data;
	struct ListNode *next;
};
int printList(struct ListNode *head){
	struct ListNode *curr = head;
	do{
		cout<<head->data<<endl;
		head = head->next;
	}while(head!=curr);
}
int main(){
	struct ListNode *p,*q;
	p = q = new ListNode;
	p->data = 1;
	p->next = NULL;
	for(int i=2;i<10;i++){
		p->next = new ListNode;
		p = p->next;
		p->data = i;
	}
	p->next = q;
	int M=5;
	printList(q);
	cout<<endl;
	for(int count=10;count>1;count--){
		for(int i=0;i<M;i++){
			p = p->next;
		}

		p->next = p->next->next;
		q =p;
		printList(q);
		//return 0;
		cout<<endl;
	}
	//printList(q);


}