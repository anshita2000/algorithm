const int MAX = 1e5+10;
const int k = 17; // 2^17 > 10��
int par[MAX][18],visited[MAX],d[MAX];
vertor<int> adj[MAX];

void DFS(int here,int depth) {
	visited[here]=true;
	d[here]=depth;
	for(auto there : adj[here]) {
		if(visited[there]) continue; 
		par[there][0]=here;
		DFS(there,depth+1);
	}
}

void SetLCA() {
    for(int j=1;j<=k;++j) {
    	for(int i=1;i<=n;++i) {
    		par[i][j]=par[par[i][j-1]][j-1];
		}
	}
}

int LCA(int u,int v) {
	if(d[u] < d[v]) swap(u,v);
	// �� ������ ���̸� �����
	for(int i=k; i>=0; --i) {
		if(d[u]-d[v] >= (1<<i))
			u=par[u][i];
	}
	// ���̸� ������ �� �� ������ �������ٸ� ���� ��ü�� LCA 
	if(u==v) return u;
	//�� ������ ������ ���Ѵ� 
	for(int i=k; i>=0; --i) {
		if(par[u][i] != par[v][i]) {
			u=par[u][i], v=par[v][i];
		}
	}
	//�� ������ �� ������ �θ� �����Ѵ� 
	return par[u][0];
}
