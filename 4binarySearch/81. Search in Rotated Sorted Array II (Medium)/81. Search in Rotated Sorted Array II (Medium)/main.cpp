//
//  main.cpp
//  81. Search in Rotated Sorted Array II (Medium)
//
//  Created by 赵桐 on 2022/9/27.
//

#include <iostream>
#include <vector>
using namespace std;
bool search(vector<int>& nums, int target);
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{2,5,6,0,0,1,2};
    std::cout << search(nums,0)<<"\n";
    return 0;
}
bool search(vector<int>& nums, int target){
    int left1=0,left2=nums.size()-1,mid1,mid2,right1=nums.size()-1,right2=nums.size()-1;
    for(int i=0;i<nums.size();i++){
        if(i+1<nums.size()){
            if(nums[i]>=nums[i+1]){
                right1=left2=i;
                break;
            }
        }
    }
    while(left1<right1){
        mid1=(left1+right1)/2;
        if(nums[mid1]==target)return true;
        else if(nums[mid1]>target){
            right1=mid1;
        }else{
            left1=mid1;
        }
    }
    
    while(left2<right2){
        mid1=(left2+right2)/2;
        if(nums[mid2]==target)return true;
        else if(nums[mid2]>target){
            right2=mid2;
        }else{
            left2=mid2;
        }
    }
    return false;
}
