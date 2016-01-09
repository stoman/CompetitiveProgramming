//Author: Stefan Toman

#include <stdio.h>
#include <string>
#include <map>

using namespace std;

string trim(string s) {
	int pos = s.find("\n");
	return pos == string::npos ? s : s.substr(0, pos);
}

int main() {
    int n;
	map<string, long> phonebook;
	char name[100];
	scanf("%d", &n);
	fgets(name, 100, stdin);//empty line
	for (int i = 0; i < n; ++i) {
		long number;
		fgets(name, 100, stdin);
		scanf("%ld", &number);
		phonebook[trim(string(name))] = number;
		fgets(name, 100, stdin);//empty line
	}
	while(fgets(name, 100, stdin) != NULL) {
		map<string, long>::iterator it = phonebook.find(trim(string(name)));
		if(it == phonebook.end()) {
			printf("Not found\n");
		}
		else {
			printf("%s=%ld\n", it->first.c_str(), it->second);
		}
	}
	return 0;
}
