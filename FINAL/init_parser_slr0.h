


pair<string, int> rules[100] = {
	{ "S",2 },
	{ "S",2 },
	{ "S",2 },
	{ "S",2 },
	{ "DECLARATION",2 },
	{ "DECLARATION",2 },
	{ "ASSIGNMENT",3 },
	{ "EXPRESSION_TYPE",1 },
	{ "EXPRESSION_TYPE",1 },
	{ "EXPRESSION_TYPE",1},
	{ "NUMERICAL_EXPRESSION",1 },
	{ "E",2 },
	{ "E_PRIME",3},
	{ "E_PRIME",3 },
	{ "E_PRIME",1 },
	{ "T",2},
	{ "T_PRIME",3 },
	{ "T_PRIME",3 },
	{ "T_PRIME",1 },
	{ "T_PRIME",1 },
	{ "F",1 },
	{ "F",1 },
	{ "F",2 },
	{ "F",3 },
	{ "STRING_EXPRESSION",1 },
	{ "EXPRESSION",1 },
	{ "EXPRESSION",1 },
	{ "IF_EXPRESSION",7 },
	{ "CONDITION",4 },
	{ "VARIABLE",1 },
	{ "VARIABLE",1 },
	{ "VARIABLE",1 },
	{ "COMPARE",1 },
	{ "COMPARE",2 },
	{ "CONDITIONAL_OPERATOR",1},
	{ "CONDITIONAL_OPERATOR",1 },
	{ "CONDITIONAL_OPERATOR",2 },
	{ "CONDITIONAL_OPERATOR",2 },
	{ "EQ",1 },
	{ "EQ",1 },
	{ "WHILE_EXPRESSION",5 },

};

string ACTION[5][3] = {
	{ "s3", "", "" },
	{ "", "s4","s2" },
	{ "a", "a", "a" },
	{ "r2", "r2", "r2" },
	{ "r1", "r1", "r1" }
};

int GOTO[5][2] = {
	{ -1, 1 },
	{ -1,-1 },
	{ -1,-1 },
	{ -1,-1 },
	{ -1,-1 }
};

map<string, int> terminals = {
	{ "int", 0 },
	{ "str", 1 },
	{ "=", 2 },
	{ "+", 3 },
	{ "-", 4 },
	{ "*", 5 },
	{ "/", 6 },
	{ "(", 7 },
	{ ")", 8 },
	{ "?=", 9 },
	{ "!=", 10 },
	{ "<", 11 },
	{ ">", 12 },
	{ "number", 13 },
	{ "string", 14 },
	{ "identifier", 15 },
	{ ";", 16 },
	{ "$", 17 },
	{ "if", 18 },
	{ "then", 19 },
	{ "else", 20 },
	{ "endif", 21 },
	{ "while", 22 },
	{ "do", 23 },
	{ "endwhile", 24 }
};

map<string, int> nonterminals = {
	{ "S", 0 },
	{ "ASSIGNMENT", 1 },
	{ "DECLARATION", 2 },
	{ "EXPRESSION", 3 },
	{ "CONDITION", 4 },
	{ "NUMERICAL_EXPRESSION", 5 },
	{ "STRING_EXPRESSION", 6 },
	{ "E", 7 },
	{ "T", 8 },
	{ "E_PRIME", 9 },
	{ "T_PRIME", 10 },
	{ "F", 11 },
	{ "IF_EXPRESSION", 12 },
	{ "COMPARE", 13 },
	{ "CONDITIONAL_OPERATOR", 14 },
	{ "EQ", 15 },
	{ "VARIABLE", 16 },
	{ "WHILE_EXPRESSION", 17 },
	{ "EXPRESSION_TYPE", 18 }
};

