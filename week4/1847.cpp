#include <iostream>

using namespace std;

#define MAXN 150
#define INF 2147483647

long long dist[MAXN][MAXN];

int main()
{
	int N, A, B;
	cin >> N >> A >> B;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			dist[i][j] = INF;
		}
	}
	
	for(int i=1; i<=N; i++) {
		dist[i][i] = 0;
		int num;
		cin >> num;
		for(int j=1; j<=num; j++) {
			int tmp;
			cin >>tmp;
			if(j==1) dist[i][tmp] = 0;
			else dist[i][tmp] = 1;
		}
	}
	
	for(int k=1; k<=N; k++) {
		for(int i=1; i<=N; i++) {
			for(int j=1; j<=N; j++) {
				dist[i][j] = dist[i][j]<(dist[i][k]+dist[k][j])?dist[i][j]:(dist[i][k]+dist[k][j]);
			}
		}
	}
	if(dist[A][B]==INF) cout << "-1" << endl;
	else cout << dist[A][B] << endl;
	return 0;
}
