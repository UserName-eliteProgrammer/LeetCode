class Solution 
{
public:
    
    vector<int> indexes;
    string chars;
    string str;
    
    void dfs(int i, vector<vector<int>>& adjList, vector<bool>& visited)
    {
        visited[i] = true;
        indexes.push_back(i);
        chars.push_back(str[i]);
        
        for(int j = 0; j < adjList[i].size(); j++)
        {
            if(visited[adjList[i][j]] == false)
            {   
                dfs(adjList[i][j], adjList, visited);
            }
        }
    }
    
    string help(vector<vector<int>>& adjList, string& s)
    {   
        int nodesCnt = s.size();
        string ans = s;
        vector<bool> visited(nodesCnt, false);
        for(int i = 0; i < nodesCnt; i++)
        {
            if(visited[i] == false)
            {
                dfs(i, adjList, visited);
                
                sort(indexes.begin(), indexes.end());
                sort(chars.begin(), chars.end());
                
                for(int j = 0; j < indexes.size(); j++)
                {   
                    ans[indexes[j]] = chars[j];
                }
                
                indexes.resize(0);
                chars.resize(0);
            }
        }
        return ans;
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) 
    {
        vector<vector<int>> adjList(s.size());
        str = s;
        for(int i = 0; i < pairs.size(); i++)
        {
            adjList[pairs[i][0]].push_back(pairs[i][1]);
            adjList[pairs[i][1]].push_back(pairs[i][0]);
        }
        return help(adjList, s);
    }
};