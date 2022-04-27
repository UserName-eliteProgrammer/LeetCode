class Solution 
{
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        unordered_set<int> s;
        for(auto vec : edges)
        {
            s.insert(vec[0]);
            s.insert(vec[1]);
        }
        
        vector<vector<int>> adjList(s.size() + 1);
        for(auto vec : edges)
        {
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        }
        
        for(int i = 1; i <= s.size(); i++)
        {
            if(adjList[i].size() == s.size() - 1)
            {
                return i;
            }
        }
        return 0;
    }
};