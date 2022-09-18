//
//  main.cpp
//  167. Two Sum II - Input array is sorted (Easy)
//
//  Created by 赵桐 on 2022/9/17.
//

#include <iostream>
#include <vector>

using namespace std;
vector<int> twoSum(vector<int>& numbers, int target);
int main(int argc, const char * argv[]) {
    // insert code here...
    int target;
    vector<int> numbers;
    while(cin>>target){
        numbers.push_back(target);
        if(cin.get()=='\n')break;
    }
    cin>>target;
    for(auto i:twoSum(numbers, target))
        cout<<i<<"\t";
    
    cout << "\n";
    return 0;
}
vector<int> twoSum(vector<int>& numbers, int target){
    vector<int> returnArray;
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<numbers.size();){
        for(int j=(int)numbers.size()-1;j>i;){
            if(numbers[i]+numbers[j]==target){
                returnArray.push_back(i+1);
                returnArray.push_back(j+1);
                return returnArray;
            }
            else if(numbers[i]+numbers[j]>target){
                j--;
            }
            else if(numbers[i]+numbers[j]<target){
                i++;
            }
        }
    }
    return returnArray;
}
