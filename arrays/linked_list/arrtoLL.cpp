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
int checkifPresent(Node* head, int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return 1;  
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {12,4,7,5,1,3};
    Node* head = convertarrtoLL(arr);
    Node* temp = head;
    int cnt=0; //length of LL
    while(temp){
        cout<< temp->data<<" ";
        temp = temp->next;
        cnt++;
    }
    cout<<endl;
    cout<<cnt<<endl;
    cout<<checkifPresent(head, 5);    
    return 0;
}