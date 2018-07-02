#!/usr/bin/env python

import copy

#performs depth-first search, starting at the vertex v of graph L, recording
visited in mark
def dfs(v):
	global mark, L, dfnumber, count
	print vertices[v],
	mark[v] = True
	dfnumber[v] = count
	count = count + 1
	for w in L[v]:
		if not mark[w]:
			dfs(w)

#begin test code

#graph is based on Fig. 6.38
vertices = ['a','b','c','d','e','f']
n = len(vertices)
global mark, L, dfnumber, count
mark = [False]*n
L = [[1,3,5],[2,5],[3],[1],[3,5],[3]] #a->0, b->1,...,f->5
dfnumber = copy.copy(vertices)
count = 0

print "Depth-first search of graph:"

for v in range(n):
	mark[v] = False
for v in range(n):
	if not mark[v]:
		dfs(v)
print
print "Depth-first numbering:"
for v in vertices:
	print v,
print
for dfn in dfnumber:
	print dfn,
