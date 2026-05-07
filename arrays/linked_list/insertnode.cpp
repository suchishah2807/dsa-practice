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

Node* insertHead(Node* head,int val){
    Node* newHead= new Node(val,head);
    return newHead;
}

Node* insertTail(Node* head, int val){
    if(head == NULL){
        return new Node(val);
    }
    Node* temp = head;
    Node* newtail = new Node(val);
    while(temp){
        temp = temp->next;
    }
    temp->next = newtail;
    return head;
}

Node* insertkthelement(Node* head, int val, int k){
    if(head==NULL) {
        if(k==1){
            return new Node(val);
            }
        else{
            return NULL;
        }
    }
    if(k==1){
        Node* newHead= new Node(val,head);
        return newHead;
    }
    Node* temp = head;
    int cnt=0;
    Node* newNode = new Node(val);
    Node* prev = nullptr;
    while(temp){
        cnt++;
        if(cnt==k-1){
            newNode->next=temp->next;
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertVal(Node* head, int val, int x){
    if(head->data==x) {
        Node* newNode = new Node(val,head);
        return newNode;
    }
    Node* temp = head;
    Node* newNode = new Node(val);
    Node* prev = nullptr;
    while(temp){
        if(temp->data==x){
            newNode->next=prev->next;
            prev->next=newNode;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {12,4,7,5,1,3};
    Node* head = convertarrtoLL(arr);
    Node* temp = head;

    return 0;
}