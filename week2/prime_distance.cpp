#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;




int prime[1000100] = {0};
int isPrime[1000100] = {0};
int prime2[50000] = {0};
int prime3[50000] = {0};

int main()
{	
	unsigned int L, U;
	int num = 0;
	//calculate the prime number between 2 and sqrt(2147483647)+1
	//here 0 is prime, 1 is non-prime
	int obj = (int)sqrt((double)2147483647)+1;
	for(int i=2; i<=obj; i++) {
		if(prime2[i]==0) {
			prime3[num] = i;
			num++;
			for(int j=i*i; j<=obj; j+=i){
				prime2[j] = 1;
			}
		}
	}
	
	
	while(scanf("%d%d", &L, &U)==2) {
		int minx=0, miny=0, minDis=2147483647;
		int maxx=0, maxy=0, maxDis=0;
		
		//cancel the non-prime number between L and U,
		// if i is non-prime, then isPrime[i-L] = 0;
		int count = 0;
		for(int i=0; i<1000100; i++) isPrime[i] = 1;
		if (L==1) L =2;
		for(int i=0; i<num&&(long long)prime3[i]*prime3[i]<=U; i++) {
		// a is the nearest number less or equal L which is multiple of prime3[i]
			int a = L/prime3[i]*prime3[i];
			for(int j=a; j<=U; j+=prime3[i]) {
				if(j>=L&&j!=prime3[i]) { //cancel the non-prime number
					isPrime[j-L] = 0;
				}
			}
		}
		
		//count the prime number between L and U
		for(int i=0; i<=U-L; i++) {
			if(isPrime[i]==1) {
				prime[count++] = i+L;
			}
		}
		
		//find the minimum and maximum distance 
		for(int j=0; j<count-1; j++) {
			if(prime[j+1]-prime[j]<minDis) {
				minDis = prime[j+1]-prime[j];
				minx = prime[j];
				miny = prime[j+1];
			}
			if(prime[j+1]-prime[j]>maxDis) {
				maxDis = prime[j+1]-prime[j];
				maxx = prime[j];
				maxy = prime[j+1];
			}
		}
		
		if(count<2) {
			printf("%s\n", "There are no adjacent primes."); 
		} else {
			printf("%d,%d are closest, %d,%d are most distant.\n", minx, miny, maxx, maxy);
		}
	}
	return 0;
}
