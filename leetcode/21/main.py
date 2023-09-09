class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


def mergeTwoLists(list1: ListNode, list2: ListNode) -> ListNode:
    output = ListNode()
    c = output
    while list1 and list2:
        if list1.val <= list2.val:
            c.next = list1
            c = c.next
            list1 = list1.next
        else:
            c.next = list2
            c = c.next
            list2 = list2.next

    while list1:
        c.next = list1
        c = c.next
        list1 = list1.next

    while list2:
        c.next = list2
        c = c.next
        list2 = list2.next

    t = output.next
    return t


n1 = ListNode(1)
n2 = ListNode(2)
n3 = ListNode(4)
b1 = ListNode(1)
b2 = ListNode(3)
b3 = ListNode(4)

# First list
n1.next = n2
n2.next = n3

# Second li1t
b1.next = b2
b2.next = b3

current1 = n1
current2 = b1

output = ListNode()
c = output
while current1 and current2:

    if current1.val <= current2.val:
        c.next = current1
        c = c.next
        current1 = current1.next
    else:
        c.next = current2
        c = c.next
        current2 = current2.next


while current1:
    c.next = current1
    c = c.next
    current1 = current1.next

while current2:
    c.next = current2
    c = c.next
    current2 = current2.next

t = output.next
while t:
    print(f"Output: {t.val}")
    t = t.next
