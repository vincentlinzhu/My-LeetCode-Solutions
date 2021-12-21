#include <iostream>
using namespace std;
#include <cmath>
#include <string>
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(){val=0; next=NULL;}
    ListNode(int x){val=x; next=NULL;}
};
//Method 1:
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        if(l2==nullptr){
            return l1;
        }
        ListNode*head=l1;
        if(l1->val > l2->val){
            head=l2;
            l2=l2->next;
        }
        else{
            l1=l1->next;
        }
        ListNode*tail=head;
        while(l1!=NULL && l2!=NULL){
            if(l1->val < l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1==NULL){
            tail->next=l2;
        }
        else{
            tail->next=l1;
        }
        return head;
    }
//Method 2:
ListNode* mergeTwoLists(ListNode*l1,ListNode*l2){
    //Base Case
    if(l1==nullptr){
        return l2;
    }
    if(l2==nullptr){
        return l1;
    }
    ListNode*v=nullptr;
    while(l1!=nullptr){
        v=l1;
        l1=l1->next;
        v->next=nullptr;
        //insert v into l2
        ListNode*c=l2;
        ListNode*a=l2->next;
        if(a==nullptr){
            a=l2;
        }
        while(a!=nullptr){
            //Establish Current and After
            if((v->val > a->val) && (a->next!=nullptr)){
                c=c->next;
                a=a->next;
            }
            //Insert at Head
            if(v->val <= l2->val){
                v->next=l2;
                l2=v;
                break;
            }
            //Insert at Tail
            if((v->val >= a->val) && (a->next==nullptr)){
                a->next=v;
                v->next=nullptr;
                break;
            }
            //Insert
            if((v->val >= c->val) && (v->val <= a->val)){
                c->next=v;
                v->next=a;
                break;
            }
        }
    }
    return l2;
}

int main(){
    ListNode *l1=new ListNode(-9);
    l1->next=new ListNode(-7);
    l1->next->next=new ListNode(-3);
    l1->next->next->next=new ListNode(-3);
    l1->next->next->next->next=new ListNode(-1);
    l1->next->next->next->next->next=new ListNode(2);
    l1->next->next->next->next->next->next=new ListNode(3);
    
    ListNode *l2=new ListNode(-7);
    l2->next=new ListNode(-7);
    l2->next->next=new ListNode(-6);
    l2->next->next->next=new ListNode(-6);
    l2->next->next->next->next=new ListNode(-5);
    l2->next->next->next->next->next=new ListNode(-3);
    l2->next->next->next->next->next->next=new ListNode(2);
    l2->next->next->next->next->next->next->next=new ListNode(4);
    ListNode*Result=mergeTwoLists(l1,l2);
    /*while(L1!=NULL) {
        cout<<L1->val<<endl;
        L1=L1->next;
    }*/
    while(Result!=NULL) {
        cout<<Result->val<<endl;
        Result=Result->next;
    }
    return 0;
}
