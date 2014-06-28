#include <iostream>

using namespace std;

int a[100];
int b[100];

int main()
{
	int n;
	while((cin>>n)&&n!=-1) {
		for(int i=0; i<n; i++) {
			cin >> a[i] >> b[i];
		}

		int sum = 0;
		sum += a[0]*b[0];
		for(int i=1; i<n; i++) {
			sum += a[i]*(b[i]-b[i-1]);
		}
		cout << sum << " miles" << endl;
	}
	return 0;
}
