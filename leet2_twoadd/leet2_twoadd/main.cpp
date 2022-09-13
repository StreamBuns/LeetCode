//
//  main.cpp
//  leet2_twoadd
//
//  Created by 赵桐 on 2020/9/2.
//  Copyright © 2020 赵桐. All rights reserved.
//
/*
 第二题两数之和
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 示例：

 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 来源：力扣（LeetCode）

 解题思路就是把数相加然后放在随便一个链表里面（我是保存在l2里面，所以最后只需要返回l2的首地址就可以）
要点1:要判定有没有进位carry，如果有进位那么下一个数相加的时候就要+1
要点2:判定当一个链表到头的时候，是不是我们要返回的链表如果不是那么需要把另外的链表挪到我们要返回的链表
要点3:在要点2的基础上要判定有没有进位，如果有进位，那么需要考虑到进位分为
 伪代码
 while（链表1链表2都没有到头）{
    链表2的值等于链表2的值加上链表1的值如果有进位加上进位
    超过10需要进位
 }
 if 无进位
  then if 链表1到头
       else 链表2到头
       fi
 
 else 无进位
  then if 链表1到头
       else 链表2到头
       fi
 fi
 */
#include <iostream>
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=l2;
        ListNode* pl2=nullptr;
        int carry=0;
        while(NULL!=l1&&NULL!=l2){
            l2->val+=l1->val+carry;
            carry=0;
            if(l2->val>=10){
                l2->val-=10;
                carry++;
            }
            l1=l1->next;
            pl2=l2;
            l2=l2->next;
        }
        if(carry==0){
            if(NULL==l1)return temp;
            else{
                while(NULL!=l1){
                    pl2->next=l2=new ListNode(l1->val);
                    pl2=l2;
                    l2=l2->next;
                    l1=l1->next;
                }
                return temp;
            }
        }else{
            if(NULL==l1){
                if (NULL!=l2) {
                    while(l2!=NULL){
                        l2->val=l2->val+carry;
                        carry=0;
                        if(l2->val>=10){
                            l2->val-=10;
                            carry++;
                        }
                        pl2=l2;
                        l2=l2->next;
                    }
                    if(carry!=0){
                        pl2->next=new ListNode(1);
                    }
                    return temp;
                }else{
                    pl2->next=new ListNode(1);
                    return temp;
                }
            }else{
                while(NULL!=l1){
                    pl2->next=l2=new ListNode(l1->val);
                    l2->val=l2->val+carry;
                    carry=0;
                    if(l2->val>=10){
                        l2->val-=10;
                        carry++;
                    }
                    pl2=l2;
                    l2=l2->next;
                    l1=l1->next;
                }
                if(carry!=0){
                    pl2->next=new ListNode(1);
                }
                return temp;
            }
        }
    }
};
int main(int argc, const char * argv[]) {
    // insertcode here...
    ListNode* l1;
    ListNode* l2 = nullptr;
    ListNode* anwser;
    l1=new ListNode(9);
    l1->next=new ListNode(9);
//    l1->next->next=new ListNode(3);
    l2=new ListNode(9);
//    l2->next=new ListNode(6);
//    l2->next->next=new ListNode(4);
    Solution so;
    anwser=so.addTwoNumbers(l1, l2);
    while(NULL!=anwser){
        std::cout<<anwser->val;
        anwser=anwser->next;
    }
    std::cout << "Hello, World!\n";
    return 0;
}
