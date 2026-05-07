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
// 1 -> 2 -> 3 -> 4 -> 5 -> 6
// head
// curr front
// prev = null
// 1 <-> 2  3 -> 4
// null <- 1 <- 2  3 -> 4
//         prev   curr  front
// null <- 1 <- 2  3 <- 4  5 -> 6
//         prev   curr  front
// 2 -> 1 -> 4 -> 3     5 -> 6
//                prev  curr front
// 2 -> 1 -> 4 -> 3     5 <-> 6
//                prev  curr front
// 2 -> 1 -> 4 -> 3 -> 6 ->  5
//                prev front curr

Node* swapPairs(Node* head){
    if(!head || !head->next) return head; // single element no swapping
    
    Node* curr = head;
    Node* prev = nullptr;
    Node* ptr = nullptr;
    
    head = curr->next;
    
    while(curr && curr->next){  // check both exist
        Node* front = curr->next;
        ptr = front->next; // i.e curr->next->next to get alternate elements for swapping pairs
        front->next = curr;
        if(prev) prev->next = front;  // only if prev exists
        curr->next = ptr;       // curr points to remaining list
        prev = curr;
        curr = ptr;
    }
    return head;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}