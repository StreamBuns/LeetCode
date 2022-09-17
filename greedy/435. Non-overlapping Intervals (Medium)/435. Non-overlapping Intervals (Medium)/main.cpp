//
//  main.cpp
//  435. Non-overlapping Intervals (Medium)
//
//  Created by 赵桐 on 2022/9/15.
//
/*
 * 题目描述
给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
输入输出样例
输入是一个数组，数组由多个长度固定为 2 的数组组成，表示区间的开始和结尾。输出一个 整数，表示需要移除的区间数量。
Input: [[1,2], [2,4], [1,3]]
Output: 1
在这个样例中，我们可以移除区间 [1,3]，使得剩余的区间 [[1,2], [2,4]] 互不重叠。
 */

/*
 * 这个直接将不同的区间，按照区间结尾进行排序，然后判断区间头是否在区间结尾，接下来的区间头大于等于
 *上一个区间的结尾则不用排除，否则则需要排除
 */
#include <iostream>
#include <vector>

using namespace std;
int eraseOverlapIntervals(vector<vector<int>>& intervals) ;
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> intervals;
    int numberLow,numberHigh;
    while(cin>>numberLow>>numberHigh){
        vector<int> temp;
        temp.push_back(numberLow);
        temp.push_back(numberHigh);
        intervals.push_back(temp);
        if(cin.get()=='\n')break;
    }
    cout<< eraseOverlapIntervals(intervals);
    return 0;
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    int tail,number=0;
//    for(int i=0;i<intervals.size();i++){
//        for(int j=i;j<intervals.size();j++){
//            if(intervals[i].data()[1]>intervals[j].data()[1]){
//                swap(intervals[i], intervals[j]);
//            }
//        }
//    }
    //使用lanmda表达式来排序，否则自己实现的排序算法会超时
    sort(intervals.begin(), intervals.end(), [](const vector<int>&a, const vector<int>&b){
        return a[1]<b[1]; // 降序
    });
    
    tail=intervals[0][1];
    for(int i=1;i<intervals.size();i++){
        if(intervals[i][0]>=tail)
            tail=intervals[i][1];
        else
            number++;
    }
    return number;
}
