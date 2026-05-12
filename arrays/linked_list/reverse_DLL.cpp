#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next; //pointer to the next element
    Node* back; 

    public:
    Node(int data1, Node* next1, Node* back1){
        data=data1;
        next=next1;
        back=back1;
    }
    public:
    Node(int data1){
        data=data1;
        next=nullptr; //for the last element the pointer of next element is null pointer
        back=nullptr;
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

Node* convertarrtoDLL(vector <int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* reverseDLL(Node* head){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        Node* nextNode = temp->next;
        temp->next = prev;
        temp->back = nextNode;
        if(prev) prev->back = temp;
        prev = temp;
        temp = nextNode;
    }
    return prev;
}

void print(Node* head){
    Node* temp = head;
    while(temp){
        cout<< head->data <<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {1,2,3,4,5,6,7};
    Node* head = convertarrtoDLL(arr);
    Node* rev = reverseDLL(head);
    print(rev);
    return 0;
}