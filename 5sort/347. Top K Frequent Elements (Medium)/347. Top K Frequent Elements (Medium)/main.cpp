//
//  main.cpp
//  347. Top K Frequent Elements (Medium)
//
//  Created by 赵桐 on 2022/9/29.
//

#include <iostream>
#include <vector>
#include<map>
using namespace std;
vector<int> topKFrequent(vector<int>& nums, int k) ;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> nums{1,2,3,4,5};
    int k=2;
    for(auto i:topKFrequent(nums, k))cout<<i;
//    std::cout << "Hello, World!\n";
    return 0;
}
vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int>numsCount;
    map<int ,int>numsCountMap;
    vector<int>returnArray;
    int m=0,max;
    for(auto i:nums){
        auto itoer=numsCountMap.find(i);
        numsCount[i]+=1;
    }
    for(int i=0;i<numsCount.size()&&m<k;i++){
        max=i;
        for(int j=0;j<numsCount.size();j++){
            if(nums[i]<nums[j])max=j;
        }
        returnArray.push_back(max);
    }
    return returnArray;
}
