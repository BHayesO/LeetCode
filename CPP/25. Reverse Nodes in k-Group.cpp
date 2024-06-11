#include <iostream>
#include "printFunctions.hpp"

using namespace std;

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* curr = head;
		for (int i = 0; i < k;i++) {
			if (curr==NULL) {
				return head;
			}
			curr = curr->next;
		}

		ListNode* prev = nullptr;
		curr = head;

		for (int i = 0; i < k; i++) {
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}

		head->next = reverseKGroup(curr, k);
		return prev;
	}
};

int main() {
	Solution sol;
	int k = 3;
	ListNode* head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
	ListNode* result = sol.reverseKGroup(head, k);
	printListNode(result);
	return 0;
}