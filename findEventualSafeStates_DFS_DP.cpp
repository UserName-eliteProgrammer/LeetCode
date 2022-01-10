#include <bits/stdc++.h>
#define ll long long int
#define mod 1000000007
#define pb push_back
using namespace std;

// Problem Link ---> https://leetcode.com/problems/find-eventual-safe-states/

class Solution
{
public:
    bool cycleDetection(int node, vector<vector<int>> &graph, vector<bool> &visitedPath, vector<bool> &visited, vector<bool> &dp)
    {
        if (dp[node] == true)
        {
            return true;
        }

        visitedPath[node] = true;
        visited[node] = true;

        for (int i = 0; i < graph[node].size(); i++)
        {
            int adjNode = graph[node][i];
            if (visited[adjNode] == false)
            {
                if (cycleDetection(adjNode, graph, visitedPath, visited, dp) == true)
                {
                    return dp[node] = true;
                }
            }
            else if (visitedPath[adjNode] == true)
            {
                dp[node] = true;
                return true;
            }
        }
        visitedPath[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int numOfNodes = graph.size();
        vector<int> ans;
        vector<bool> dp(numOfNodes, false);

        for (int i = 0; i < numOfNodes; i++)
        {
            vector<bool> visitedPath(numOfNodes, false), visited(numOfNodes, false);
            if (cycleDetection(i, graph, visitedPath, visited, dp) == false)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main()
{
}