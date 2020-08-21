# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head is None:
            return None
        
        res = None
        tail = None
        trav = head
        sxref=[]
        dxref=[]
        while trav is not None:
         newnode = Node(trav.val,None,trav.random)
         sxref.append(trav)
         dxref.append(newnode)
         if tail is None:
            tail = res = newnode
         else:
            tail.next = newnode
            tail = newnode
         trav = trav.next
        
        trav = head
        trav1 = res 
        while trav is not None:
            if trav.random is None:
                trav1.random = None
            else:
             i = sxref.index(trav.random)
             trav1.random = dxref[i]
                
            trav = trav.next
            trav1 = trav1.next
            
        return res

