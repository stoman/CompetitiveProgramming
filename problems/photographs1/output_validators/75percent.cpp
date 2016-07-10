//Author: Stefan Toman

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	string inputfile(argv[1]), judgefile(argv[2]);
	ifstream input(inputfile), judge(judgefile);
	int cases, correct = 0;
	input >> cases;
	for(int i = 0; i < cases; i++) {
		string judgein, teamin;
		judge >> judgein;
		cin >> teamin;
		if(judgein == teamin) correct++;
	}

	string feedbackdir(argv[3]);
	ofstream judgemessage(feedbackdir + "judgemessage.txt");
	judgemessage << correct << " of " << cases << " test cases correct." << endl;

	return 4*correct >= 3*cases ? 42 : 43;
}

