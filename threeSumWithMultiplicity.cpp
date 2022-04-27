class Solution 
{
public:
    int threeSumMulti(vector<int>& arr, int target) 
    {   
        int ans = 0;
        map<int, set<int>> mp;
        for(int i = 0; i < arr.size(); i++)
        {
            mp[arr[i]].insert(i);
        }
        
        for(int i = 0; i < arr.size() - 2; i++)
        {   
            mp[arr[i]].erase(i);
            for(int j = i + 1; j < arr.size() - 1; j++)
            {   
                mp[arr[j]].erase(j);
                if(mp[target - (arr[i] + arr[j])].size())
                {
                    ans += mp[target - (arr[i] + arr[j])].size();
                }
            }
            
            for(int j = i + 1; j < arr.size() - 1; j++)  mp[arr[j]].insert(j);
        }
        return ans;
    }
};