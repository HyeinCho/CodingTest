def del_nodes(node_idx):
    for i in tree[node_idx]:
        if visited[i]:
            continue
        visited[i] = 1
        del_nodes(i)


def find_leaf(node_idx):
    if node_idx == del_num:
        return
    flag = False
    for i in tree[node_idx]:
        if not visited[i]:
            flag = True
            find_leaf(i)
    if not flag:
        global answer
        answer += 1


N = int(input())
nodes = list(map(int, input().split()))
del_num = int(input())
parent_idx = -1
tree = [[] for _ in range(N + 1)]
for idx, node in enumerate(nodes):
    if node == -1:
        parent_idx = idx
    else:
        tree[node].append(idx)

visited = [0] * (N + 1)
visited[del_num] = 1
del_nodes(del_num)

answer = 0
find_leaf(parent_idx)
print(answer)
