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

// returning the node at which cycle begins
// brute force
// 1 -> 2 -> 3 -> 4 -> 5 -> 2
// we know that the node where cycle begins has 2 incoming arrows meaning that it is ->next for
// 2 other nodes so we again made a hashmap to check for the count of it.
Node* cyclebegins(Node* head){
    Node* temp = head;
    unordered_map <Node*,int> cnt;
    while(temp){
        temp=temp->next;
        cnt[temp]++;
        if(cnt[temp]>1) return temp;
    }
}
// Tortoise and Hare's algo
Node* detectNode(Node* head){
    Node *slow = head, *fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
        return slow;
        }
    }
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