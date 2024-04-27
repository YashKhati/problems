from collections import deque

n = 6
edges = [[3, 0], [3, 1], [3, 2], [3, 4], [5, 4]]


def findMinHeightTrees(n, edges):
    indegree = [0] * n
    adjList = [ [] for _ in range(n)]
    for x in edges:
        indegree[x[0]] += 1
        indegree[x[1]] += 1

        adjList[x[0]].append(x[1])
        adjList[x[1]].append(x[0])

    queue = deque([i for i in range(n) if indegree[i] == 1])

    nodeCount = n
    while nodeCount > 2:
        leave_count = len(queue)
        nodeCount -= leave_count

        for _ in range(leave_count):
            leaf = queue.popleft()
            for neighbour in adjList[leaf]:
                indegree[neighbour] -= 1
                if indegree[neighbour] == 1:
                    queue.append(neighbour)


    return  list(queue)

print(findMinHeightTrees(n,edges))
