

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

/*class know
{
public:
 bool possible; // if one one was excluded from the search possible = false
 int status;    // 0(not know),1(know),2(itself)

 know(bool poss, int sta)
 {
  possible = poss;
  status = sta;
 }
 ~know() {}
};*/

void exclude_cand(int a, int b);

int main()
{

 return 0;
}

bool check_celebrity(int x, std::vector<std::vector<int>> &adj)
{

 // check if x knows someone
 for (int i = 0; i < adj.size(); i++)
 {
  if (adj[x][i] == 1)
  {
   return false;
  }
  if (adj[i][x] == 0)
  {
   return false;
  }
 }
 return true;
}

int celebrity(std::vector<std::vector<int>> &adj)
{
 int cand = 0;
 for (int i = 1; i < adj.size(); i++)
 {
  // if the candidate knows someone i pick this individual as a candidate
  // note if cand does not know anyone the cand will remain 0
  if (adj[cand][i] == 1)
  {
   cand = i;
  }

  if (check_celebrity(cand, adj))
  {
   return cand;
  }
  return -1;
 }
}
