//
//  main.cpp
//  135. Candy (Hard)
//
//  Created by 赵桐 on 2022/9/13.
//

#include <iostream>
#include <vector>
using namespace std;

int candy(vector<int>& ratings);

int Fib(int n){//非递归的实现
    if(n==1)return 1;
    if(n==2)return 1;
    int  f1=1,f2=1,f3=0;
    for(int i=3;i<=n;i++){
        f3=f2+f1;
        f1=f2;
        f2=f3;
    }
    return f3;
}


int main(int argc, const char * argv[]) {
    // insert code here...
//    vector<int> scoreArray;
//    int score=-1;
//    while(cin>>score){
//        scoreArray.push_back(score);
//        if(cin.get()=='\n') break;
//    }
//    cout<<candy(scoreArray)<<endl;
    cout<<Fib(10000)<<"\n";
    cout<<Fib(10001)<<"\n";
    cout<<(float)Fib(10000)/(float)Fib(10001)<<"\n";
    return 0;
}
int candy(vector<int>& ratings) {
    if(ratings.size() == 0) return 0;
    if(ratings.size() == 1) return 1;
    
    int candyArray[ratings.size()];
    candyArray[0]=1;

    int number=0,itForword=0,itR=1;
    for(;itR<ratings.size();itR++){
        itForword=itR-1;
        if(ratings[itForword]>ratings[itR]){
            if(candyArray[itForword]==1){
                for(int i=itForword-1;i>=0;i--){
                    if((i-1)>=0){
                        if(ratings[i-1]==ratings[i]){
                            if(candyArray[i]!=1){
                                
                            }
                        }
                    }
                    candyArray[i+1]++;
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
    
    for(auto i:candyArray)number+=i;
    return number;
}
