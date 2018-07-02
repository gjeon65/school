#!/usr/bin/env python

import sys
 
class Graph():
 
    def __init__(self, vertices):
        self.V = vertices
        self.graph = [[0 for column in range(vertices)] 
                      for row in range(vertices)]
 
    def printSolution(self, dist):
        for node in range(self.V):
            print(node,' ',dist[node])
	#find minimum distance
    def minDistance(self, dist, sptSet):
 
        min = sys.maxsize
 
        for v in range(self.V):
            if dist[v] < min and sptSet[v] == False:
                global min_index
                min = dist[v]
                min_index = v
 
        return min_index
 
    # using adjacency matrix representation
    def dijkstra(self, src):
 
        dist = [sys.maxsize] * self.V
        dist[src] = 0
        sptSet = [False] * self.V
 
        for cout in range(self.V):
 				#get rest v store to u
            u = self.minDistance(dist, sptSet)
            sptSet[u] = True
            for v in range(self.V):
                if self.graph[u][v] > 0 and sptSet[v] == False and dist[v] > dist[u] + self.graph[u][v]:
                        dist[v] = dist[u] + self.graph[u][v]

        self.printSolution(dist)
 
g  = Graph(6)
g.graph = [[1, 4, 1, 5, 8, 10],
           [3, 3, 1, 5, 8, 10],
           [2, 3, 1, 5, 8, 10],
           [4, 3, 1, 5, 7, 10],
           [5, 3, 1, 5, 7, 8],
           [6, 3, 1, 5, 7, 8]
          ];
 
g.dijkstra(0);
