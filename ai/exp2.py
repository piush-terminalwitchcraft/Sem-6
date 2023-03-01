from collections import defaultdict

class Graph:
    # constructor
    def __init__(self, vertices, root, target):
        self.vertices = vertices
        self.root = root
        self.target = target
        self.edges = defaultdict(list)

    # add edges in graph
    def addEdge(self, u, v):
        self.edges[u].append(v)
    # dfs traversal in graph with level
    def dfs(self, node, lvl, currlvl):
        print("{node} ")
        if currlvl == lvl:
            return
        for i in self.edges[node]:
            self.dfs(i,lvl,currlvl+1)
    # dfid traversal using iterations
    def dfid(self, iter):
        for i in range(0, iter):
            print("Iteration {i} for DFID is \n")
            self.dfs(self.root, i, 0)



vertices = int(input("Enter number of vertices "))
root = int(input("Enter the root node"))
target = int(input("Enter the destination node"))
graph = Graph(vertices,root,target)
for i in range(0,vertices):
    a,b = input("Enter the edges")
    graph.addEdge(int(a),int(b))

iterations = int(input("Enter the number of iterations "))
graph.dfid(iterations)
