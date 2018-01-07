/*TERMINALS*/
Sayyed D_int = { "int", terminal };
Sayyed D_string = { "str", terminal };
Sayyed equall = { "=", terminal };
Sayyed pluss = { "+", terminal };
Sayyed minuss = { "-", terminal };
Sayyed star = { "*", terminal };
Sayyed division = { "/", terminal };
Sayyed o_paren = { "(", terminal };
Sayyed c_paren = { ")", terminal };
Sayyed e_equal = { "?=", terminal };
Sayyed n_equal = { "!=", terminal };
Sayyed lesss = { "<", terminal };
Sayyed greater = { ">", terminal };
Sayyed number = { "number", terminal };
Sayyed v_string = { "string", terminal };
Sayyed identifier = { "identifier", terminal };
Sayyed semi_colon = { ";", terminal };
Sayyed cond_if = { "if", terminal };
Sayyed cond_then = { "then", terminal };
Sayyed cond_else = { "else", terminal };
Sayyed cond_endif = { "endif", terminal };
Sayyed loop_while = { "while", terminal };
Sayyed loop_do = { "do",terminal };
Sayyed loop_endwhile = { "endwhile", terminal };
Sayyed epsilon = { "epsilon", terminal };
Sayyed end_character = { "$", terminal };


/*NON-TERMINALS*/
Sayyed S = { "S", non_terminal };
Sayyed ASSIGNMENT = { "ASSIGNMENT", non_terminal };
Sayyed DECLARATION = { "DECLARATION", non_terminal };
Sayyed EXPRESSION = { "EXPRESSION", non_terminal };
Sayyed NUMERICAL_EXPRESSION = { "NUMERICAL_EXPRESSION", non_terminal };
Sayyed STRING_EXPRESSION = { "STRING_EXPRESSION", non_terminal };
Sayyed E = { "E", non_terminal };
Sayyed T_PRIME = { "T_PRIME", non_terminal };
Sayyed E_PRIME = { "E_PRIME", non_terminal };
Sayyed T = { "T", non_terminal };
Sayyed F = { "F", non_terminal };
Sayyed CONDITION = { "CONDITION", non_terminal };
Sayyed COMPARE = { "COMPARE", non_terminal };
Sayyed IF_EXPRESSION = { "IF_EXPRESSION", non_terminal };
Sayyed WHILE_EXPRESSION = { "WHILE_EXPRESSION", non_terminal };
Sayyed CONDITIONAL_OPERATOR = { "CONDITIONAL_OPERATOR", non_terminal };
Sayyed EQ = { "EQ", non_terminal };
Sayyed VARIABLE = { "VARIABLE", non_terminal };
Sayyed EXPRESSION_TYPE = { "EXPRESSION_TYPE", non_terminal };

/*RULES*/
Sayyed  _S[7][7] = { { ASSIGNMENT , semi_colon },{ DECLARATION , semi_colon },{ EXPRESSION , semi_colon }, {epsilon} };
Sayyed  _DECLARATION[7][7] = { { D_int , ASSIGNMENT },{ D_string , ASSIGNMENT } };
Sayyed  _ASSIGNMENT[7][7] = { { identifier , equall , EXPRESSION_TYPE } };
Sayyed  _EXPRESSION_TYPE[7][7] = { { NUMERICAL_EXPRESSION },{ STRING_EXPRESSION } ,{ epsilon } };
Sayyed  _NUMERICAL_EXPRESSION[7][7] = { { E } };
Sayyed  _E[7][7] = { { T , E_PRIME } };
Sayyed  _E_PRIME[7][7] = { { pluss , T , E_PRIME } ,{ minuss , T , E_PRIME } ,{ epsilon } };
Sayyed  _T[7][7] = { { F,T_PRIME } };
Sayyed  _T_PRIME[7][7] = { { star , F , T_PRIME } ,{ division , F , T_PRIME },{ epsilon } };
Sayyed  _F[7][7] = { { identifier },{ number },{ minuss , F },{ o_paren , E , c_paren } };
Sayyed  _STRING_EXPRESSION[7][7] = { { v_string } };
Sayyed  _EXPRESSION[7][7] = { { IF_EXPRESSION },{ WHILE_EXPRESSION } };
Sayyed  _IF_EXPRESSION[7][7] = { { cond_if , CONDITION , cond_then , S , cond_else , S , cond_endif } };
Sayyed  _CONDITION[7][7] = { {o_paren , VARIABLE , COMPARE , c_paren } };
Sayyed  _VARIABLE[7][7] = { { identifier },{ number },{ v_string } };
Sayyed  _COMPARE[7][7] = { { epsilon },{ CONDITIONAL_OPERATOR, VARIABLE } };
Sayyed  _CONDITIONAL_OPERATOR[7][7] = { { e_equal },{ n_equal },{ greater , EQ } , { lesss , EQ} };
Sayyed  _EQ[7][7] = { { equall },{ epsilon } };
Sayyed  _WHILE_EXPRESSION[7][7] = { { loop_while, CONDITION, loop_do, S, loop_endwhile} };


/*PARSE TABLE*/
Sayyed* parse_table[19][25] = {
	{ _S[1],_S[1],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_S[0],NULL,&epsilon,_S[2],NULL,&epsilon,&epsilon,_S[2],NULL,&epsilon },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_ASSIGNMENT[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ _DECLARATION[0],_DECLARATION[1],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_EXPRESSION[0],NULL,NULL,NULL,_EXPRESSION[1],NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,_CONDITION[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,_NUMERICAL_EXPRESSION[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_NUMERICAL_EXPRESSION[0],NULL,_NUMERICAL_EXPRESSION[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_STRING_EXPRESSION[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,_E[0],NULL,NULL,_E[0],NULL,NULL,NULL,NULL,NULL,_E[0],NULL,_E[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,_T[0],NULL,NULL,_T[0],NULL,NULL,NULL,NULL,NULL,_T[0],NULL,_T[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,&epsilon,_E_PRIME[0],_E_PRIME[1],NULL,NULL,NULL,&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,&epsilon,&epsilon,_T_PRIME[0],_T_PRIME[1],NULL,&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,_F[2],NULL,NULL,_F[3],NULL,NULL,NULL,NULL,NULL,_F[1],NULL,_F[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_IF_EXPRESSION[0],NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&epsilon,_COMPARE[1],_COMPARE[1],_COMPARE[1],_COMPARE[1],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_CONDITIONAL_OPERATOR[0],_CONDITIONAL_OPERATOR[1],_CONDITIONAL_OPERATOR[2],_CONDITIONAL_OPERATOR[3],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,_EQ[0],NULL,NULL,NULL,NULL,NULL,&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_VARIABLE[1],_VARIABLE[2],_VARIABLE[0],NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL },
	{ NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,_WHILE_EXPRESSION[0],NULL,NULL },
	{ NULL,NULL,NULL,NULL,_EXPRESSION_TYPE[0],NULL,NULL,_EXPRESSION_TYPE[0],NULL,NULL,NULL,NULL,NULL,_EXPRESSION_TYPE[0],NULL,_EXPRESSION_TYPE[0],&epsilon,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL }
};
/*T/N-T ENUMS*/
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
	{ ">", 12},
	{ "number", 13 },
	{ "string", 14 },
	{ "identifier", 15 },
	{ ";", 16 },
	{ "$", 17  },
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
