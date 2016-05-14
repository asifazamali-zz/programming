#include <iostream>
#include <vector>
#include <map>
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
int createHash(struct ListNode **head,map<int,struct ListNode *> &hashmap){
	struct ListNode *curr = *head;
	int count = 0;
	while(curr){
		count++;
		hashmap[count] = curr;
		curr = curr->next;
	}
	return 0;
}
int main(){
	int i;
	struct ListNode *head = NULL;
	for(i=0;i<5;i++){
		append(&head,i);
	}
	map<int,struct ListNode *> hashmap;
	map<int,int> demo;
	demo[1]=2;
	demo[2] = 3;
	// demo.emplace(2,5);
	// cout<<demo[2]<<endl;
	// demo[1] = 3;
	// cout<< demo.at(1)<<endl;
	createHash(&head,hashmap);
	//hashmap[3]= 0x70bc20;
	for(auto it=hashmap.begin();it!= hashmap.end();it++){
		cout<<it->first<<"-->"<<it->second<<endl;
	}
	int len = hashmap.size();
	int p = 3;
	int from_start = len-p+1;
	cout<<hashmap.at(from_start)->data;
	return 0;
}