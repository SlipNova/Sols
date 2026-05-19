#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

using ll = long long;
using ld = long double;

const int MOD = 1e9+7;
const ld PI = acos((ld)-1);

template<class T> bool ckmin(T &a, const T &b) {return b < a ? a = b, 1 : 0;}
template<class T> bool ckmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}

struct PairHash {
    size_t operator()(const pair<int,int>& p) const {
        return hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};

};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) {
            return head;
        }
        ListNode* curr = head;
        int len = 1;
        while (curr->next != nullptr) {
            curr = curr->next;
            len++;
        }
        k %= len;
        if (k == 0)
            return head;
        int steps = len - k - 1;
        ListNode* tail = head;
        while (steps--) {
            tail = tail->next;
        }
        ListNode* newHead = tail->next;
        tail->next = nullptr;
        curr->next = head;
        return newHead;
    }
};