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
    while(head != NULL ){
        cout<< head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* removeHead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    temp=head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    Node* temp = head;
    if(head == NULL || head->next == NULL) return nullptr;
    while(temp->next->next != NULL){ // to find second last element
        temp=temp->next;
    }
    delete temp->next; // delete last element i.e tail
    temp->next=nullptr; // assogn null pointer as next pointer of new tail(previous second last)
    return head;
}

Node* removekthelement(Node* head, int k){
    if(head == NULL ) return head;

    if(k==1){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    int cnt=0;
    Node* prev = nullptr;
    while(temp){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp; 
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* removeEl(Node* head, int el){
    if(head == NULL ) return head;

    if(head->data==el){
        Node* temp = head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        if(temp->data==el){
            prev->next=prev->next->next;
            delete temp; 
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {12,4,7,5,1,3};
    Node* head = convertarrtoLL(arr);
    Node* temp = head;
    

    return 0;
}