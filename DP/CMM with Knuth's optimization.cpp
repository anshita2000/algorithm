#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
#define MAX 5005
using namespace std;

// p[i][j]: ?d[i][j]�� �ּҰ� �Ǳ� ���� ���� ���� k

int tc,n,d[MAX][MAX],p[MAX][MAX];
vector<int> v,sum;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin>>tc;
	while(tc--) {
		cin>>n;
		v.clear(); v.resize(n+1,0);
		sum.clear(); sum.resize(n+1,0);
		for(int i=1; i<=n; ++i) {
			cin>>v[i];                    //v[i]: i ��° ������ ũ��
            sum[i] += sum[i-1] + v[i];    //sum[i]: i ��° ���ϱ��� ������ ũ����� ��
			p[i-1][i]=i;                  //p[i-1][i]���� i�� ����		
        } 
		for(int i=n-1;i>=1;--i) {
            for(int j=i+2; j<=n; ++j) {  //j�� i+2���� ����
                d[i][j] = INF;
			    for(int k = p[i][j-1]; k <= p[i+1][j]; ++k) {
					int val=d[i][k]+d[k][j];
					if(d[i][j]>val) {
				        p[i][j]=k;    //?p[i][j]�� d[i][j]�� �ּҰ� �Ǳ� ���� ���� ���� k�� ����
					    d[i][j]=val;
					}	
				}
				d[i][j]+=sum[j]-sum[i];    // ����� �ߺ��ǹǷ� for���� ������ ���
		    }
		}
		cout<<d[0][n]<<'\n';
	}
}
