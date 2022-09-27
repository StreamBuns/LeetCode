//
//  main.cpp
//  69. Sqrt(x) (Easy)
//
//  Created by 赵桐 on 2022/9/20.
//

#include <iostream>
int mySqrt(int x);
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int number=2147395599;
//    int b=1;
//    cout<<b;
    std::cout << mySqrt(number);
    return 0;
}
int mySqrt(int x) {
    if(x<=0)return 0;
    long long int l=1,r=x;
    long long int mid=(l+r)/2;
    while(!(mid*mid<=x&&(mid+1)*(mid+1)>x)){
        if(mid*mid>x){
            r=mid;
            mid=(l+mid)/2;
        }
        else{
            l=mid;
            mid=(r+mid)/2;
        }
    }
    return mid;
}
