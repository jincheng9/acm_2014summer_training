#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Unit {
	int row;
	int col;
}stone[140000];

bool cmp1(Unit u1, Unit u2) {
	return u1.row < u2.row || (u1.row==u2.row&&u1.col<u2.col);
}

bool cmp2(Unit u1, Unit u2) {
	return u1.col < u2.col || (u1.col==u2.col&&u1.row<u2.row);
}

int main()
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		int sum = 0;//# of positions
		int m, n, k;
		scanf("%d%d%d", &m, &n, &k);
		for(int j=0; j<k; j++) {
			scanf("%d%d", &stone[j].row, &stone[j].col);
		}
		if(k==0) {
			
			if(m>=2) sum+=n;
			if(n>=2) sum+=m;
			cout << sum << endl;
			continue;
		}
		//sort based on row
		sort(stone, stone+k, cmp1);
		//the first case, m==1
		if(m==1) {
			if(stone[0].col>=3) sum++;
			for(int j=1; j<k; j++) {
				if(stone[j].col-stone[j-1].col>=3) sum++;
			}
			if(n-stone[k-1].col>=2) sum++;
			cout << sum << endl;
			continue;
		}
		//the second case, n==1
		if(n==1) {
			if(stone[0].row>=3) sum++;
			for(int j=1; j<k; j++) {
				if(stone[j].row-stone[j-1].row>=3) sum++;
			}
			if(m-stone[k-1].row>=2) sum++;
			cout << sum << endl;
			continue;
		}
		//the third case, m>=2, n>=2
		//the 1st square and the 1st stone
		sum += (stone[0].row-1);
		if(stone[0].col>=3) sum++;
		//the jth stone and the j+1th stone	
		for(int j=1; j<k; j++) {
			if(stone[j].row==stone[j-1].row) {
				if(stone[j].col-stone[j-1].col>=3) {
					sum++;
				}
			} else {
				sum += (stone[j].row-stone[j-1].row-1);
				if(n-stone[j-1].col>=2) sum++;
				if(stone[j].col>=3) sum++;
			}
		}
		//the last stone and the rightmost square
		if(stone[k-1].row==m) {
			if(n-stone[k-1].col>=2) sum++;
		} else {
			sum += m-stone[k-1].row;
			if(n-stone[k-1].col>=2) sum++;
		}
		
		//sort based on col
		sort(stone, stone+k, cmp2);
		//the 1st square and the 1st stone
		sum += (stone[0].col-1);
		if(stone[0].row>=3) sum++;
		//the jth stone and the j+1th stone	
		for(int j=1; j<k; j++) {
			if(stone[j].col==stone[j-1].col) {
				if(stone[j].row-stone[j-1].row>=3) {
					sum++;
				}
			} else {
				sum += (stone[j].col-stone[j-1].col-1);
				if(m-stone[j-1].row>=2) sum++;
				if(stone[j].row>=3) sum++;
			}
		}
		//the last stone and the rightmost square
		if(stone[k-1].col==n) {
			if(m-stone[k-1].row>=2) sum++;
		} else {
			sum += n-stone[k-1].col;
			if(m-stone[k-1].row>=2) sum++;
		}
		
		printf("%d\n", sum);
	}
	return 0;
}
