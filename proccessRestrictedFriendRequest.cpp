class DSU
{
private:
    int *parent, *size;

public:
    DSU(int n)
    {
        parent = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int num)
    {
        if (parent[num] == num)
        {
            return num;
        }
        return findParent(parent[num]);
    }

    void unionDSU(int u, int v)
    {
        int p1 = findParent(u), p2 = findParent(v);
        if (p1 == p2)
        {
            return;
        }

        if (size[p1] > size[p2])
        {
            parent[p2] = p1;
            size[p1] += size[p2];
        }
        else
        {
            parent[p1] = p2;
            size[p2] += size[p1];
        }
        return;
    }
};

class Solution 
{
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) 
    {
        vector<bool> ans;
        DSU dsu(n);

        for(auto &it1 : requests)
        {   
            int usr1Par = dsu.findParent(it1[0]);
            int usr2Par = dsu.findParent(it1[1]);
            bool flag = true;

            for(auto &it2 : restrictions)
            {
               int resUsr1 = dsu.findParent(it2[0]);
               int resUsr2 = dsu.findParent(it2[1]);

               if((usr1Par == resUsr1 and usr2Par == resUsr2) or (usr2Par == resUsr1 and usr1Par == resUsr2))
               {
                    flag = false;
                    break; 
               }
            }
            if(flag)
            {
                dsu.unionDSU(it1[0], it1[1]);
            }
            ans.push_back(flag);
        }
        return ans; 
    }
};