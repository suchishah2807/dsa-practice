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
    while(head){
        cout << head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}
/*
// using stack in O(2n)
Node* reverseLL(Node*head){
    Node* temp = head;
    stack <int> st;
    while(temp){
        st.push(temp->data);
        temp=temp->next;
    }
    Node* temp2 = head;
    while(temp2){
        temp2->data=st.pop();
        temp2=temp2->next;
    }
    return head;
}
*/
// using iterative method
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
// using recursion
Node* reverse(Node* head){
    // base case for 1 node
    if(head==NULL || head->next==NULL) return head;
    // recursive step
    Node* newHead = reverse(head->next);
    Node* front = head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {12,4,7,5,1,3};
    Node* head = convertarrtoLL(arr);

    print(head);
    return 0;
}