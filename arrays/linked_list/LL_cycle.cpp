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
// basically just create a hashmap and check if that node has already been visited. if yes
// then return true
bool hasCycle(Node* head){
    unordered_map <Node*, int> cnt;
    Node* temp = head;
    while(temp){
        cnt[temp]++;
        if(cnt[temp]>1) return true;
        temp = temp->next;
    }
    return false;
}
// Tortoise and Hare algorithm
bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow==fast) return true; // just on basis of observations
    }
    return false;
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