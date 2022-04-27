#define ll long long int
class Solution 
{
public:
    int nthUglyNumber(int n) 
    {
        set<ll> q;
        unordered_set<ll> ref;
        vector<ll> dp;
        q.insert(1);
        while(dp.size() < n)
        {
            ll num = *(q.begin());
            dp.push_back(num);
            ref.insert(num);
            
            q.erase(num);
            
            if(ref.count(num * 2) == 0)
            {
                q.insert(num * 2);    
            }
            if(ref.count(num * 3) == 0)
            {
                q.insert(num * 3);
            }
            if(ref.count(num * 5) == 0)
            {
                q.insert(num * 5);
            }
        }
        return dp[dp.size() - 1];
    }
};