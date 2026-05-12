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

Node* reverseLL(Node* head){
    Node* temp = head;
    Node* prev = NULL;
    while(temp){
        Node* next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node* getkthnode(Node* temp, int k){
    k-=1;
    while(temp && k){
        temp=temp->next;
        k--;
    }
    return temp;
}
Node* revnodes_ksize(Node* head, int k){
    Node* temp = head; 
    Node* prevlastnode = nullptr;
    while(temp){
        Node* kthnode = getkthnode(temp,k);
        if(kthnode==NULL){
            if(prevlastnode) prevlastnode->next=temp;
            break;
        }
        Node* nextnode = kthnode->next;
        kthnode->next=nullptr;
        reverseLL(temp);
        if(temp==head){
            head = kthnode;
        }
        else{
            prevlastnode->next=kthnode;
        }
        prevlastnode = temp;
        temp = nextnode;
    }
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    


    return 0;
}