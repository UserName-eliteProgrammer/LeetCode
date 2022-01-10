
class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int, int> countMap;
        multimap<int, int, greater<int>> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++)
        {
            countMap[nums[i]]++;               
        }

        for(auto pair : countMap)
        {
            mp.insert(make_pair(pair.second, pair.first));
        } 

        for(auto pair : mp)
        {   
            if(k == 0)
            {
                break;
            }
            ans.push_back(pair.second);
            k--;
        }
        return ans;          
    }
};