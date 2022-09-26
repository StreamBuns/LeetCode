//
//  main.cpp
//  76. Minimum Window Substring (Hard)
//
//  Created by 赵桐 on 2022/9/19.
//
/*
 * 子串没有强调连续性，子串可能包含重复字符的话就是另一种算法
 * 暴力求解，美剧输入字符串S的所有长度大于等于T的子串，逐个判断是否覆盖T
 * 分别统计S的子串和T中每个字符的出现次数，然后逐个对比，使用字符频数数组
 * 
 */
#include <iostream>
#include <vector>

using namespace std;
string minWindow(string s, string t) ;
string minWindow2(string s, string t) ;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s="ADOBECODEBANC",t="ABC";
    //    cin>>s>>t;
    cout<<minWindow2(s,t)<<endl;
    
    
    return 0;
}
string minWindow(string s, string t) {
    string minStr;
    unsigned long path;
    for(int i=0;i<s.size();++i){
        int flag[t.size()];
        path=t.find(s[i]);
        if(path!=string::npos){
            flag[path]=1;
            
        }
    }
    
    return minStr;
}
string minWindow2(string s, string t) {
    //    chars表示目前每个字符缺少的数量
    vector<int > chars(128,0);
    //    falg表示每个字符是否在t中存在
    vector<bool> flag(128,false);
    //先统计T中字符的情况
    for(int i = 0; i < t.size(); ++i){
        flag[t[i]]=true;
        ++chars[t[i]];
    }
    //    移动滑动窗口，不断更改统计数据
    int cnt = 0,l = 0,min_l = 0,min_size=(int)s.size()+1;
    for(int r = 0; r < s.size(); ++r){
        if(flag[s[r]]){
            if(--chars[s[r]] >= 0){
                ++cnt;
            }
            //            若目前滑动窗口已包含T中全部字符
            //            则尝试将l右移，在不影响结果的情况下获得最短子字符串
            while (cnt == t.size()) {
                if(r - l +1 < min_size){
                    min_l=l;
                    min_size=r - l + 1;
                }
                if(flag[s[l]] && ++chars[s[l]] > 0){
                    --cnt;
                }
                ++l;
            }
        }
    }
    return min_size>s.size()?"":s.substr(min_l,min_size);
}
