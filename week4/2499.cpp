#include <iostream>
#include <cmath>
using namespace std;


int main()
{
	int n, i, j;
	cin >> n;

	for(int k=0; k<n; k++) {
		cin >> i >> j;
		int left = 0;
		int right = 0;
		
		while(i!=1||j!=1) {
			if(i>j) {
				int tmp = ceil((double)i/j-1);
				i = i-tmp*j;
				left+=tmp;
			} else {
				int tmp = ceil((double)j/i-1);
				j = j-tmp*i;
				right+=tmp;
			}
		}

		cout << "Scenario #" << k+1 << ":" << endl;
		cout << left << " " << right << endl;
		cout << endl;
 	}
	return 0;

}
