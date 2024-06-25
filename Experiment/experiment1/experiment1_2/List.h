//
// Created by showe on 2024/3/19.
//

#ifndef EXPERIMENT1_2_LIST_H
#define EXPERIMENT1_2_LIST_H
#include <stddef.h>
struct ListNode {
    int cof;
    int exp;
    ListNode *next;
    ListNode(int p, int n) : cof(p), exp(n), next(NULL){};
};

class List {
private:
    int size = 0;

public:
    ListNode *head;
    List();
    List(const List &another);
    ~List();
    void init();
    void input();
    void print();
    void clear();
    List operator+(const List &another) const;
};
#endif//EXPERIMENT1_2_LIST_H
