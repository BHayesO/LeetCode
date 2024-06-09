#include <iostream>
#include <vector>
#include "printFunctions.hpp"
//#include "21. Merge Two Sorted Lists.cpp"

using namespace std;

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* dummyNode = new ListNode(0);
		ListNode* current = dummyNode;
		for (int i = 0;i < lists.size();i++) {
			current->next = mergeTwoLists(current->next, lists[i]);
		}
		return dummyNode->next;
	}

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
	vector<ListNode*> lists = { new ListNode(1,new ListNode(4,new ListNode(5))), new ListNode(1,new ListNode(3,new ListNode(4))), new ListNode(2, new ListNode(6)) };
	printVector(lists);
	ListNode* result = sol.mergeKLists(lists);
	printListNode(result);
	return 0;
}