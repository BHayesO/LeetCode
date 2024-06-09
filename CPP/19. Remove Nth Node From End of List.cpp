#include <iostream>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* newList = new ListNode(0);
		newList->next = head;
		ListNode* first = head;
		int nodes = 0;

		while (first) { // while (first != nullptr) { is the same
			nodes++;
			first = first->next;
		}

		nodes -= n;
		first = newList;

		while (nodes > 1) {
			nodes--;
			first = first->next;
		}

		first->next = first->next->next;

		return newList->next;
	}
};


int main() {
	Solution sol;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	int n = 2;
	ListNode* result = sol.removeNthFromEnd(head,n);
	printListNode(result);
	return 0;
}