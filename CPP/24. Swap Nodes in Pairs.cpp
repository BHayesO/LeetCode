#include <iostream>
#include <vector>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* next = head->next;
        ListNode* rest_left = next->next;
        next->next = head;
        ListNode* rest_head = swapPairs(rest_left);
        head->next = rest_head;

        return next;
    }
};

int main() {
	Solution sol;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4))));
	ListNode* result = sol.swapPairs(head);
	printListNode(result);
	return 0;
}