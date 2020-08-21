# Definition for a Node.
# Here we can interleave items and copy
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

def show(head):
  while head is not None:
      print(head.val)
      head = head.next

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return None
        #Do an interleaved duplicate list ie if 1->2->3->4 
        #Create another list with 1->1->2->2->3->3->4->4 with the
        #second virtual list random pointer to a sentinel.
        
        trav = head
        sentinel = Node(-1,None,None)
        while trav is not None:
         newrandom = None if trav.random is None else sentinel 
         newnode = Node(trav.val,trav.next,newrandom)
         trav.next = newnode
         trav = newnode.next

        prev = head 
        trav = head.next

        #Fix the sentinels by doing a scan and replacing the
        #sentinels with the next item of the actual random pointers
        #In the example above if first 2 pointed to 4 , 4 next will be the
        #random node for the new list

        while prev is not None: 
         if trav.random is sentinel:
            trav.random = prev.random.next
        
         prev = trav.next   
         trav = prev.next if prev is not None else None

        
        ans = head.next
        tail = head.next

        head.next = tail.next
        tail.next = None
        
        trav = head.next

        while trav is not None:
           tail.next = trav.next
           trav.next = trav.next.next
           tail = tail.next
           trav = tail.next
           tail.next = None              
            
        return ans


n1=Node(1,None,None)
n0=Node(2,n1,None)
show(n0)
s=Solution()
show(s.copyRandomList(n0))

