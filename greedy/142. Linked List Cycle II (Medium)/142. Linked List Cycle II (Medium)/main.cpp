//
//  main.cpp
//  142. Linked List Cycle II (Medium)
//
//  Created by 赵桐 on 2022/9/19.
//

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head);
int main(int argc, const char * argv[]) {
    // insert code here...
    ListNode *head;
    head=new ListNode(1);
    head->next=new ListNode(2);
    head->next->next=new ListNode(3);
    head->next->next->next=new ListNode(4);
    head->next->next->next->next=head->next;
    cout<<detectCycle(head)->val;
    return 0;
}
ListNode *detectCycle(ListNode *head){
    if(head==NULL)return NULL;
    int number=1;
    auto fastPtr=head,slowPtr=head;
    if(fastPtr->next==NULL)return NULL;
    fastPtr=fastPtr->next->next;
    slowPtr=slowPtr->next;
    while(fastPtr!=NULL){
        if(number==1){
            if(slowPtr!=fastPtr){
                if(fastPtr->next==NULL)break;
                fastPtr=fastPtr->next->next;
                slowPtr=slowPtr->next;
            }else{
                fastPtr=head;
                number--;
            }
        }else{
            if(slowPtr!=fastPtr){
                if(fastPtr->next==NULL)break;
                fastPtr=fastPtr->next;
                slowPtr=slowPtr->next;
            }else{
                return fastPtr;
            }
        }
    }
    return NULL;
}
