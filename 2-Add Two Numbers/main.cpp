#include <math.h>
#include <iostream>
using namespace std;

/*
1. change list into int and sum int, change back to list. But this makes listnode meaningless. Int can't deal with big number

2. 
*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    void show() {
        if (next) {
            next->show();
        }
        cout << val;
    }
};


ListNode* int2list(int a) {
    ListNode *s;
    ListNode *p;
    int n;
    if (a > 9) {
        n = a % 10;
        s = p = new ListNode(n);
        a = (a - n) / 10;
    } else {
        s = new ListNode(a);
        return s;
    }
    while (a > 9) {
        n = a % 10;
        p->next = new ListNode(n);
        p = p->next;
        a = (a - n) / 10;
    }
    p->next = new ListNode(a);
    return s;
}

 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res;
        ListNode *p;
        int carry_bit = 0;
        int tmp = l1->val + l2->val;
        if (tmp > 9) {
            tmp -= 10;
            carry_bit = 1;
        } else carry_bit = 0;
        res = p = new ListNode(tmp);
        l1 = l1 -> next;
        l2 = l2 -> next;
        while (l1 && l2) {
            tmp = l1->val + l2->val + carry_bit;
            if (tmp > 9) {
                tmp -= 10;
                carry_bit = 1;
            } else carry_bit = 0;
            p->next = new ListNode(tmp);
            p = p->next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while (l1) {
            tmp = l1->val + carry_bit;
            if (tmp > 9) {
                tmp -= 10;
                carry_bit = 1;
            } else carry_bit = 0;
            p->next = new ListNode(tmp);
            p = p->next;
            l1 = l1 -> next;
        }
        while (l2) {
            tmp = l2->val + carry_bit;
            if (tmp > 9) {
                tmp -= 10;
                carry_bit = 1;
            } else carry_bit = 0;
            p->next = new ListNode(tmp);
            p = p->next;
            l2 = l2 -> next;
        }
        if (carry_bit) {
            p->next = new ListNode(carry_bit);
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    ListNode *a = int2list(243);
    ListNode *b = int2list(564);
    ListNode *res = sol.addTwoNumbers(a, b);
    a->show();
    cout << "+";
    b->show();
    cout << "=";
    res->show();
    cout << endl;
    return 0;
}