#include "compiler.h"
#include "init_parser_ll1.h"

string temp_arr[100];

int calc_len(Sayyed * arr) {
	int i = 0;
	while (arr->name != "\0") {
		i++;
		arr++;
	}
	return i;
}



int parse_ll1(string input[100])
{

	/*EXAMPLE*/
	stack <Sayyed> stack;
	stack.push(end_character);
	stack.push(S);
	int i = 0;

	cout << "------------------------------------------------------------\n                      --- Parsing ---                     \n------------------------------------------------------------\n";

	while (true) {
		string temp18 = input[i];
		Sayyed top = stack.top();

		if (top.name == "$" && temp18 == "$") {
			cout << "-----------------------------------------------------------\n                     --- Parsing OK ---                     \n------------------------------------------------------------\n";
			return 1;
		}
		else if (top.ToN == non_terminal)
		{
			int non_terminal_index = nonterminals[top.name];
			int terminal_index = terminals[temp18];
			Sayyed * current_rule = parse_table[non_terminal_index][terminal_index];
			if (current_rule == NULL)
			{
				cout << "Parsing Error... Input not compatible with grammar\n" << endl;
				return -1;
			}
			stack.pop();
			cout << top.name << " -> ";

			int len;

			if (current_rule->name == "epsilon")
				len = 1;
			else
				len = calc_len(current_rule);

			for (int j = len - 1; j >= 0; j--) {
				stack.push(current_rule[j]);

			}
			for (int j = 0; j < len; j++) {
				cout << current_rule[j].name << "  ";
			}
			cout << endl;
			continue;
		}
		else if (top.ToN == terminal)
		{
			if (top.name == epsilon.name)
			{
				stack.pop();
			}
			else
			{
				if (top.name == temp18)
				{
					i++;
					stack.pop();
				}
				else
				{

					cout << "Parsing Error... Input not compatible with grammar\n";
					return -1;
				}
			}
		}
		//cout << endl;
	}

}

void div_and_parse_ll1()
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
			if (parse_ll1(temp_arr) < 0)
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