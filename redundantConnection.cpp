class Solution 
{
public:
    vector<int> cycleNodes;
    bool detection = false;
    int endPoint = -1;

    void cycleDetection(int parent, int node, vector<int> *adj, vector<bool> &visited)
    {   
        if(detection)
        {
            return;
        }

        visited[node] = true;
        cycleNodes.push_back(node);
        for (int i = 0; i < adj[node].size(); i++)
        {   
            int adjNode = adj[node][i];
            if(visited[adjNode] == false)
            {
                cycleDetection(node, adjNode, adj, visited);
            }
            else if(visited[adjNode] == true and adjNode != parent)
            {
                detection = true;
                endPoint = adjNode;
                break;
            }
        }
        
        if(detection == true)
        {   
            visited[node] = false;
            return;
        }
        cycleNodes.pop_back();
        visited[node] = false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges)    
    {
        vector<int> *adj = new vector<int>[edges.size() + 1];
        map<int, pair<int, int>> order;
        set<pair<int, int>> pairs;

        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
            order[i] = {edges[i][0], edges[i][1]};
        }

        for (int i = 1; i <= edges.size(); i++)
        {   
            detection = false;
            endPoint = -1;
            cycleNodes.resize(0);
            vector<bool> visited(edges.size() + 1, false);
            cycleDetection(-1, i, adj, visited);

            if(detection == true and endPoint == i)
            {   
                break;
            }
        }
        
        vector<int> ans(2);
        
        for (int i = 0; i < cycleNodes.size() - 1; i++)
        {
            pairs.insert({cycleNodes[i], cycleNodes[i + 1]});
            pairs.insert({cycleNodes[i + 1], cycleNodes[i]});
        }
        pairs.insert({cycleNodes[0], cycleNodes[cycleNodes.size() - 1]});
        pairs.insert({cycleNodes[cycleNodes.size() - 1], cycleNodes[0]});

        for(auto pair : order)
        {
            if(pairs.find(pair.second) != pairs.end())
            {
                ans[0] = pair.second.first;
                ans[1] = pair.second.second;
            }
        }
        return ans;
    }
};