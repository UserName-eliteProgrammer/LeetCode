typedef TreeNode treenode;

map<treenode*, treenode*> parent;
treenode* mainNode;

void dfs(treenode* node, int val, treenode* p = NULL)
{
	if(node == NULL) return;
	if(node->val == val) mainNode = node;

	parent[node] = p;
	dfs(node->left, val, node);
	dfs(node->right, val, node);
}

int bfs()
{	
	int ans = -1;
	queue<pair<treenode*, int>> q;
	map<treenode*, bool> visited;
	visited[mainNode] = true;
	q.push({mainNode, 0});

	while(q.size())
	{	
		treenode *temp = q.front().first;
		int tempAns = q.front().second;
		q.pop();
		ans = max(ans, tempAns);
		if(temp->left != NULL and visited[temp->left] == false)
		{	
			visited[temp->left] = true;
			q.push({temp->left, tempAns + 1});	
		} 
		if(temp->right != NULL and visited[temp->right] == false)
		{	
			visited[temp->right] = true;
			q.push({temp->right, tempAns + 1});
		}
		if(parent[temp] != NULL and visited[parent[temp]] == false)
		{	
			visited[parent[temp]] = true;
			q.push({parent[temp], tempAns + 1});	
		} 
	}
	return ans;
}

int Solution:: solve(TreeNode* A, int B) 
{
    dfs(A, B);
	int ans = bfs();
	return ans;
}