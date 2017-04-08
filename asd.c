#include <stdio.h>
#include "myscanner.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

void variableCheck(){
	int tok = yylex();
	if(tok == IDENTIFIER){
		int tok2 = yylex();
		if(tok2 == SEMICOLON)
			printf("Correct\n");
		else if(tok2 == OPENBIGBRACKET){
			if(yylex() == INTEGER && yylex() == CLOSEBIGBRACKET && yylex() == SEMICOLON){
				printf("Correct\n");				
			}
			else{
				printf("Invalid\n");
			}
		}
		else if(tok2 == OPENBRACKET){
			while(1){
				int tok3 = yylex();
				if(tok3 == VARIABLE){
					int tok4 = yylex();
					if(tok4 == IDENTIFIER){
						int tok5 = yylex();
						if(tok5 == COMMA){
							continue;
						}
						else if(tok5 == CLOSEBRACKET){
							printf("Correct\n");
							break;
						}
						else{
							printf("Invalid\n");
							break;	
						}					
					}
				}
				else if(tok3 == CLOSEBRACKET){
					printf("Correct\n");
					break;
				}
				else{
					printf("Invalid\n");
				}
			}
		}
		else
			printf("Invalid\n");
	}
}

void checkToken(int t){
	int token, token2;
	token = t;
	while(token) {
		printf("%d\n", token);
		switch (token) {
		// public, private, default, protected
		case ACCESSMOD:
			token2 = yylex();
			printf("%d\n", token2);
			if(token2 != VARIABLE && token2 != CLASS){
				printf("Invalid\n");
			}
			else if(token2 == VARIABLE){
				variableCheck();
			}
			else{
				printf("Invalid\n");
			}
			break;
		// '//'
		case SIMPLECOMMENT:
			printf("Simple Comment\n");
			while(yylex() != CHANGELINE);
			printf("Commented!\n");
			break;
		// '/*'
		case OPENCOMMENT:
			printf("Opened Comment\n");
			while(yylex() != CLOSECOMMENT);
			printf("Closed!\n");
			break;
		// '*/'
		case VARIABLE:
			variableCheck();
			break;
		// import
		case IMPORT:{
			int tokA = yylex();
			while(tokA){
				if(tokA == SEMICOLON)
					break;
				tokA = yylex();		
			}
			break;
		}
		// {
		case OPENMIDDLEBRACKET:
			printf("Open M bracket\n");	
			int tok = yylex();
			while(tok){
				if(tok == CLOSEMIDDLEBRACKET)
					break;
				checkToken(tok);
			}
			printf("Close M bracket\n");
			break;
		// \n
		case CHANGELINE:
			break;
		default:
			printf("Syntax error in line %d\n",yylineno);
		}
		token = yylex();
	}
}

int main(void) 
{

	int token, token2;

	token = yylex();
	checkToken(token);
	return 0;
}
