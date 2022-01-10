// khud ki smjh se changes kiye hai....code nhi dekha....kafi mehnat lagi code flow ko smjhte hue code likhne mei

class Solution 
{
public:
    bool dfs(int node, vector<int> *g,  vector<bool> &visitedPath, vector<bool> &visited)
    {
        visitedPath[node] = true;
        visited[node] = true;

        for(auto element : g[node])
        {   
            if(visited[element] == false)
            {   
                if(visitedPath[element] == false)
                {   
                    if(dfs(element, g, visitedPath, visited))
                    {   
                        return true;      
                    }
                }
            }
            else if(visitedPath[element] == true)
            {
                return true;
            }
        }

        visitedPath[node] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> g[numCourses];
        vector<bool> visited(numCourses, false);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            g[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }  

        for (int i = 0; i < numCourses; i++)
        {   
            vector<bool> visitedPath(numCourses, false);
            if(visited[i] == false)
            {
                if(dfs(i, g, visitedPath, visited))
                {
                    return false;
                }  
            }      
        } 
        return true;   
    }
};