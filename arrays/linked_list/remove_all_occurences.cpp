#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next; //pointer to the next element
    
    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr; //for the last element the pointer of next element is null pointer
    }
};

Node* convertarrtoLL(vector <int> &arr){
    Node* head = new Node(arr[0]); // creates a new node with value of arr[0] and next=null pointer
    Node* mover = head; //this is a pointer that tranverses through array
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* remove_all_occurences(Node* head, int val){
        if(head==NULL) return nullptr;
        Node* temp = head;
        Node* dummy = new Node(0,head); // dummy is used to it prevents the case the head is to be removed
        Node* prev = dummy;
        while(temp){
            if(temp->data == val){
                Node* delNode= temp;
                prev->next = temp->next;
                temp = temp->next;
                delete delNode;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy->next;
    }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}