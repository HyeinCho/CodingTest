import sys
sys.setrecursionlimit(10**6) # 재귀한도 늘리기

result = [[], []]

class node:
    def __init__(self, info):
        self.number = info[0]
        self.x = info[1]
        self.y = info[2]
        self.left = None
        self.right = None

        
def addTree(node1, node2):
    if node1.x < node2.x:
        if node1.right == None:
            node1.right = node2
        else:
            addTree(node1.right, node2)
    else:
        if node1.left == None:
            node1.left = node2
        else:
            addTree(node1.left, node2)
        
        
def preorder(node1):
    if node1:
        result[0].append(node1.number)
        preorder(node1.left)
        preorder(node1.right)


def postorder(node1):
    if node1:
        postorder(node1.left)
        postorder(node1.right)
        result[1].append(node1.number)
        

def solution(nodeinfo):
    answer = [[]]
    tree = []
    for idx, val in enumerate(nodeinfo):
        tree.append(node([idx+1, val[0], val[1]]))
    tree.sort(key=lambda tmp: tmp.y, reverse=True)
    
    for i in range(1, len(tree)):
        addTree(tree[0], tree[i])
    
    preorder(tree[0])
    postorder(tree[0])
    answer = result
    return answer
