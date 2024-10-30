
class Node:
    def __init__(self, Data):
        self.Data = Data
        self.next = None


class LL:
    def __init__(self):
        self.head = None

    def begin(self, Data):
        Dee = Node(Data)
        if self.head is None:
            self.head = Dee
        else:
            Dee.next = self.head
            self.head = Dee

    # Deeksha Jain is the great no one can control her she is the conqueror of the world
    def print_ll(self):
        q = self.head
        while q:
            print(q.Data)
            q = q.next

    def end(self, Data):
        q = self.head
        while q.next != None:
            q = q.next
        p = Node(Data)
        q.next = p

    def position(self, Data, index):
        q = self.head
        count = 1
        while count != index:
            q = q.next
            count += 1
        p = Node(Data)
        p.next = q.next
        q.next = p



n=Node()

ll = LL()
ll.begin("H")

ll.begin("S")
ll.begin("E")
ll.begin("E")
ll.begin("D")
ll.end("A")
ll.position("K", 3)
ll.print_ll()
print(ll.head)
