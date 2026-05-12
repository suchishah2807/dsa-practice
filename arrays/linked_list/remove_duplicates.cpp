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

Node* removeduplicates(Node* head){
    Node* dummy = new Node(0, head);
    Node* prev = dummy;
    Node* temp = head;

    while(temp && temp->next){
        if(temp->data == temp->next->data){
            // inner loop: skip ALL consecutive duplicates
            while(temp->next && temp->data == temp->next->data){
                Node* del = temp->next;
                temp->next = temp->next->next;
                delete del;
            }
            // delete temp itself (last remaining duplicate)
            Node* del = temp;
            prev->next = temp->next;
            temp = temp->next;
            delete del;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
    return dummy->next;
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
    vector<int> arr = {1,1,1,1,2,3};
    Node* head = convertarrtoLL(arr);
    Node* ans = removeduplicates(head);
    Node* ptr = ans;
    while(ptr){
        cout<< ptr->data<<" ";
        ptr = ptr->next;
    }
    
    return 0;
}