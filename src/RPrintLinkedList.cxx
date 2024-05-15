#include <iostream>
#include<string.h>
#include<stack>
using namespace std;

struct ListNode{
    int m_value;
    ListNode* m_next;
};
ListNode* creat(int n){
    ListNode* head = nullptr;
    ListNode* senti = nullptr;
    for(int i=0;i<n;i++){
        ListNode* node = new ListNode;
        node->m_value = i;
        node->m_next = nullptr;
        if(i==0){
            head = node;
            senti = head;
        }else{
            senti->m_next = node;
            senti = senti->m_next;
        }
    }
    return head;
}
void print(ListNode* head){
    if(head == nullptr){
        return;
    }
    ListNode* node = head;
    while(node){
        cout<<node->m_value<<" ";
        node = node->m_next;
    }
    cout<<endl;
}
void rPrint(ListNode* head){
    if(head == nullptr){
        return;
    }
    ListNode* node = head;
    stack<int> stk;
    while(node){
        stk.push(node->m_value);
        node = node->m_next;
    }
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
    cout<<endl;
}
int main()
{
    ListNode* head = nullptr;
    head = creat(10);
    print(head);
    rPrint(head);
    return 0;
}

