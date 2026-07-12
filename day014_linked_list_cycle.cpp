#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true; 
            }
        }

        return false;  // fast reached the end, no cycle
    }
};

int main() {
    Solution sol;

    ListNode* head1 = new ListNode(3);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(0);
    head1->next->next->next = new ListNode(-4);
    head1->next->next->next->next = head1->next; 

    cout << "Test 1 (expected: 1): " << sol.hasCycle(head1) << endl;

    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);

    cout << "Test 2 (expected: 0): " << sol.hasCycle(head2) << endl;
    ListNode* head3 = new ListNode(1);
    cout << "Test 3 (expected: 0): " << sol.hasCycle(head3) << endl;

    ListNode* head4 = nullptr;
    cout << "Test 4 (expected: 0): " << sol.hasCycle(head4) << endl;

    return 0;
}
