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

Node* reversebetween(Node* head, int left, int right){
    if(left==right) return head;
    Node* temp = head;
    Node* prev = NULL;
    int cnt=1;
    while(temp){
        while(cnt<left){
            temp = temp->next;
            cnt++;
        }
        prev = temp; // left-1 position to link with right position element
        Node* revprev = nullptr;
        Node* curr = temp->next; //at the left position
        for(int i=0;i<right-left+1;i++){
            Node* next=curr->next;
            curr->next=revprev;
            revprev=curr;
            curr=next;
        }
        prev->next=revprev;
        prev->next->next=curr;
    }
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}