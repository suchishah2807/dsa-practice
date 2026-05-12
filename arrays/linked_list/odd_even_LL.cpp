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
// 1->2->3->4->5->6->7->null
// 1->3->5->7->2->4->6->null
// 1->next = 1->next
// 1->2->null = 1->2->null
// 1->2->3->null = 1->3->2->null
// 1->3<-2 odd=3 even=2
//    |
//   null
// 1->3 2->null odd=3 even=null

Node* oddevenLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* evenHead = head->next;
    while(even!=NULL || even->next!=NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next=evenHead;
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {1,2,3,4,5,6,7};
    Node* head = convertarrtoLL(arr);
    Node* result = oddevenLL(head);
    print(result);
    

    return 0;
}