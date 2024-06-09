from ListNode import *
from typing import List, Optional

class Solution:
    def mergeKlLists(self, lists: List[Optional[ListNode]]) ->  Optional[ListNode]:
        dummyNode = ListNode(0)
        for i in range(len(lists)):
            dummyNode.next = self.mergeTwoLists(dummyNode.next, lists[i])
            
        return dummyNode.next
    
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
    lists = [ListNode(1,ListNode(4,ListNode(5))),
             ListNode(1,ListNode(3,ListNode(4))),
             ListNode(2,ListNode(6))]
    result = Solution().mergeKlLists(lists)
    print(result)