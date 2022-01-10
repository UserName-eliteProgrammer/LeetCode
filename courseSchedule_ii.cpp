class Solution
{
public:
    vector<int> ans;
    bool notPossible = false;

    void dfs(int node, vector<int> *g, vector<bool> &visitedPath, vector<bool> &visited)
    {
        visited[node] = true;
        visitedPath[node] = true;

        for(auto element : g[node])
        {   
            if(visited[element] == false)
            {
                if(visitedPath[element] == false)
                {
                    dfs(element, g, visitedPath, visited);    
                }
            }
            else if(visitedPath[element] == true)
            {
                notPossible = true;
                break;
            }
        }

        visitedPath[node] = false;
        ans.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) 
    {   
        int size = prerequisites.size();
        vector<int> *g = new vector<int>[numCourses];
        vector<bool> visitedPath(numCourses, false);
        vector<bool> visited(numCourses, false);

        for (int i = 0; i < size; i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; i++)
        {
            if(visited[i] == false)
            {
                dfs(i, g, visitedPath, visited);
            }
        }

        if(notPossible)
        {
            ans.resize(0);
        }
        return ans;
    }
};