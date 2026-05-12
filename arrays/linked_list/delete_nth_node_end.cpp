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
// brute force in O(2n)
Node* nthnodefromend(Node*head,int n){
    Node* temp = head;
    int cnt=0;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    int i = n - cnt;
    if(i==n) return head->next;
    Node* ptr = head;
    int num = 0;
    while(ptr){
        if(num == i){
            Node* delNode = ptr->next;
            ptr->next = ptr->next->next;
            delete delNode;
            return head;
        }
    }
}
// Tortoise and hare's algo
Node* nth_node_from_end(Node* head, int n){
    Node* slow = head;
    Node* fast = head;
    // move fast pointer by n steps
    while(n){
        fast=  fast->next;
        n--;
    }
    // edge case: if fast is null, head itself needs to be deleted
    if(fast == nullptr){
        head = head->next;
        return head;
    }
    // now move both simultaneously, which ensures slow moves N-n steps to land on node just
    // before the one whihc we want to remove
    while(fast){
        slow = slow->next;
        fast = fast->next;
    }
    Node* deleteNode = slow->next;
    slow->next = slow->next->next;
    delete deleteNode;
    return head;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<< head->data <<" ";
    }
    cout<<endl;
}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}