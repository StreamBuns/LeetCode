//
//  main.cpp
//  76. Minimum Window Substring (Hard)
//
//  Created by 赵桐 on 2022/9/19.
//

#include <iostream>
#include <vector>

using namespace std;
string minWindow(string s, string t) ;
int main(int argc, const char * argv[]) {
    // insert code here...
    string s,t;
    cin>>s>>t;
//    cout<<minWindow(s,t)<<endl;
    cout<<s.find("a")<<endl;
    return 0;
}
string minWindow(string s, string t) {
    string minStr;
    unsigned long path;
    for(int i=0;i<s.size();i++){
        int flag[t.size()];
        path=t.find(s[i]);
        if(path!=string::npos){
            flag[path]=1;
            
        }
    }
    
    return minStr;
}
