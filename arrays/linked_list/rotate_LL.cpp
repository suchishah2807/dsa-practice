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
// 1->2->3->4->5
// 4->5->1->2->3
Node* rotate_ll(Node* head, int k){
    int l=0; // length of linked list
    Node* temp = head;
    while(temp){
        temp=temp->next;
        l++;
    }
    Node* slow = head;
    Node* fast = head;
    Node* h = head;
    if(k%l==0) return head; // if we rotate list in multiples of its length we will get same list
    int cnt = k%l;
    while(cnt){ // for cases where k>l we use the modulo as rotating it by its own length gives lsit itself
        fast = fast->next;
        cnt--;
    }
    while(fast->next){
        fast = fast->next;
        slow = slow->next;
    }
    // now slow is at k+1th position from back
    Node* rotatehead = slow->next;
    Node* rotatenode = rotatehead;
    slow->next = nullptr;
    while(rotatenode->next){
        rotatenode = rotatenode->next;
    }
    rotatenode->next = h;
    return rotatehead;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}