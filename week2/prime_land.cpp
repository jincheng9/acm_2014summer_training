#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <cmath>

using namespace std;

int c[40000] = {0};

int a[2000] = {0};



int power(int m, int n) {
	int sum = 1;
	for(int i=0; i<n; i++) {
		sum *= m;
	}	
	return sum;
}

int main()
{
	string s;
	//lessNPrime(32767);

	while(getline(cin, s)) {
		
		if(s=="0") break;
		else {
			vector<string> str;
			char * pch;
			pch = strtok(const_cast<char*>(s.c_str()), " ");
			while(pch !=NULL) {
				str.push_back(pch);
				pch = strtok(NULL, " ");
			}

			for(int i=0; i<str.size(); i++) {
				a[i] = atoi(str[i].c_str());
			}
			// calculate the number
			int sum = 1;
			for(int j=0; j<=str.size()-2; j+=2) {
				sum *= power(a[j],a[j+1]);
			}
			sum -= 1;
			//get another representation

			//memset(c, 0, 40000);
			
			
			for(int i=0; i<40000; i++) c[i] = 0;
			int tmp = sum;

			for(int k=2; k<=tmp; k++) {
					while(tmp%k==0) {
						c[k]++;
						tmp /= k;
					}
			}

			//output the representation
			
			for(int t=sum; t>=2; t--) {
				if(c[t]>0) {
					cout << t << " " << c[t] << " ";
				}
			}
			cout <<  endl;
			
		} 
	}

	return 0;
}
