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

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<< head->data <<" ";
    }
    cout<<endl;
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

Node* remove_nodesw_GreaterEl(Node* head){
    Node* rev = reverseLL(head);
    Node* temp = rev;
    Node* prev = nullptr;
    int max = INT_MIN;
    while(temp){
        if(temp->data >= max){
            max = temp->data;
            prev = temp;
            temp = temp->next;
        }
        else{
            prev->next = temp->next;
            temp = temp->next;
        }
    }
    return reverseLL(rev);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}