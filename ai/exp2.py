# from collections import defaultdict

# class Graph:
#     # constructor
#     def __init__(self, vertices, root, target):
#         self.vertices = vertices
#         self.root = root
#         self.target = target
#         self.edges = defaultdict(list)

#     # add edges in graph
#     def addEdge(self, u, v):
#         self.edges[u].append(v)
#     # dfs traversal in graph with level
#     def dfs(self, node, lvl, currlvl):
#         print("{node} ")
#         if currlvl == lvl:
#             return
#         for i in self.edges[node]:
#             self.dfs(i,lvl,currlvl+1)
#     # dfid traversal using iterations
#     def dfid(self, iter):
#         for i in range(0, iter):
#             print("Iteration {i} for DFID is \n")
#             self.dfs(self.root, i, 0)


# vertices = int(input("Enter number of vertices "))
# root = int(input("Enter the root node"))
# target = int(input("Enter the destination node"))
# graph = Graph(vertices,root,target)
# for i in range(0,vertices):
#     a,b = input("Enter the edges")
#     graph.addEdge(int(a),int(b))

# iterations = int(input("Enter the number of iterations "))
# graph.dfid(iterations)

# define the graph as an adjacency matrix
graph = {
    'A': {'B': 9, 'C': 4},
    'B': {'C': 2, 'D': 7, 'E': 3},
    'C': {'D': 1, 'E': 6},
    'D': {'E': 4, 'F': 8},
    'E': {'F': 2},
    'F': {}
}
# define the goal node
goal = 'E'


def dfs(start, depth, path, visited):
    # add the current node to the path and the visited set
    path.append(start)
    visited.add(start)

    # check if the goal node has been reached
    if start == goal:
        return True, path

    # check if the maximum depth has been reached
    if depth == 0:
        return False, None

    # recursively search the neighbors of the current node
    for neighbor, cost in graph[start].items():
        if neighbor not in visited:
        # recursively call dfs with the neighbor node and the reduced depth
            found, new_path = dfs(neighbor, depth - 1, path, visited)
        if found:
            return True, new_path

    # remove the current node from the path and the visited set
    path.pop()
    visited.remove(start)

    return False, None


def dfid(start):
    # initialize the maximum depth to 0
    depth = 0

    # repeat until the goal node is found
    while True:
        # initialize the path and visited set
        path = []
        visited = set()

    # perform a depth-limited search
    found, new_path = dfs(start, depth, path, visited)
    if found:
        # return the path and the cost of the edges
        cost = sum(graph[new_path[i]][new_path[i+1]] for i in
               range(len(new_path)-1))
    return new_path, cost

    # increment the maximum depth and try again
    depth += 1

    # print the current state of the algorithm
    print('--- Iteration ---')
    print('Depth:', depth)
    print('Open List:', path)
    print('Closed List:', visited)
    print('-----------------')


# example usage
start_node = 'A'
path, cost = dfid(start_node)
print('Path:', path)
print('Cost:', cost)
