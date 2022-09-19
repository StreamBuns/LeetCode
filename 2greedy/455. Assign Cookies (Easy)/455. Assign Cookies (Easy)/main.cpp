//
//  main.cpp
//  455. Assign Cookies (Easy)
//
//  Created by 赵桐 on 2022/9/13.
//

/*  455. Assign Cookies (Easy)
 *题目描述
 有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩子可以吃饱。
 *输入输出样例
 输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数 量。
 Input: [1,2], [1,2,3]
 Output: 2
 */

#include <iostream>
#include <vector>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s);
int findContentChildren2(vector<int>& g, vector<int>& s);
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> eatArray,cookieArray;
    int number=-1;
    while(cin>>number){
        eatArray.push_back(number);
        if(cin.get()=='\n') break;
    }
    while(cin>>number){
        cookieArray.push_back(number);
        if(cin.get()=='\n') break;
    }
    
    cout<<findContentChildren(eatArray, cookieArray)<<endl;
    cout<<findContentChildren2(eatArray, cookieArray)<<endl;
    return 0;
}
int findContentChildren(vector<int>& g, vector<int>& s){
    int fullNumber=0,i=0,j=0;
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    for(;i<g.size();i++){
        for(;j<s.size();j++){
            if(g[i]<=s[j]){
                fullNumber++;
                j++;
                break;
            }
        }
    }
    return fullNumber;
}
int findContentChildren2(vector<int>& g, vector<int>& s){
    int fullNumber=0;
    auto iteratorEat=g.begin(),iteratorCookie=s.begin();
    
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    while(iteratorCookie!=s.end()&&iteratorEat!=g.end()){
        if((*iteratorEat)<=(*iteratorCookie)){
            fullNumber++;
            iteratorEat++;
        }
        iteratorCookie++;
    }
    return fullNumber;
}
