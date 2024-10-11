#include<bits/stdc++.h>

class Node {
private:
    int data;
    Node *next;
public:
    Node(int data) {
        this->data = data;
        next = nullptr;
    }
    void setNext(Node* pointer) {
        next = pointer;
    }
    void iterate(Node * head) {
        while(head) {
            cout<<head->data<<" ";
            head = head->next;
        }
    }
};

int main() {
    Node *head = new Node(12);
    head->setNext(new Node(1));
    head->iterate(head);
}