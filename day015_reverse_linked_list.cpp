#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            ListNode* nextNode = current->next;  
            current->next = prev;                
            prev = current;                      
            current = nextNode;                 
        }

        return prev;  
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution sol;

    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head1);

    ListNode* reversed1 = sol.reverseList(head1);
    cout << "Reversed list: ";
    printList(reversed1); 

    
    ListNode* head2 = new ListNode(1);
    ListNode* reversed2 = sol.reverseList(head2);
    cout << "Single node reversed: ";
