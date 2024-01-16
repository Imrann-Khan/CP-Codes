#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int store_index = left;
    
    for (int i = left; i < right; ++i)
    {
        if (nums[i] > pivot) 
        {
            swap(nums[i], nums[store_index]);
            ++store_index;
        }
    }
    swap(nums[store_index], nums[right]);
    return store_index;
}

int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left <= right) 
    {
        int pivot_index = partition(nums, left, right);
        
        if (pivot_index == k) //if pivot index is equal k, then we found kth largest element inthe array
        { 
            return nums[pivot_index];
        } 
        else if (pivot_index < k) 
        {
            return quickselect(nums, pivot_index + 1, right, k);
        } 
        else 
        {
            return quickselect(nums, left, pivot_index - 1, k);
        }
    }
    
    return -1; // Not found
}

int findKthLargest(vector<int>& nums, int k) {
    if( (k>=1 && k<=105) && (k<=nums.size()) )
        return quickselect(nums, 0, nums.size() - 1, k - 1);
    else return -1; //contraints doesn't matched
}

int main() {
    vector<int> nums;
    int k;
    int size; //array size
    cin>>size;
    for(int i=0;i<size;i++)
    {
        int k; cin>>k;
        if(k>=-104 && k<=104)
            nums.push_back(k);
        else return -1; //contraints doesn't matched
    }
    cin>>k;
    cout << findKthLargest(nums, k) << endl; 
}
