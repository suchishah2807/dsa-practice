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

Node* deletehead(Node* head){
    if(!head || !head->next) return nullptr;
    Node* newhead = head->next;
    newhead->back = nullptr;
    delete head;
    return newhead;
}

Node* deletetail(Node* head){
    if(!head->next){ delete head; return nullptr; }
    Node* temp = head;
    while(temp->next->next){
        temp = temp->next;
    }
    Node* tail = temp->next;
    temp->next = nullptr;
    delete tail;
    return head;
}
// [1,2,3,4,5,6,7] val=3
Node* deletevalue(Node* head, int val){
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        if(val==head->data){
            Node* delhead = head;
            Node* newhead = head->next;
            newhead->back=nullptr;
            delete delhead;
            return newhead;
        }
        else if(temp->data==val){
            Node* delNode = temp;
            prev->next=temp->next;
            temp->next->back=prev;
            delete delNode;
            return head;
        }
        else if(temp->next==nullptr || temp->data==val){
            prev->next = nullptr;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* deleteposition(Node* head, int n){
    Node* temp = head;
    Node* prev = nullptr;
    int cnt=1;
    while(temp){
        if(cnt==1){
            Node* delhead = head;
            Node* newhead = head->next;
            newhead->back=nullptr;
            delete delhead;
            return newhead;
        }
        else if(cnt==n){
            Node* delNode = temp;
            prev->next=temp->next;
            temp->next->back=prev;
            delete delNode;
            return head;
        }
        else if(temp->next==nullptr){
            prev->next=nullptr;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
    return head;
}
// 0-2-3-4-5-6 head=2
// newhead 1
Node* inserthead(Node* head, int val){
    Node* newhead = new Node(val, head, nullptr);
    head->back = newhead;
    return newhead;
}
// 0-1-2-3-4-5 tail=5
// newtail = 6
Node* inserttail(Node* head, int val){
    Node* temp = head;
    while(temp->next){
        temp = temp->next;
    }
    Node* newtail = new Node(val,nullptr,temp);
    temp->next = newtail;
    return head;
}

Node* insertval(Node* head, int val, int x){
    Node* newNode = new Node(val);
    Node* temp = head;
    Node* prev = nullptr;
    while(temp){
        if(temp->data==x){
            newNode->next=temp;
            newNode->back=prev;
            prev->next=newNode;
            temp->back=newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
}

Node* insertposition(Node* head, int val, int k){
    Node* newNode = new Node(val);
    Node* temp = head;
    Node* prev = nullptr;
    int cnt=1;
    while(temp){
        if(cnt==k){
            newNode->next=temp;
            newNode->back=prev;
            prev->next=newNode;
            temp->back=newNode;
            return head;
        }
        prev = temp;
        temp = temp->next;
        cnt++;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector <int> arr = {1,2,3,4,5};

    

    return 0;
}