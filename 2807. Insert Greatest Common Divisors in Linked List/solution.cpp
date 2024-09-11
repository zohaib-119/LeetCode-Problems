#include <iostream>
#include <algorithm> // for __gcd

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* p = head;
        while (p->next) {
            int gcdValue = __gcd(p->val, p->next->val);
            
            ListNode* gcdNode = new ListNode(gcdValue, p->next);
            
            p->next = gcdNode;
            
            p = gcdNode->next;
        }
        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

// Helper function to create a new node
ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    // Create the linked list: 18 -> 24 -> 30
    ListNode* head = createNode(18);
    head->next = createNode(24);
    head->next->next = createNode(30);

    cout << "Original list: ";
    printList(head);

    Solution solution;
    head = solution.insertGreatestCommonDivisors(head);

    cout << "List after inserting GCDs: ";
    printList(head);

    return 0;
}
