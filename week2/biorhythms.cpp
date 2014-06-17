#include <iostream>

using namespace std;

int* extendEuclid(int a, int b) {
	int *sol = new int[2];
	if(b==0) {
		sol[0] = 1;
		sol[1] = 0;
		return sol;
	} else {
		int *tmp = extendEuclid(b, a%b);
		sol[0] = tmp[1];
		sol[1] = tmp[0]-(int)(a/b)*tmp[1];
		return sol;
	}
}

int main()
{
	int p, e, i, d, result;
	int count = 0;
	
	while(cin >> p >> e >> i >> d) {
		if(p==-1) break;
		count++;
		int *tmp1 = extendEuclid(23, 28);
		int x1 = (e-p)*tmp1[0]*23+p;
		
		int *tmp2 = extendEuclid(23, 33);
		int x2 = (i-p)*tmp2[0]*23+p;
		
		int *tmp3 = extendEuclid(28, 33);
		int x3 = (x2-x1)/23*tmp3[0]*23*28+x1;
		
		int lcm = 23 * 28 * 33;
		if(x3<d) {
			while(x3<d) {
				x3 += lcm;
			}
			if(x3==d) result = lcm;
			else result = x3-d;
		} else if (x3==d) {
			result = lcm;
		} else {
			while(x3>d) {
				x3 -= lcm;
			}
			if(x3==d) result = lcm;
			else result = x3+lcm-d;
		}
		cout << "Case " << count << ": the next triple peak occurs in " << result << " days." << endl;
	} 
	return 0;
}
