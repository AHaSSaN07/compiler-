#include "compiler.h"
#include "init_parser_slr0.h"

string temp_arr[100];

int calc_len(Sayyed * arr) {
	int i = 0;
	while (arr->name != "\0") {
		i++;
		arr++;
	}
	return i;
}


int parse_slr0(string input[100])
{
	stack <int> stack;
	stack.push(0);

	int itr = 0;
	string current_token = input[itr];

	while (true) {
		int state = stack.top();    /* current state is taken from top of stack */
		int current_token_index = terminals[current_token];
		if (ACTION[state][current_token_index][0] == 's')   /* shift and go to state i */
		{
			int a = atoi(&ACTION[state][current_token_index][1]);
			stack.push(a);
			itr++;
			current_token = input[itr];
		}
		else if (ACTION[state][current_token_index][0] == 'r') {
			/* reduce by rule i: X ::= A1...An */
			int rule_index = atoi(&ACTION[state][current_token_index][1]);
			for (int i = 0; i < rules[rule_index].second; i++)
				stack.pop();

			state = stack.top();    /* restore state before reduction from top of stack */

			int nonterminal_index = nonterminals[rules[rule_index].first];
			stack.push(GOTO[state][nonterminal_index]);   /* state after reduction */
		}
		else if (ACTION[state][current_token_index] == "a") {
			cout << "Horraaay!!" << endl;
			return 1;
		}
		else {
			perror("*blows rasperry*");
			return 0;
		}
	}


}

void div_and_parse_slr0()
{
	int idx = 0, j = 0;
	bool if_flag = false;

	cout << endl << endl;

	for (int i = 0; i < number_of_tokens; i++) {
		cout << token_pairs[i].second << " ";
	}
	cout << endl;


	for (int i = 0; (i <= number_of_tokens); i++)
	{

		if ((token_pairs[i - 1].second == ";") && (!if_flag))
		{
			temp_arr[j] = "$";
			if (parse_slr0(temp_arr) < 0)
				exit(0);
			j = 0;
		}


		if (token_pairs[i].second == "if" || token_pairs[i].second == "while") {
			if_flag = true;
		}
		else if (token_pairs[i].second == "endif" || token_pairs[i].second == "endwhile") {
			if_flag = false;
			temp_arr[j] = token_pairs[i].second;

		}



		if (token_pairs[i].first == "identifier")
			temp_arr[j] = "identifier";
		else if (token_pairs[i].first == "string")
			temp_arr[j] = "string";
		else if (token_pairs[i].first == "number")
			temp_arr[j] = "number";
		else
			temp_arr[j] = token_pairs[i].second;
		j++;
	}
}