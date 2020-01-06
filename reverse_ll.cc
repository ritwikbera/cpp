#include <bits/stdc++.h>

using namespace std;

struct Node{
	int data;
	Node *next, *prev;
};

Node* getNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = new_node->prev = NULL;
	return new_node;
}

Node* push(Node* head_ref, Node* new_node)
{
	new_node->prev = NULL;
	new_node->next = (head_ref);

	if ((head_ref) != NULL)
		(head_ref)->prev = new_node;

	head_ref = new_node;

	return head_ref;
}

Node* Reverse(Node* node) 
{ 
    if (!node) 
        return NULL; 
  
    Node* temp = node->next; 
    node->next = node->prev; 
    node->prev = temp; 

    if (!node->prev) 
        return node; 
  
    return Reverse(node->prev); 
} 
  

void printList(Node* head) 
{ 
    while (head != NULL) { 
        cout << head->data << " "; 
        head = head->next; 
    } 
} 
  
int main() 
{ 
    Node* head = NULL; 
  
    head = push(head, getNode(2)); 
    head = push(head, getNode(4)); 
    head = push(head, getNode(8)); 
    head = push(head, getNode(10)); 
    cout << "Original list: "; 
    printList(head); 
  
    head = Reverse(head); 
    cout << "\nReversed list: "; 
    printList(head); 
    return 0; 
} 