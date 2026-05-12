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
// a1->a2->[c1->c2->c3]
// b1->b2->b3->[c1->c2->c3]

Node* getIntersectionNode(Node* headA, Node* headB) {
    Node* ptr1 = headA;
    Node* ptr2 = headB;

    while(ptr1 != ptr2){
        // if ptr1 reaches end, redirect to headB
        if(ptr1 == nullptr)
            ptr1 = headB;
        else
            ptr1 = ptr1->next;

        // if ptr2 reaches end, redirect to headA
        if(ptr2 == nullptr)
            ptr2 = headA;
        else
            ptr2 = ptr2->next;
    }
    return ptr1;  // either intersection node or nullptr
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