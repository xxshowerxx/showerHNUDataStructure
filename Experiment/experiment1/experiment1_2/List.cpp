//
// Created by showe on 2024/3/19.
//
#include "List.h"
#include <bits/stdc++.h>
using namespace std;
List::List() { init(); }
List::List(const List &another) {
    init();
    ListNode *p1 = another.head;
    ListNode *p2 = head;
    while (p1->next != NULL) {
        p1 = p1->next;
        ListNode *p = new ListNode(p1->cof, p1->exp);
        p2->next = p;
        p2 = p2->next;
    }
    size = another.size;
}
List::~List() { clear(); }
void List::init() {
    head = new ListNode(0,0);
}
void List::input() {
    cin >> size;
    ListNode *p=head;
    for (int i = 0; i < size; ++i) {
        int c, n;
        cin >> c;
        if(c==0)continue;
        cin>>n;
        ListNode *tmp=new ListNode(c,n);
        p->next=tmp;
        p=p->next;
    }
}
void List::clear() {
    ListNode *p = head;
    while (p != NULL) {
        head = head->next;
        delete p;
        p = head;
    }
    size = 0;
}
void List::print() {
    ListNode *p = head->next;
    while (p != NULL) {
        cout << p->cof << " " << p->exp << endl;
        p = p->next;
    }
}
List List::operator+(const List &another) const {
    List ans;
    ListNode *p1 = head->next;
    ListNode *p2 = another.head->next;
    ListNode *back = ans.head;
    while (p1 != NULL || p2 != NULL) {
        if (p2 == NULL || (p1 != NULL && p2 != NULL&&p1->exp > p2->exp)) {
            ListNode *p = new ListNode(p1->cof, p1->exp);
            back->next = p;
            back = back->next;
            ans.size += 1;
            p1 = p1->next;
        } else if (p1 == NULL || (p1 != NULL && p2 != NULL&&p2->exp > p1->exp)) {
            ListNode *p = new ListNode(p2->cof, p2->exp);
            back->next = p;
            back = back->next;
            ans.size += 1;
            p2 = p2->next;
        } else {
            if(p2->cof + p1->cof==0)
            {
                p1=p1->next;
                p2=p2->next;
                continue;
            }
            ListNode *p = new ListNode(p2->cof + p1->cof, p2->exp);
            back->next = p;
            back = back->next;
            ans.size += 1;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return ans;
}