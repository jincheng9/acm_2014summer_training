#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int i=0; i<T; i++) {
		char *year = new char[4+1];
		char *month = new char[2+1];
		char *day = new char[2+1];
		char *hour = new char[2+1];
		char *min = new char[2+1];
		char *sec = new char[2+1];
		string s;
		cin >> s; 
		
		for(int j=0; j<4; j++) year[j] = s[j]; 
		
		for(int j=0; j<2; j++) month[j] = s[j+5];
		
		for(int j=0; j<2; j++) day[j] = s[j+8];
		
		for(int j=0; j<2; j++) hour[j] = s[j+11];
		
		for(int j=0; j<2; j++) min[j] = s[j+14];
		
		for(int j=0; j<2; j++) sec[j] = s[j+17];
		
		year[4] = '\0';
		month[2] = '\0';
		day[2] = '\0';
		hour[2] = '\0';
		min[2] = '\0';
		sec[2] = '\0';
		
		char c;
		int a = (hour[0]-'0')*10+(hour[1]-'0');
		
		// determine c
		if(a<=11) c = 'a';
		else c= 'p';
		
		// determine hour
		if(a==0) {
			hour[0] = '1';
			hour[1] = '2';
		} else if(a >=13 && a<=23) {
			hour[0] = (char)(int)'0'+(hour[0]-'1');
			hour[1] = (char)(int)'0'+(hour[1]-'2');
		}
		cout << month  << '/' << day << '/' << year << '-' << hour << ':' << min << ':' << sec << c << 'm' << endl;
		delete []year;
		delete []month;
		delete []day;
		delete []hour;
		delete []min;
		delete []sec;
	}
	return 0;
}
