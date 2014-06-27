#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define MAX 10001

int father[MAX];
int rank[MAX];

int find(int x) {
	if(x==father[x]) return father[x];
	else {
		return find(father[x]);
	}
}
// 树的条件：连通，边数=节点数-1

int main()
{
	int m, n;
	int count = 0;
	bool flag = true;
	int edge = 0;
	set <int> node;
	set <int>::iterator it;
	
	for(int i=1; i<MAX; i++) father[i] = i;
	for(int i=1; i<MAX; i++) rank[i] = 0;
	while(cin>>m>>n) {
		if(m==-1&&n==-1) {
			return 0;
		} else {
			if(m>0&&n>0) { 
				edge++;
				node.insert(m);
				node.insert(n);
				int big = m>n?m:n;
				int small = m<n?m:n;
				
				int fatherbig = find(big);
				int fathersmall = find(small);
				if(fatherbig!=fathersmall) {
					if(rank[fatherbig]>rank[fathersmall]) {
						father[small] = big;
						rank[fatherbig]++;
					} else if(rank[fatherbig]<rank[fathersmall]) {
						father[big] = small;
						rank[fathersmall]++;
					} else {
						father[small] = big;
						rank[fatherbig]++;
					}
				}
				
			} else { 
				count++; 
				if(node.size()==0) { 
					cout << "Case " << count << " is a tree." << endl;	
				} else {
					it = node.begin();
					int fa = find(*it); 
				
					for(set<int>::iterator it2=++it; it2!=node.end(); it2++) {
						if(find(*it2)!=fa) {
							flag = false;
							break;
						}
					}
					if(flag&&edge==node.size()-1) { 
						cout << "Case " << count << " is a tree." << endl;	
					} else {
						cout << "Case " << count << " is not a tree." << endl;
					}
				}
				
				for(int i=1; i<MAX; i++) father[i] = i;
				for(int i=1; i<MAX; i++) rank[i] = 0;
				node.clear();
				flag = true;
				edge = 0;
			}
		}
	}
}
