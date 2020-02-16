#define MAX 500000

bool s[MAX+1];
vector<int> prime;

void getPrime() {
	for(int i=2; i<=MAX; ++i) s[i]=1;
	for(int i=2; i*i<MAX; ++i) {
		if (s[i] == 0) continue;
		for (int j = i * i; j <= MAX; j += i) {
			s[j] = 0;
		}
	}
	for(int i=2; i<=MAX; ++i) if(s[i]) prime.push_back(i);
}


// ���μ� ���� 
int n,minFactor[MAX+1];

void getPrime2(int n) {
	for(int i=2; i<=n; ++i) minFactor[i]=i;
	for(int i=2; i*i<=n; ++i) {
		if (minFactor[i] == i)
		for (int j = i * i; j <= MAX; j += i) {
			//���� ����� �� �� ���� ������ ��쿡 ����
			if(minFactor[j] == j) 
				minFactor[j] = i;
		}
	}
}

vector<int> factor(int n) {
	vector<int> ret;
	while(n>1) {
		int num = minFactor[n];
		ret.push_back(num);
		n/=num;
	}
	return ret;
}
