#include <iostream>
#include <string>
#include <vector>
#define NODES 6
#define INF 10000

using namespace std;


int min(int s,int d)
{
  if( s < d)
  {
    return s;
  }
  return d;
}

class elements
{
public:
  elements(int first);
  elements();
  int indexof(int location);
  void add(int i);
  int elementAt(int index);
  int size();
  
private:
  vector<int> av;
};
elements::elements()
{

}
elements::elements(int first)
{
  av.push_back(first);
}
int elements::indexof(int location)
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
  if(indexof(i)==-1)
  {
    av.push_back(i);
  }
}
int elements::elementAt(int index)
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
    if(s.indexof(i)==-1)
    {
      returnVal.add(i);
    }
  }
  return returnVal;
}

int minDNode(elements s)
{
  int size = s.size();
  int minNum = INF;
  int minIndex = -1;
  for(int i=0; i< size; i++)
  {
    if(D[s.elementAt(i)] < minNum)
    { 
      minNum = D[s.elementAt(i)];
      minIndex = s.elementAt(i);
    }
  }
  return minIndex;
}
void printUpdateOneIndexed()
{
  int size = S.size();
  cout << "";
  for(int i=0; i< size-1; i++)
  {
    cout << S.elementAt(i)+1 <<",";
  }
  cout << S.elementAt(size-1)+1 << "=";
  if(size >3)
  {
    cout << "\t";
  }
  else
  {
    cout << "\t\t";
  }
  
  cout <<"["<< w+1 << "] = ";
  cout << D[1] << ", " << P[1]+1 << ", ";
  cout << D[2] << ", " << P[2]+1 << ", ";
  cout << D[3] << ", " << P[3]+1 << ", ";
  cout << D[4] << ", " << P[4]+1 << ", ";
  cout << D[5] << ", " << P[5]+1 << ", ";
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
{
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
  
  printUpdateOneIndexed();
  
  for(i=0; i < NODES-1; i++)
  {
    elements vminuss = set_not(S);
    w = minDNode(vminuss);
    S.add(w);
    vminuss = set_not(S);
    int size = vminuss.size();
    int v;
    for(int j=0; j< size; j++)
    {
      v = vminuss.elementAt(j);
      if( (D[w]+tab.C[w][v])<D[v])
      {
			P[v] = w;
      }
      D[v] = min(D[v], D[w]+tab.C[w][v]);      
    }
    printUpdateOneIndexed();
  }
  return 0;
}

