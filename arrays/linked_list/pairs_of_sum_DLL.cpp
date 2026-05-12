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

Node* findtail(Node* head){
    Node* temp = head;
    while(temp->next){
        temp=temp->next;
    }
    return temp;
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

vector <pair<int,int>> pairs(Node* head, int sum){
    Node* left = head;
    Node* right = findtail(head);
    vector <pair<int,int>> pairs;
    while(left->data < right->data){
        if(left->data + right->data==sum){
            pairs.push_back({left->data, right->data});
            left=left->next;
        }
        else if(left->data + right->data > sum){
            right = right->back;
        }
        else if(left->data + right->data < sum){
            left = left->next;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}