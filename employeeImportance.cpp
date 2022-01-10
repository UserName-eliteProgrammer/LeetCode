class Solution 
{
public:
    map<int, vector<int>>id_Sub_mp;
    map<int, int> id_imp_mp;
    bool visited[2005];
    int ans = 0;

    void dfs(int id)
    {
        int imp = id_imp_mp[id];
        int subSize = id_Sub_mp[id].size();

        visited[id] = true;
        ans += imp;
        
        for (int i = 0; i < subSize; i++)
        {   
            if(visited[id_Sub_mp[id][i]] == false)
            {   
                dfs(id_Sub_mp[id][i]);
            }
        }
        return;
    }

    int getImportance(vector<Employee*> employees, int id) 
    {   
        int size = employees.size();

        for (int i = 0; i < size; i++)
        {   
            int id = employees[i]->id;
            id_Sub_mp[id] = employees[i]->subordinates;
            id_imp_mp[id] = employees[i]->importance;
        }
        
        dfs(id);
        return ans;
    }
};