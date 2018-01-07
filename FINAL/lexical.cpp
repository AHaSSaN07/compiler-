#include "compiler.h"


string temp = "";
bool comment = false;
void init_lang()
{
    words["int"] = "keyword";
    words["word"] = "keyword";
    words["while"] = "keyword";
    words["do"] = "keyword";
    words["endwhile"] = "keyword";
    words["if"] = "keyword";
    words["then"] = "keyword";
    words["else"] = "keyword";
    words["endif"] = "keyword";
    words["+"] = "operator";
    words["-"] = "operator";
    words["*"] = "operator";
    words["/"] = "operator";
    words["="] = "operator";
    words["?="] = "operator";
    words["!="] = "operator";
    words["("] = "special character";
    words[")"] = "special character";
    words["<"] = "special character";
    words[">"] = "special character";
    words[";"] = "special character";
}

void read_lines(string file_path)
{
	string line;
	ifstream File(file_path);
	if (!File)
		cout << "Error opening the file " << endl;

	while (File)
		while (getline(File, line))
			if (line != "" && line != "\n")
				lex(line);
}

void lex(string line)
{
	int index = 0;
	bool quotes = false;

	for (unsigned int i = 0; i < line.length(); i++)
	{
		char c = (char)line[i];
		string s(1, c);
		if (!comment) {
			if (!quotes)
			{
				if (c == '\"')
				{
					add_token_pair("command");
					quotes = true;
				}
				else if (c == ' ' || c == '\t')
				{
					add_token_pair("command");
				}
				else if (c == '<')
				{
					add_token_pair("command");
					if ((char)line[i + 1] == '<')
					{
						temp = "<<";
						i++;
					}
					else temp = "<";
					add_token_pair("command");
				}
				else if (c == '>')
				{
					add_token_pair("command");
					temp = ((char)line[i + 1] == '>') ? ">>" : ">";
					add_token_pair("command");
					if ((char)line[i + 1] == '>')
						i++;
				}
				else if (c == '/') {
					add_token_pair("command");
					if ((char)line[i + 1] == '/')
						return;
					else if ((char)line[i + 1] == '=') {
						temp = "/=";
						i++;
					}
					else if ((char)line[i + 1] == '*') {
						comment = true;
						i++;
					}
					else {
						temp = "/";
					}
					add_token_pair("command");
				}
				else if (words[s] == "special character")
				{
					add_token_pair("command");
					temp = c;
					add_token_pair("command");
				}
				else
				{
					temp += c;
				}
			}
			else
			{
				if (c == '\"')
				{
					quotes = false;
					add_token_pair("quotes");
				}
				else
					temp += c;
			}
		}
		else {
			if (c == '*') {
				if ((char)line[i + 1] == '/') {
					comment = false;
					i++;
				}
			}
		}
	}
}

bool add_token_pair(string sender)
{
	if (temp.length() != 0) {
		if (sender == "quotes")
		{
			token_pairs[number_of_tokens].first = "string";
		}
		else
		{
			if (words[temp] != "\0")
				token_pairs[number_of_tokens].first = words[temp];
			else if ((char)temp[0] >= '0' && (char)temp[0] <= '9') {
				token_pairs[number_of_tokens].first = "number";
			}
			else
			{
				if (check_id_names_validity())
				{
					token_pairs[number_of_tokens].first = "identifier";
				}
				else
				{
					cout << "Lexical Error... \"" << temp << "\" is an illegal identifier.\n";
					exit(0);
				}
			}
		}
		token_pairs[number_of_tokens++].second = temp;
		temp = "";
		return true;
	}
	return false;
}

bool check_id_names_validity()
{
	for (unsigned int i = 0; i < temp.length(); i++)
	{
		if ((temp[i] >= 33 && temp[i] <= 47) || (temp[i] >= 58 && temp[i] <= 64) || (temp[i] >= 91 && temp[i] <= 96) || (temp[i] >= 123 && temp[i] <= 126))
		{
			return false;
		}
	}
	if (temp[0] >= 48 && temp[0] <= 57) return false; // id doesn't start with numbers 
	else return true;
}


void lex_output()
{
	cout << "------------------------------------------------------------\n                    --- Lexical Analysis ---                     \n------------------------------------------------------------\n";
	for (int i = 0; i < number_of_tokens; i++) {
		cout << "<\"" << token_pairs[i].second << "\", " << token_pairs[i].first << ">\n";
	}
}
