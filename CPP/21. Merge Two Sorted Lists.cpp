#include <iostream>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* l1_current = l1;
		ListNode* l2_current = l2;
		ListNode* dummyNode = new ListNode(0);
		ListNode* sortedList_current = dummyNode;

		while (l1_current && l2_current) {
			if (l1_current->val <= l2_current->val) {
				sortedList_current->next = l1_current;
				l1_current = l1_current->next;
			}
			else {
				sortedList_current->next = l2_current;
				l2_current = l2_current->next;
			}
			sortedList_current = sortedList_current->next;
		}
		if (l1_current) {
			sortedList_current->next = l1_current;
		}
		if (l2_current) {
			sortedList_current->next = l2_current;
		}
		return dummyNode->next;
	}
};

int main() {
	Solution sol;
	ListNode* l1 = new ListNode(1, new ListNode(2, new ListNode(4)));
	ListNode* l2 = new ListNode(1, new ListNode(3, new ListNode(4)));
	ListNode* result = sol.mergeTwoLists(l1, l2);
	printListNode(result);
	return 0;
}