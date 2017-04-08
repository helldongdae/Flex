%{
#include "myscanner.h"
%}
%option nounput yylineno

%%
:				return COLON;
[;]				return SEMICOLON;
"public"			return ACCESSMOD;
"private"			return ACCESSMOD;
"default"			return ACCESSMOD;
"protected"			return ACCESSMOD;
"int"				return VARIABLE;
"float"				return VARIABLE;
"double"			return VARIABLE;
"void"				return VARIABLE;
"String"			return VARIABLE;
"class"				return CLASS;
"import"			return IMPORT;
"/*"				return OPENCOMMENT;
"*/"				return CLOSECOMMENT;
"["				return OPENBIGBRACKET;
"]"				return CLOSEBIGBRACKET;
"for"				return FOR;
"while"				return WHILE;
"final"				return FINAL;
"package"			return PACKAGE;
"assert"			return ASSERT;
"new" 				return NEW;
" /"				return CALCULATION;

[//]				return SIMPLECOMMENT;
[\t\n]				return CHANGELINE;
[a-zA-Z][_a-zA-Z0-9]*		return IDENTIFIER;
[1-9][0-9]*			return INTEGER;
[1-9][0-9]*[.][1-9][0-9]*	return FLOATNUMBER;
["][^"]["]			return STRING;
['][^'][']			return CHAR;
[.]				return DOT;
[{]				return OPENMIDDLEBRACKET;
[}]				return CLOSEMIDDLEBRACKET;
[(]				return OPENBRACKET;
[)]				return CLOSEBRACKET;
[,] 				return COMMA;
[=]				return IS;
"+="				return IS;
"-="				return IS;
"*="				return IS;
"/="				return IS;
[+]				return CALCULATION;
[-]				return CALCULATION;
[*]				return CALCULATION;
[%]				return CALCULATION;
"!="				return BOOLRETURN;
"=="				return BOOLRETURN;
[<]				return BOOLRETURN;
"<="				return BOOLRETURN;
[>]				return BOOLRETURN;
">="				return BOOLRETURN;
"++"				return CALONCE;
"--"				return CALONCE;
[ ]				;
.					printf("unexpected character\n");

%%

int yywrap(void)
{
	return 1;
}
