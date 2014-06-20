#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str[10001];
	string prefix[10001];
	int count = 0;
	string tmp;
	while(!cin.eof()) {
		cin >> str[count++];
	}
	
	for(int i=0; i<count; i++) {//find the shortest prefix of ith string
		bool flag = false;
		for(int j=1; j<str[i].length(); j++) {
			//get the jth substring
			string substr = str[i].substr(0, j);
			
			//find where this substring exists in the other strings
			bool find = false;

			for(int k=0; k<count; k++) {
				if(k!=i) {
					if(str[k].length()>=j&&str[k].substr(0,j)==substr) {
						find = true;
						break;
					}
				}
			}

			if(!find) {
				prefix[i] = substr;
				flag = true;
				break;
			}
		}
		if(!flag) prefix[i] = str[i];

	}
	
	for(int i=0; i<count; i++) {
		//for(int j=0; j<str[i].length(); j++) cout << str[i][j];
		//cout << " ";
		//for(int j=0; j<prefix[i].length(); j++) cout << prefix[i][j];
		//cout << endl;
		cout << str[i] << " " << prefix[i] << endl;
	}
	return 0;
}