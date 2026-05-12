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
        temp=temp->next;
    }
    cout<<endl;
}
// 1 0 2 2 0 1
// 0->0->0 = zerohead     1->1->1 = onehead     2->2->2 = twohead
//       |                      |                     |
//      ptr0                   ptr1                   ptr2
Node* sort0s1s2s(Node* head){
    Node* zeroHead = new Node(0);
    Node* ptr0 = zeroHead;
    Node* oneHead = new Node(1);
    Node* ptr1 = oneHead;
    Node* twoHead = new Node(2);
    Node* ptr2 = twoHead;
    Node* temp = head;
    while(temp){
        if(temp->data==0){
            ptr0->next=temp;
        }
        else if(temp->data==1){
            ptr1->next=temp;
        }
        else{
            ptr2->next=temp;
        }
        temp=temp->next;
    }
    ptr0->next=oneHead->next;
    ptr1->next=twoHead->next;
    return zeroHead->next;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}