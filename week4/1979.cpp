#include <iostream>
#include <cmath>

using namespace std;

char rec[100][100];
int adj[1000][1000] = {0};
bool visited[1000];
int num = 1; // include itself
int W, H;

void DFS(int i) {
	for(int j=0; j<W*H; j++) {
		if(i!=j&&adj[i][j]==1&&!visited[j]) {
			visited[j] = true;
			//cout << "x=" << j/W << " y=" << j%W << endl;
			num++;
			DFS(j);
		}
	}
}


int main()
{
	while(cin >> W >> H) {
		num = 1;
		int initial = 0;
		if(W==0&&H==0) return 0;
		for(int i=0; i<H; i++) {
			for(int j=0; j<W; j++) {
				cin >> rec[i][j];
				if(rec[i][j]=='@') {
					initial = i*W+j;
					//cout << "initial:" << initial << endl;
				}
			}
		}
		//adjacent matrix, 1 means node i and node j are connected
		for(int i=0; i<H*W; i++) {
			for(int j=i+1; j<H*W; j++) {
				adj[i][j] = 1;
				adj[j][i] = 1;
			}
		}
		
		for(int i=0; i<H*W; i++) {
			for(int j=i+1; j<H*W; j++) {
				int x1 = i/W;
				int y1 = i%W;
				int x2 = j/W;
				int y2 = j%W;

				if((x1!=x2&&y1!=y2)||(x1==x2&&abs((double)y1-y2)>=2)||(y1==y2&&abs((double)x1-x2)>=2)||rec[x1][y1]=='#'||rec[x2][y2]=='#') {
					adj[i][j] = 0;
					adj[j][i] = 0;
				}
			}
		}
		//search from the initial tile
		/* for(int i=0; i<H*W; i++) {
			for(int j=0; j<H*W; j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		} */
		for(int i=0; i<H*W; i++) visited[i] = false;
		visited[initial] = true;
		DFS(initial);
		cout << num << endl;
	}
	return 0;
}
