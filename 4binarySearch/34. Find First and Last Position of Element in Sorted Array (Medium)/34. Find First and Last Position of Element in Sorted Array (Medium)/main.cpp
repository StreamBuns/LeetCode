//
//  main.cpp
//  34. Find First and Last Position of Element in Sorted Array (Medium)
//
//  Created by 赵桐 on 2022/9/26.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target);
int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<int> nums={5,7,7,8,8,10};
    vector<int> nums={1,4};
    nums=searchRange(nums, 4);
    for(auto i:nums)
        cout<<i;
    std::cout << "\n";
    return 0;
}
vector<int> searchRange(vector<int>& nums, int target){
    if(nums.empty()) return  vector<int >{-1,-1};
//    int lower,upper;
    
    vector<int> returnArray;
    if(nums.size()<=0) return returnArray={-1,-1};

        
    int left=0,right=(int)nums.size()-1;
    int mid=(left+right)/2;
    while(nums[mid]!=target&&left<right){
        if(nums[mid]>target){
            right=mid;
            mid=(left+mid)/2;
        }else{
            left=mid+1;
            mid=(right+left)/2;
        }
    }
    
    if(nums[mid]!=target)return returnArray={-1,-1};
    while(mid>=0&&nums[mid]==target)mid--;
    mid++;
    returnArray.push_back(mid);
    while(mid<nums.size()&&nums[mid]==target)mid++;
    returnArray.push_back(--mid);
    return returnArray;
}
