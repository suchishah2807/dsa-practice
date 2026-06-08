#include <bits/stdc++.h>
using namespace std;
// for kth largest use min heap
// for kth smallest use max heap
class heap{
    public:
        int arr[100000];
        int size;
        
        heap(){
            arr[0]=-1;
            size=0;
        }
        // basically our concept is that we keep filling the arr(i.e min heap tree) but we restrict the size to k. as soon as there
        // is element added to arr of size k, we insert it and then remove the root node. that maintains the size k of our min heap
        // and as it is a min heap the top has minimum element and bottom has maximum element since we are only keeping k elements
        // it makes sure the root node is kth largest
        void insert(int val, int k){
            size+=1;
            int index = size;
            arr[index]=val;

            while(index>1){
                int parent = index/2;
                if(arr[parent] > arr[index]){
                    swap(arr[parent],arr[index]);
                    index = parent;
                }
                else{
                    break;
                }
            }
            if(size>k) deletefromheap();
        }

        void deletefromheap(){
            if(size == 0) return;
            arr[1] = arr[size];
            size--;
            int i = 1;
            while(i <= size){
                int left = 2*i;
                int right = 2*i+1;
                int smallest = i;
                if(left <= size && arr[left] < arr[smallest]) smallest = left;
                if(right <= size && arr[right] < arr[smallest]) smallest = right;
                if(smallest == i) break;
                swap(arr[i], arr[smallest]);
                i = smallest;
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
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    heap h;
    for(int i=0;i<nums.size();i++){
        h.insert(nums[i],k);
    }

    int ans = h.arr[1];

    return 0;
}