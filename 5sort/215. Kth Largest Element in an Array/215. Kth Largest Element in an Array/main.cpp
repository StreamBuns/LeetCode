//
//  main.cpp
//  215. Kth Largest Element in an Array(Medium)
//
//  Created by 赵桐 on 2022/9/29.
//
//
/*
 *第k个数
 * 暴力解法即直接排序然后选取输出
 *
 * 好一点的方法就是使用快速排序的定桩法
 * 我们知道快速排序每一轮循环都会确定一个数的最终位置，所以我们只要找到最终位置为k的数就可以停止了就不需要继续进行了
 
 */
//

#include <iostream>
#include <vector>
using namespace std;
int findKthLargest(vector<int>& nums, int k);
int findKthLargest2(vector<int>& nums, int k);
int findKthLargest3(vector<int>& nums, int k);
int quickSelection(vector<int>& nums, int l, int r) {
    int i = l + 1, j = r;
    while (true) {
       while (i < r && nums[i] <= nums[l]) {++i;}
       while (l < j && nums[j] >= nums[l]) { --j; }
       if (i >= j) {break;}
       swap(nums[i], nums[j]);}
    swap(nums[l], nums[j]);
    return j;
}
void quick_sort(vector<int> &nums, int l, int r);
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,2,3,4,5,6,7,8,9};
    int k=3;
    cout<<findKthLargest(nums, k);
    cout<<findKthLargest2(nums, k);
    cout<<findKthLargest3(nums, k);
    std::cout << "Hello, World!\n";
    return 0;
}
int findKthLargest(vector<int>& nums, int k){
    sort(nums.begin(),nums.end());
    return  nums[nums.size()-k];
}

void quick_sort(vector<int> &nums, int l, int r) {
    if (l + 1 >= r) return;
    int first = l, last = r - 1, key = nums[first];
    while (first < last){
       while(first < last && nums[last] >= key) {
           --last;
       }
       nums[first] = nums[last];
       while (first < last && nums[first] <= key) {
           ++first;
       }
       nums[last] = nums[first];
        
    }
    nums[first] = key;
    quick_sort(nums, l, first);
    quick_sort(nums, first + 1, r);
}
int findKthLargest2(vector<int>& nums, int k){
    int l = 0, r = nums.size() - 1, target = nums.size() - k;
    while (l<r) {
        int mid;
        int i = l + 1, j = r;
        while(true){
            while(i<r&&nums[i]<=nums[l]){++i;}
            while(l<j&&nums[j]>=nums[l]){--j;}
            if(i>=j)break;
            swap(nums[i], nums[j]);
        }
        swap(nums[l],nums[j]);
        mid = j;
        if (mid == target) {
            return nums[mid];
        }
        if (mid < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
     }
     return nums[l];
}
int findKthLargest3(vector<int>& nums, int k){
    
    int l = 0, r = nums.size() - 1, target = nums.size() - k;
       while (l < r) {
          int mid = quickSelection(nums, l, r);
          if (mid == target) {
              return nums[mid];
          }
          if (mid < target) {
              cout<<"3:"<<l<<"\n";
              l = mid + 1;
          } else {
              cout<<"3:"<<r<<"\n";
              r = mid - 1;
          }
       }
       return nums[l];
}
