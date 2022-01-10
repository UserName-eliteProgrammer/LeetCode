class Solution 
{
public:
    int ans = 0;
    unordered_map<int, Employee*> mp;

    void dfs(int id)
    {
        ans += mp[id]->importance;

        for (int i = 0; i < (mp[id]->subordinates).size(); i++)
        { 
            dfs(mp[id]->subordinates[i]);
        }
    }

    int getImportance(vector<Employee*> employees, int id) 
    {
        for (int i = 0; i < employees.size(); i++)
        {
            int id = employees[i]->id;
            mp[id] = employees[i];
        }
        dfs(id);
        return ans;    
    }
};