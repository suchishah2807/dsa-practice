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

Node* middleElement(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next; // moving it 1 place
        fast = fast->next->next; // moving it 2 places ahead
    }
    return slow;
}

bool checkPalindrome(Node* head){
    Node* head1 = head;
    Node* mid = middleElement(head1);
    Node* head2 = mid->next;
    mid->next = nullptr;
    Node* rev = reverseLL(head2);
    Node* temp1 = head1;
    Node* temp2 = rev;
    while(temp1 && temp2){
        if(temp1->data != temp2->data) return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
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