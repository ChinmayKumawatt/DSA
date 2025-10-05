#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* prev;
		Node* next;
		
		Node(int d){
			this->data = d;
			this->next = NULL;
			this->prev = NULL;
		}
		~Node(){
			int value = this->data;
			if(this->next!=NULL){
				delete next;
				this->next = NULL;
			}
			cout<<value<<" deleted"<<endl;
		}
};

	void print(Node* head){
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	
	int getLength(Node* head){
		int len = 0;
		Node* temp = head;
		while(temp!=NULL){
			len++;
			temp=temp->next;
		}
		return len;
	}
	
	void insertAtHead(Node* &head,int d){
		Node* temp = new Node(d);
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
	
	void insertAtTail(Node* &tail,int d){
		Node* temp = new Node(d);
		tail->next = temp;
		temp->prev = tail;
		tail = temp;
	}
	
	void insertAtPosition(Node* &tail,Node* &head,int position, int d){
		if(position == 1){
			insertAtHead(head,d);
			return;
		}
		Node* temp = head;
		int cnt = 1;
		while(cnt<position-1){
			temp = temp->next;
			cnt++;
		}
		if(temp->next == NULL){
			insertAtTail(tail,d);
			return;
		}
		Node* nodeToInsert = new Node(d);
		nodeToInsert->next = temp->next;
		temp->next->prev = nodeToInsert; 
		temp->next = nodeToInsert;
		nodeToInsert->prev = temp;
	}
	
	void deleteNode(Node* &head, int pos){
		if(pos==1){
			Node* position = head;
			head = head->next;
			position->next = NULL;
			head->prev=NULL;
			delete position;
		}
		else{
			Node* curr = head;
			Node* previous = NULL;
			int cnt = 1;
			while(cnt<pos){
				previous = curr;
				curr = curr->next;
				cnt++;
			}
			previous->next = curr->next;
			curr->next->prev = previous;
			curr->next = NULL;
			curr->prev = NULL;
			delete curr;
		}	
	}
	
int main(){
	Node* node1 = new Node(10);
	Node* head = node1;
	Node* tail = node1;
	print(head);
	insertAtHead(head,11);
	print(head);
	insertAtTail(tail,13);
	print(head);
	insertAtPosition(tail,head,3,12);
	print(head);
	deleteNode(head,2);
	print(head);
	deleteNode(head,1);
	print(head);
//	cout<<getLength(head)<<endl;
	return 0;
}
