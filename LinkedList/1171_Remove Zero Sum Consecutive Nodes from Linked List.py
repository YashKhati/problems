# Leetcode 1171

# Approach -> O(n^2)
def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        front = ListNode(0, head)
        start = front

        while start is not None:
            prefix_sum = 0
            end = start.next

            while end is not None:
                # Add end's value to the prefix sum
                prefix_sum += end.val
                # Delete zero sum consecutive sequence 
                # by setting node before sequence to node after
                if prefix_sum == 0:
                    start.next = end.next
                end = end.next

            start = start.next

        return front.next

# Approach ->O(n)

 def removeZeroSumSublists(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        dummy = ListNode(0,head)
        curr = dummy
        pref_sum = 0

        # hashtable to maintain node and prefix sum
        pref_sum_node = {0 : dummy}

        while curr:
            # if there is duplicate prefix_sum it will be replaced with new curr node
            pref_sum += curr.val
            pref_sum_node[pref_sum] = curr
            curr = curr.next
        
        pref_sum = 0
        curr = dummy

        while curr is not None:
            pref_sum += curr.val
            # Skipping the nodes in middle because middle nodes will have sum equal to zero 
         
            curr.next = pref_sum_node[pref_sum].next
            curr = curr.next

        return dummy.next 

