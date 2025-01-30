class Node:
    def __init__(self, key, value):
        self.k = key
        self.val = value
        self.prev = None
        self.next = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {} 
        self.left = Node(0, 0)  
        self.right = Node(0, 0)  
        self.left.next = self.right
        self.right.prev = self.left

    def get(self, key: int) -> int:
        if key in self.cache:
            node = self.cache[key]
            self.remove(node)
            self.insert(node)
            return node.val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
            del self.cache[key]
        node = Node(key, value)
        self.cache[key] = node
        self.insert(node)
        if len(self.cache) > self.cap:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.k]
            del lru

    def remove(self, node: Node) -> None:
        prev = node.prev
        next_node = node.next
        prev.next = next_node
        next_node.prev = prev

    def insert(self, node: Node) -> None:
        prev = self.right.prev
        next_node = self.right
        prev.next = node
        node.prev = prev
        node.next = next_node
        next_node.prev = node
