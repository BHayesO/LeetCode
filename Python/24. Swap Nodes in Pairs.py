from typing import Optional
from ListNode import *

class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        dummy = ListNode()
        curr = head
        prev = dummy
        
        while curr and curr.next:
            prev.next = curr.next
            curr.next = prev.next.next
            prev.next.next = curr
            
            prev = curr
            curr =  curr.next
            
        return dummy.next

if __name__ == '__main__':
    head = ListNode(1,ListNode(2,ListNode(3,ListNode(4))))
    result = Solution().swapPairs(head)
    print(result)