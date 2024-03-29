//
//  main.cpp
//  88. Merge Sorted Array (Easy)
//
//  Created by 赵桐 on 2022/9/18.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n);
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int >nums1,nums2;
    int m,n;
    while(cin>>m){
        nums1.push_back(m);
        if(cin.get()=='\n')break;
    }
    cin>>m;
    while(cin>>n){
        nums2.push_back(n);
        if(cin.get()=='\n')break;
    }
    cin>>n;
    merge2(nums1, m, nums2, n );
    for(auto i:nums1){
        cout<<i<<'\t';
    }
    cout<<'\n';
    return 0;
}
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    for(int i=0;i<n;i++){
        nums1[m++]=nums2[i];
    }
    sort(nums1.begin(), nums1.end());
}
void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int pos=m-- +n-- -1;
    while(m>=0&&n>=0&&pos>=0){
        nums1[pos--]=nums1[m]>=nums2[n]?nums1[m--]:nums2[n--];
    }
    while(n>=0){
        nums1[pos--]=nums2[n--];
    }
}
