struct DisjointSet {
	vector<int> parent,rank;

    //�����ڷ� �θ� �ڱ� �ڽ����� �ʱ�ȭ
	DisjointSet(int n): parent(n+1),rank(n+1) {
		for(int i=1;i<=n;++i) parent[i]=i;
	}

    //�θ� ã�´�.
	int find(int x) {
		return parent[x] == x ? x : find(parent[x]);
	}
    
    //�θ� ��ģ��.
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if(a == b) return;
        //a�� v���� rank�� ������ ����
        if(rank[a] > rank[v]) swap(a,b);
        parent[a] = v;
        if(rank[a] == rank[b]) ++rank[v];
	}
};



//��ȣ�� ���� ���� union�ϵ��� ������ union-find 
int getParent(int x) {
	return x==parent[x]? x : getParent(parent[x]);
}

void merge(int a,int b) {
	a=getParent(a); b=getParent(b);
	a<b? parent[b]=a : parent[a]=b; 
}

int main() {
	for(int i=1; i<=n ; ++i) parent[i]=i;
} 
