"""
Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.


Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3


Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.
"""


class Node:
  def __init__(self):
    self.val = None
    self.next = None

  def __str__(self):
    return f"val {self.val} next is {self.next}"
class MyLinkedList:

    def __init__(self):
      self.head = None
      self.length = 0

    def __str__(self):
      return f"len is {self.length} head {self.head}"

    def get(self, index: int) -> int:
      count = 0
      cur = self.head
      while cur is not None:
        if count == index:
          return cur.val
        cur = cur.next
        count+=1
      return -1

    def addAtHead(self, val: int) -> None:
      newHead = Node()
      newHead.val = val
      if self.head is None:
        self.head = newHead
        return
      newHead.next = self.head
      self.head = newHead
      self.length +=1


    def addAtTail(self, val: int) -> None:
      tail = Node()
      tail.val = val
      if self.head is None:
        self.head = tail
        return
      if self.head.next is None:
        self.head.next = tail
        return
      cur = self.head
      while cur.next is not None:
        cur = cur.next
      cur.next = tail
      self.length+=1


    def addAtIndex(self, index: int, val: int) -> None:
      if index == 0:
        self.addAtHead(val)
        return

      count = 0
      cur = self.head
      prev = None
      next = None
      inserted = Node()
      inserted.val = val
      while cur is not None:
        if count == (index-1):
          prev = cur
          next = cur.next
          prev.next = inserted
          inserted.next = next
          self.length+=1
          return
        cur = cur.next
        count+=1

    def deleteAtIndex(self, index: int) -> None:
      cur = self.head
      if index == 0:
        if cur.next is None:
          self.head = None
          self.length = 0
          return
        self.head = cur.next
        self.length -= 1
        return

      count = 0
      prev = None
      next = None

      while True and cur is not None:
        if count == (index - 1):
          prev = cur
          next = cur.next
          if next is not None:
            next = next.next
          prev.next = next
          self.length-=1
          break
        cur = cur.next
        count+=1




# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)

obj = MyLinkedList()
obj.addAtHead(2)
obj.addAtHead(3)
print(f"obj is {obj}")


obj = MyLinkedList()
obj.addAtTail(1)
print(f"obj is now {obj}")
print(f"get is {obj.get(0)}")

# peeking others' solutions

# seperate Node with MyLinkedList!!!
# MyLinkedList only needs head and length