#include <bits/stdc++.h>
using namespace std;
class heap{
    public:
        int arr[100000];
        int size;
        
        heap(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val){
            size+=1;
            int index = size;
            arr[index]=val;

            while(index>1){
                int parent = index/2;
                if(arr[parent] < arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    return;
                }
            }
        }

        void deletefromheap(){
            if(size==0) return;
            arr[1] = arr[size]; // replace the last node as root node 
            size--; // delete the last node

            int i=1;
            while(i<size){
                int left = 2*i;
                int right = 2*i + 1;

                if(left<size && arr[left] > arr[i]){
                    swap(arr[left],arr[i]);
                }
                else if(right<size && arr[right] > arr[i]){
                    swap(arr[right],arr[i]);
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    heap h;
    h.insert(10);
    h.insert(5);
    h.insert(15);
    h.insert(30);
    h.insert(20);
    h.print();
    
    h.deletefromheap();
    h.print();
    return 0;
}