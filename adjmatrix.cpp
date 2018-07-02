#include <iostream>
#include <stdio.h>
#include <limits.h>
#include "arraylist.h"
#include <vector>
#define NODES 6
#define INF 20000  
#define V 6

using namespace std;

class elements
{
public:
  elements(int first);
  elements();
  int idx(int location);
  void add(int i);
  int idxPosition(int index);
  int size();
  
private:
  vector<int> av;
};
elements::elements(){}
elements::elements(int first)
{
  av.push_back(first);
}
int elements::idx(int location)
{
  int size = av.size();
  for(int i=0; i< size;i++)
  {
    if(av[i]==location)
    {
      return i;
    }
  }
  return -1;
}
void elements::add(int i)
{
  if(idx(i)==-1)
  {
    av.push_back(i);
  }
}
int elements::idxPosition(int index)
{
  return av[index];
}
int elements::size()
{
  return av.size();
}
elements S(0); 
int D[NODES];
int P[NODES];
int w;

elements set_not(elements s)
{
  
  elements returnVal;
  for(int i=0; i< NODES; i++)
  {
    if(s.idx(i)==-1)
    {

      returnVal.add(i);
    }
  }
  return returnVal;
}

int minDistance(int dist[], bool sptSet[])
{

   int min = INT_MAX, min_index;
  
   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;
  
   return min_index;
}
  

int printSolution(int dist[], int n)
{
   for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src)
{
     int dist[V]; 

  
     bool sptSet[V]; 

     for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     dist[src] = 0;

     for (int count = 0; count < V-1; count++)
     {

       int u = minDistance(dist, sptSet);

       sptSet[u] = true;

       for (int v = 0; v < V; v++)

         if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX 
                                       && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
     }

     printSolution(dist, V);
}

int main()
{
//adj matrix insert
   int graph[V][V] = {{1, 4, 1, 5, 8, 10},
                      {3, 3, 1, 5, 8, 10},
                      {2, 3, 1, 5, 8, 10},
                      {4, 3, 1, 5, 7, 10},
                      {5, 3, 1, 5, 7, 8},
                      {6, 3, 1, 5, 7, 8},
                     };
  
    dijkstra(graph, 0);
  
    return 0;
}
