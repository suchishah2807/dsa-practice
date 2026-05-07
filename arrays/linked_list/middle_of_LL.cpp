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
// brute force
// for odd number of elements the middle element exists. 
// for eg. N=5 -> 3 = N/2 + 1 = 5/2 + 1 = 2 + 1
// for even number of elements out of the 2 middle elements the second one is considered.
// for eg. N=6 -> 4 = N/2 + 1 = 6/2 + 1 = 3 + 1
Node* middleEl(Node* head){
    Node* temp = head;
    int cnt=0;
    while(temp){
        temp = temp->next;
        cnt++;
    }
    int mid = (cnt/2) + 1;
    Node* midEl = head;
    while(mid-1){
        midEl = midEl->next;
        mid--;
    }
    return midEl;
}
// Tortoise and Hare algorithm
Node* middleElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next; // moving it 1 place
        fast = fast->next->next; // moving it 2 places ahead
/* it takes fast N/2 steps to reach the last pointer that means in those same number of
iterations slow also moves N/2 steps, considering they were laready at head slow it at N/2 +1 th
position */
    }
    return slow;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}