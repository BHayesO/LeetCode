from ListNode import *

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l1_current = l1
        l2_current = l2
        dummyNode = ListNode(0)
        sortedList_current = dummyNode
        
        while l1_current and l2_current:
            if l1_current.val <= l2_current.val:
                sortedList_current.next = l1_current
                l1_current = l1_current.next
            else:
                sortedList_current.next = l2_current
                l2_current = l2_current.next
            sortedList_current = sortedList_current.next
            
        if l1_current:
            sortedList_current.next = l1_current
        if l2_current:
            sortedList_current.next = l2_current
            
        return dummyNode.next

if __name__ == "__main__":
    l1 = ListNode(1,ListNode(2,ListNode(4)))
    l2 = ListNode(1,ListNode(3,ListNode(4)))
    result = Solution().mergeTwoLists(l1,l2)
    print(result)