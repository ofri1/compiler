%{

/* Declarations section */
#include <stdio.h>
#include "output.hpp"
#include "parser.hpp"
#include "parser.tab.hpp"

using namespace output;


%}

%option yylineno
%option noyywrap
%option caseless

%%

[\n|\r|\r\n|\t| ]			;

"void"						return VOID;
"int"						return INT;
"byte"						return BYTE;
"bool"						return BOOL;
"struct"					return STRUCT;
"and"						return AND;
"or"						return OR;
"not"						return NOT;
"true"						return TRUE;
"false"						return FALSE;
"return"					return RETURN;
"if"						return IF;
"else"						return ELSE;
"while"						return WHILE;
"break"						return BREAK;
"continue"					return CONTINUE;
;							return SC;
\,							return COMMA;
\.							return PERIOD;
\(							return LPAREN;
\)							return RPAREN;
\{							return LBRACE;
\}							return RBRACE;
=							return ASSIGN;
==|!=						yylval = new Node(yytext); return RELOPL;
\<|\>|\<=|\>=				yylval = new Node(yytext); return RELOPN;
\*|\/						yylval = new Value_node("BINOP",yytext);return MULDIV;
\+|\-						yylval = new Value_node("BINOP",yytext);return ADDSUB;
"b"							return B; 
[a-zA-Z][a-zA-Z0-9]*		yylval = new Value_node("ID",yytext);return ID;
0|[1-9][0-9]*				yylval = new Value_node("INT",yytext); return NUM;
\"([^\n\r\"\\]|\\[rnt"\\])+\"	yylval = new Value_node("STRING",yytext); return STRING;
\/\/[^\r\n]*[\r|\n|\r\n]?	;
.							errorLex(yylineno); exit(0);

%%