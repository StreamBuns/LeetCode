//
//  main.cpp
//  leet3_lengthOfLongestSubstring
/*3. 无重复字符的最长子串
难度
中等


给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 
思路：
    1：暴力循环解答
    直接建立窗口然后便利里面有无相同的字符如果有则改变窗口，无则窗口字符+1
    最后只要比较当前窗口的字符数与之前最大的窗口长度
 例如abcabcbb为例，当窗口abc遇到a是窗口变为bc同时在变长度之前记录最大的窗口值3
    2:用哈希表优化，哈希表可以利用O(1)的搜索速度
*/
//  Created by 赵桐 on 2020/9/7.
//  Copyright © 2020 赵桐. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //暴力解答
        //直接建立窗口然后便利里面有无相同的字符如果有则改变窗口，无则窗口字符+1
        //最后只要比较当前窗口的字符数与之前最大的窗口长度
//        string windows="";
//        int maxLength=0,sLength=(int)s.length(),wLength;
//        for(int i=0;i<sLength;i++){
//            wLength=(int)windows.length();
//            for(int j=0;j<wLength;j++){
//                if(s[i]==windows[j]){
//                    maxLength=maxLength>(int)windows.length()?maxLength:(int)windows.length();
//                    windows=windows.substr(j+1,windows.length());
//                    break;
//                }
//            }
//            windows+=s[i];
//        }
//        return (int)windows.length()>maxLength?(int)windows.length():maxLength;
        
        //使用hash表进行了改进
//        struct MapFinder{
//        public:
//            MapFinder(const char& tempString):compareString(tempString){};
//                bool operator ()(const map<int, char>::value_type &pair)
//            {
//                return pair.second == compareString;
//            }
//        private:
//           const char& compareString;
//        };
//        map<int,char> hashMap;
//        map<int,char> windowsHashMap;
//        int sLength=(int)s.length(),maxLength=0;
//        map<int ,char >::iterator tempIterator;
//        for (int i=0; i<sLength; i++) {
//            hashMap.insert(map<int ,char>::value_type(i,s[i]));
//            tempIterator=find_if(windowsHashMap.begin(), windowsHashMap.end(),MapFinder(s[i]));
//            if(tempIterator!=windowsHashMap.end()){
//                maxLength=max((int)windowsHashMap.size(),maxLength);
//                while(tempIterator!=windowsHashMap.begin()&&!windowsHashMap.empty()){
//                    windowsHashMap.erase(tempIterator--);
//                }
//               windowsHashMap.erase(tempIterator--);
//            }
//            windowsHashMap.insert(map<int,char>::value_type(i,s[i]));
//        }
//        return max((int)windowsHashMap.size(),maxLength);
        
        //改进的Hash表
        map<char,int> hashMap;
        int sLength=(int)s.length(),maxLength=0;
        map<char,int >::iterator tempIterator;
        int i,k=0;
        string ans,tep;
        for (i=0; i<sLength; i++) {
            tempIterator=hashMap.find(s[i]);
            if(tempIterator!=hashMap.end()){
                if(maxLength==0){
                maxLength=max(i-k,maxLength);
                k=tempIterator->second;
                }else{
                k=tempIterator->second;
                maxLength=max(i-k,maxLength);
                }
            }else {
                if(maxLength!=0)
                maxLength++;
            }
            hashMap[s[i]]=i;
        }
        if (k==0) {
            return (int)hashMap.size();
        }
        return max(i-k-1,maxLength);
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    string s="abcabcbb";
    s="au";
    s="pwwkew";
//    s="bbbb";
//    s="ynyo";
//    s="jbpnbwwd";
//    s="ohomm";
    Solution solution;
    cout<<solution.lengthOfLongestSubstring(s);
//    string windows="";
//    int maxLength=1,position=-1;
//    for(int i=0;i<s.length()-1;i++){
//        windows+=s[i];
//        for(int j=0;j<windows.length();j++){
//            if(s[i+1]==windows[j]){
//                position=j;
//                windows=windows.substr(position+1,windows.length());
//                break;
//            }
//        }
//        if(-1!=position){
//            position=-1;
//            maxLength=maxLength>(int)windows.length()+1?maxLength:(int)windows.length()+1;
//        }
//        cout<<s[i]<<endl;
//    }
//    if(windows.length()>=maxLength){
//        cout<<windows.length();
//    }
//    else cout<<maxLength;
    return 0;
}
