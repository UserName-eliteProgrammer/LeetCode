class Solution 
{
public:
    vector<vector<int>> ans;
    void help(int node, vector<vector<int>> &graph, vector<int> &nodes,  int target)
    {
        if(node == target)
        {
            nodes.push_back(node);
            ans.push_back(nodes);
            nodes.pop_back();
            return;
        }

        nodes.push_back(node);
        for(auto adj : graph[node])
        {
            help(adj, graph, nodes, target);
        }
        nodes.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        int targetNode = graph.size() - 1;
        vector<int> nodes;
        help(0, graph, nodes, targetNode);
        return ans;    
    }
};