#include "compiler.h"

int number_of_tokens = 0;
map<string, string> words;
pair<string, string> token_pairs[10000];

int tdobu;
int main() {
	
	int ch;
	
	init_lang();

	read_lines("test.txt");
	cout << " This is a simple compiler for a c++-toy language " << endl;
	cout << " 1- for lexical analysis " << endl;
	cout << " 2- for Top-Down parser  " << endl;
	cout << " 3- for Bottom_Up parser " << endl;

	cin >> ch;
	switch (ch)
	{
	case 1: lex_output();
		break;

	case 2:  div_and_parse_ll1();
		break;
	case 3: div_and_parse_slr();
		break;
	default:
		cout << " invalid choice..." << endl;
	}
	
	return 0;
}