//
//  main.cpp
//  135. Candy (Hard)
//
//  Created by 赵桐 on 2022/9/13.
//
/*
 *把所有孩子的糖果数初始化为 1; 先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的 糖果数加 1;再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数 不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。通过这两次遍历， 分配的糖果就可以满足题目要求了。这里的贪心策略即为，在每次遍历中，只考虑并更新相邻一 侧的大小关系。
 */
/*
 *第一遍循环完成以后，第二遍循环从左往右可以不？
 *第二轮从左往右也是可以的，只需要控制好边界就行了
 *第一轮跟第二轮都是从左往右，把处理集成在一条遍历中行不。
 *不行，必须二轮循环，例如1 3 4 3 2 1，一轮循环，13比较，3比1大且糖果数不大于1，故3糖果数加一，然后到了
 *3 4比较的时候，4大，所以4是3.然后4 3比较的时候，3为2 然后3 2 比较的时候2为1 。这里2与1比较1只能为0了，因为没发往前二次调整。所以二轮循环调整两次是必要的。
 */
#include <iostream>
#include <vector>

#include<numeric>
using namespace std;

int candy(vector<int>& ratings);
int candy2(vector<int>& ratings);


int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> scoreArray;
    int score=-1;
    while(cin>>score){
        scoreArray.push_back(score);
        if(cin.get()=='\n') break;
    }
    cout<<candy2(scoreArray)<<endl;
    
    return 0;
}
int candy(vector<int>& ratings) {
    if(ratings.size() < 2) return ratings.size();
    
    int candyArray[ratings.size()];
    candyArray[0]=1;

    int number=0,itForword=0,itR=1;
    for(;itR<ratings.size();itR++){
        itForword=itR-1;
        if(ratings[itForword]>ratings[itR]){
            if(candyArray[itForword]==1){
                for(int i=itForword;i>=0;i--){
                    candyArray[i]++;
                }
            }
            candyArray[itR]=candyArray[itForword]-1;
        }
        if(ratings[itForword]==ratings[itR]){
            if(candyArray[itForword]==1)
            candyArray[itR]=candyArray[itForword];
            else candyArray[itR]=candyArray[itForword]-1;
        }
        if(ratings[itForword]<ratings[itR]){
            candyArray[itR]=candyArray[itForword]+1;
        }
    }
    for(int i=0;i<ratings.size();){
        if((i+1)>=ratings.size()){
            break;
        }
        else{
            if(ratings[i+1]==ratings[i]){
                number=i+1;
                while (ratings[number+1]==ratings[number]) {
                    number++;
                }
//                if((number-i)<2){
//                    i++;
//                    continue;
//                }
                if(i-1>=0){
                    if(ratings[i-1]>ratings[i]){
                        for(int j=i;j<number;j++){
                            candyArray[j]=1;
                        }
                    }else if(ratings[i-1]<ratings[i]){
                        for(int j=i+1;j<number;j++){
                            candyArray[j]=1;
                        }
                    }
                }
                if(i+1<ratings.size()){
                    if(ratings[i+1]>ratings[i]){
                        ratings[i]=2;
                    }else if(ratings[i+1]<ratings[i]){
                        ratings[i]=ratings[i+1]+1;
                    }
                }
                i+=number;
            }else{
                i++;

            }
        }
    }
    number=0;
    for(auto i:candyArray)number+=i;
    return number;
}

int candy2(vector<int>& ratings) {
    int size = (int)ratings.size();
        if (size < 2) {
           return size;
        }
        vector<int> num(size, 1);
        for (int i = 1; i < size; ++i) {
           if (ratings[i] > ratings[i-1]) {
               num[i] = num[i-1] + 1;
    } }
        for (int i = size - 1; i > 0; --i) {
           if (ratings[i] < ratings[i-1]) {
               num[i-1] = max(num[i-1], num[i] + 1);
           }
    }
    return accumulate(num.begin(), num.end(), 0); // std::accumulate 可以很方便地求和
}

