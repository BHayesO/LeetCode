from re import T
from typing import Optional
from ListNode import *

class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        curr = head
        for _ in range(k):
            if not curr:
                return head
            curr = curr.next

        prev = None
        curr = head
        for _ in range(k):
            nxt = curr.next
            curr.next = prev
            prev = curr
            curr = nxt
            
        head.next = self.reverseKGroup(curr, k)
        return prev

if __name__ == '__main__':
    k = 3
    head = ListNode(1,ListNode(2,ListNode(3,ListNode(4,ListNode(5)))))
    result = Solution().reverseKGroup(head,k)
    print(result)