//
//  main.cpp
//  leet1_twoSum
//
//  Created by 赵桐 on 2020/8/23.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution{
public:vector<int> twoSum(vector<int>& nums, int target) {
    

    
    
    //Hash表做法 需要两遍遍历第一遍遍历需要把数据填入到里面，第二遍便利找到对应的值。
    //一边循环，最坏2遍就能就结束因而时间复杂度为O(n)。空间复杂度由于多生成了一个hashArray所以为O(n)
    //Hash的是用空间换取时间,主要的点在于利用好Hash查找效率为O(1)的点
//    map<int,int> hashMap;
//    for(auto i=0;i<nums.size();i++){
//        hashMap.insert(map<int, int>::value_type(nums[i],i));
//    }
//    for(auto i=0;i<nums.size();i++){
//        int temp=target-nums[i];
//        if(hashMap.find(temp)!=hashMap.end()&&hashMap.find(temp)->second!=i){
//            return vector<int>{i,hashMap.find(temp)->second};
//        }
//    }
    
    //Hash一遍可以边插入边查找有没有对应的值
    map<int,int> hashMap;
    for(auto i=0;i<nums.size();i++){
        hashMap.insert(map<int, int>::value_type(nums[i],i));
        int temp=target-nums[i];
        if(hashMap.find(temp)!=hashMap.end()&&hashMap.find(temp)->second!=i){
           return  i>hashMap.find(temp)->second?vector<int>{hashMap.find(temp)->second,i}: vector<int>{i,hashMap.find(temp)->second};
        }
    }
    //暴力解法
    //vector<int> answer
//    for(auto i=0;i<nums.size()-1;i++){
//        for(auto j=i+1;j<nums.size();j++){
//            if(target==nums[i]+nums[j]){
//                if(i<j){
//                    answer.push_back(i);
//                    answer.push_back(j);
//                }else{
//                    answer.push_back(j);
//                    answer.push_back(i);
//                }
//            }
//        }
//    }
//    return answer;
    exit(1);
//    return vector<int>{1,1};
}
};
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int > nums={2,7,11,15};
    vector<int > answer;
    Solution so;
    answer=so.twoSum(nums, 9);
    for(int i:answer){
        cout<<i;
    }
    
    return 0;
}


