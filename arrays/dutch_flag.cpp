#include <bits/stdc++.h>
using namespace std;
void quicksort(vector <int>& nums, int low, int high){
    if(low >= high) return;
    
    int pivot = nums[low + rand() % (high - low + 1)];
    int lt = low; // end index where all elements are less than(lt) pivot
    int gt = high; // start index all elements are greater than(gt) pivot 
    int i = low; // current index
    while(i<gt){
        if(nums[i]<pivot){
            swap(nums[i],nums[lt]);
            i++;
            lt++;
        }
        else if(nums[i]>pivot){
            swap(nums[i],nums[gt]);
            i++;
            gt++;
        }
    }
    // all indexes between lt to gt have same elements
    quicksort(nums,low,lt-1);
    quicksort(nums,gt+1,high);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}