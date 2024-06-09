from ListNode import *

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        newList = ListNode()
        newList.next = head
        nodes = 0
        first = head
        
        while first:
            nodes+=1
            first = first.next
            
        nodes-=n
        first = newList
        
        while nodes>0:
            nodes-=1
            first = first.next
            
        first.next = first.next.next
        return newList.next
    
if __name__ == "__main__":
    head = ListNode(1,ListNode(2,ListNode(3,ListNode(4,ListNode(5)))))
    n = 2
    result = Solution().removeNthFromEnd(head,n)
    print(result)