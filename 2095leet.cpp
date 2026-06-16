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
    ListNode() {
        val = 0;
        next = nullptr;
    }
    ListNode(int x) {
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode* next) {
        val = x;
        next = next;
    }
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr) {
        ListNode* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    return prev;
}


ListNode* create(vector <int>& a) {
    if (a.size() == 0) {
        return NULL;
    }
    ListNode* head = new ListNode(a[0]);
    ListNode* trav = head;
    for (int i = 1; i < a.size(); i++) {
        ListNode* node = new ListNode(a[i]);
        trav -> next = node;
        trav = node;
    }
    return head;
 }

void print(ListNode* head) {
    ListNode* curr = head;
    while (curr != nullptr) {
        cout << curr -> val << (curr -> next != nullptr ? ' ' : '\n');
        curr = curr -> next;
    }
}

int length(ListNode* head) {
    ListNode* curr = head;
    int len = 0;
    while (head != nullptr) {
        head = head -> next;
        len++;
    }
    return len;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = length(head);
    if (n > len || n <= 0) {
        return head;
    }
    int target = len - n; 
    if (target == 0) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    ListNode* prev = head;
    for (int i = 1; i < target; i++) {
        prev = prev->next;
    }
    ListNode* temp = prev->next;
    prev->next = temp->next;
    delete temp;
    return head;
}

int pairSum(ListNode* head) { // sum with twin 2330leet
    int len = length(head);
    int half = len / 2;
    ListNode* h = head;
    ListNode* temp = head;
    for (int i = 0; i < half; i++) {
        temp = temp->next;
    }
    if (len % 2 == 1) {
        temp = temp->next;
    }
    temp = reverseList(temp);
    int ans = INT_MIN;
    while (temp != nullptr) {
        ans = max(ans, temp->val + h->val);
        temp = temp->next;
        h = h->next;
    }
    return ans;
}

ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head -> next == nullptr) {
        return nullptr;
    }
    ListNode *prev, *slow, *fast;
    prev = nullptr;
    slow = head;
    fast = head;
    while (fast && fast -> next != nullptr) {
        prev = slow;
        slow = slow -> next;
        fast = (fast -> next) -> next;
    }
    prev -> next = slow -> next;
    return head;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ListNode* L = create(a);
        L = deleteMiddle(L);
        print(L);
    }
    return 0;
}