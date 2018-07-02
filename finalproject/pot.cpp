#include <iostream>
#include <limits.h>
#include "arraylist.h"
#include <vector>
#define NODES 6
#define INF 20000

using namespace std;

int min(int x,int y)
{
  if( x < y)
  {
    return x;
  }
  return y;
}

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

int minDistance(elements s)
{

  int size = s.size();
  int minNum = INF;
  int minIndex = -1;
  for(int i=0; i< size; i++)
  {
    if(D[s.idxPosition(i)] < minNum)
    { 
      minNum = D[s.idxPosition(i)];
      minIndex = s.idxPosition(i);
    }
  }
  return minIndex;
}
/*
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
     solution(dist, V);
}
*/
void solution()
{
  int N = S.size();
  cout << "s = (";
  for(int i=0; i< N-1; i++)
  {
    cout << S.idxPosition(i)+1 <<",";
  }
  cout << S.idxPosition(N-1)+1 << ") ;  ";

  
  cout <<"w = ("<< w+1 << ")  ;  ";
  cout << "D[2]= "<< D[1]  <<" "<< "P[2]= " << P[1]+1;
  cout << "D[3]= "<< D[2]  <<" "<< "P[3]= " << P[2]+1;
  cout << "D[4]= "<< D[3]  <<" "<< "P[4]= " << P[3]+1;
  cout << "D[5]= "<< D[4]  <<" "<< "P[5]= " << P[4]+1;
  cout << "D[6]= "<< D[5]  <<" "<< "P[6]= " << P[5]+1;
  cout << endl;
}
class table{
public:
  table();
  int C[NODES][NODES];  
};

table::table()
{
  for(int i = 0; i<NODES;i++)
  {
    for(int j = 0; j<NODES;j++)
    {
      C[i][j]=INF;
    }
  }
}

int main()
{//nodes are -1 and added edges
  table tab;
  tab.C[0][1]=4;
  tab.C[0][2]=1; 
  tab.C[0][3]=5;
  tab.C[0][4]=8;
  tab.C[0][5]=10;
  tab.C[2][1]=2; 
  tab.C[3][4]=2; 
  tab.C[4][5]=1;
  
  int i;
  D[0] = INF; 
  P[0] = -1; 
  for(i=1; i< NODES; i++)
  {
    D[i] = tab.C[0][i];
    P[i] = 0;
  }

  solution();
  
  for(i=0; i < NODES-1; i++) 
  {
    
    elements m = set_not(S);
    w = minDistance(m);
    S.add(w);
    m = set_not(S);
    int size = m.size();
    int v;
    for(int j=0; j< size; j++)
    {
      v = m.idxPosition(j);
      if( (D[w]+tab.C[w][v])<D[v])
      {
		P[v] = w;
      }
      D[v] = min(D[v], D[w]+tab.C[w][v]);      
    }
    solution();
  }
  return 0;
}

