#include <iostream>
using namespace std;

class Node{
	public:
		int data;
		Node* next;
	
	//constructor	
	Node(int data){
		this->data = data;
		this->next = NULL;
	}
	
	~Node(){
		int value=this->data;
		if(this->next!=NULL){
			delete next;
			this->next = NULL;
		}
		cout<<"memory freed for data "<<value<<endl;
	}
};

	void insertAtHead(Node* &head,int d){
		Node* temp = new Node(d);
		temp->next = head;
		head = temp;
	}
	
	void insertAtTail(Node* &last,int d){
		Node* temp = new Node(d);
		last->next = temp;
		//last = temp;
		last = last->next;
	}
	
	void insertAtMid(Node* &head,Node* tail,int pos,int d){
		if(pos==1){
			insertAtHead(head,d);
			return;
		}
		Node* temp = new Node(d);
		Node* position=head;
		for(int i = 1;i<pos-1;i++){
			position = position->next;
		}		
		if(position->next==NULL){
			insertAtTail(tail,d);
			return;
		}
		temp->next = position->next;
		position->next=temp;
	}
	
	void deleteNode(Node* head,int pos){
		if(pos==1){
			Node* position = head;
			head = head->next;
			position->next=NULL;
			delete position;
		}
		else{
		Node* curr = head;
		Node* prev = NULL;
		for(int i = 1;i<pos;i++){
			prev = curr;
			curr = curr->next;
		}
		prev->next = curr->next;
		curr->next=NULL;
		delete curr;
	}
	}	
	
	void print(Node* &head){
		Node* temp = head;
		while(temp!=NULL){
			cout<<temp->data<<" ";
			temp = temp->next;
		}
		cout<<endl;
	}


int main(){
	Node* node1 = new Node(10);
	
	Node* head = node1;
	Node* last = node1;
	
	insertAtHead(head,12);
	insertAtHead(head,15);

	insertAtTail(last,6);
	insertAtTail(last,7);
	insertAtTail(last,8);
	
	insertAtMid(head,last,2,90);
	insertAtMid(head,last,8,80);
	
	deleteNode(head,2);
	
	print(head);
	
	return 0;
}
