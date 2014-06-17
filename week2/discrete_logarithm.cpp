#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

struct BmodP {
	long long index;
	long long value;
}mod1[10000000];

bool cmp(BmodP tmp1, BmodP tmp2) {
	if(tmp1.value<tmp2.value || (tmp1.value==tmp2.value&&tmp1.index<tmp2.index))  return true;
	return false;
}

long long* extendEuclid(long long a, long long b) {
	long long *sol = new long long[2];
	if(b==0) {
		sol[0] = 1;
		sol[1] = 0;
		return sol;
	} else {
		long long *tmp = extendEuclid(b, a%b);
		sol[0] = tmp[1];
		sol[1] = tmp[0]-(long long)floor(a/b)*tmp[1];
		return sol;
	}
}

// a^n%p
long long pow_mod(long long a, long long n, long long p) {
	if(n==0) return 1;
	long long x = pow_mod(a, n/2, p);
	long long ans = ((x%p) * (x %p))%p;
	if(n%2==1) ans = ((ans%p)*(a%p))%p;
	return ans;
}

long long bi_search(long long m, long long x) {
	long long low = 0;
	long long high = m-1;
	
	while(low<=high) {
		long long mid = (low+high)/2;
		if(mod1[mid].value==x) {
			return mod1[mid].index;
		} else if(mod1[mid].value<x) {
			low = mid+1;
		} else {
			high = mid-1;
		}	
	}
	return -1;
}

int main()
{
	long long P, B, N;
	while(scanf("%lld%lld%lld", &P, &B, &N)!=EOF) {
		bool is_find = false;
		long long m = (long long)ceil(sqrt((double)(P)));
		//calculate B^j%p, j=0,1,...,m-1
		
		for(long long j=0; j<m; j++) {
			mod1[j].index = j;
			mod1[j].value = pow_mod(B, j, P);
		}
		//sort array mod1, later used for binary search
		sort(mod1, mod1+m, cmp);
		//There may exist same value with different index, let the big index be the small index
		//otherwise, binary search may find the bigger index
		for(long long i=0; i<m-1; i++) {
			if(mod1[i+1].value==mod1[i].value) {
				mod1[i+1].index = mod1[i].index;
			}
		}
		
		
		//calculate N*inv(B^{im})%P, i=0,1,...,m-1
		
		long long *invB = extendEuclid(B, P);
		
		
		while(invB[0] <0) invB[0]+=P;
		
		//long long bm = pow_mod(invB[0], m, P);
		for(long long i=0; i<m; i++) {
			long long tmp = pow_mod(invB[0], i*m, P);
			long long res = ((tmp%P) * (N % P))%P;
			//serach res in mod1
			long long j = bi_search(m, res);
			
			if(j!=-1) {
				long long L = i*m + j;
				cout  << L << endl;
				is_find = true;
				break;
			}
		}
		if(!is_find) cout << "no solution" << endl;
	}
	return 0;
}
