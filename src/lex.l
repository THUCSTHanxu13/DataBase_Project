%{
	#include "main.h"
	#include "yacc.tab.h"

	extern "C" {
		int yywrap(void);
		int yylex(void);
	}

	std::string substrwork(char * con) {
		std::string res = "";
		for (int i = 1; i < strlen(con) -1; i++)
		res = res + con[i];
		return res;
	}
%}


%%

GROUP|group {
	return OP_GROUP;
}

BY|by {
	return OP_BY;
}


CHECK {
	return OP_CHECK;
}

check {
	return OP_CHECK;
}

IN {
	return OP_IN;
}

in {
	return OP_IN;
}

SUM|sum {
	return OP_SUM;
}

LIKE|like {
	return OP_LIKE;
}

AVG|avg {
	return OP_AVG;
}

MAX|max {
	return OP_MAX;
}

MIN|min {
	return OP_MIN;
}

AND|and {
	return OP_AND;
}

OR|or {
	return OP_OR;
}

NOT|not {
	return OP_NOT;
}

INSERT|insert {
	return INSERT;
}

INTO|into {
	return INTO;
}

DELETE|delete {
	return DELETE;
}

SELECT|select {
	return SELECT;
}

UPDATE|update {
	return UPDATE;
}

SET|set {
	return SET;
}

WHERE|where {
	return WHERE;
}

FROM|from {
	return OP_FROM;
}

VALUES|values {
	return VALUES;
}

CREATE|create {
	return CREATE;
}

DROP|drop {
	return DROP;
}

USE|use {
	return USE;
}

DESC|desc {
	return DESC;
}

SHOW|show {
	return SHOW;
}

DATABASE|database {
	return DATABASE;
}

TABLE|table {
	return TABLE;
}

[>][=] {
	return OP_GE;
}

[<][=] {
	return OP_LE;
}

[<][>] {
	return OP_NOT_EQUAL;
}

[=][=] {
	return OP_EQUAL;
}

NULL {
	return OP_NULL;
}

null {
	return OP_NULL;
}

is|IS {
	return OP_IS;
}

PRIMARY {
	return OP_PRIMARY;
}

KEY {
	return OP_KEY;
}

int {
	return OP_INT;
}

varchar {
	return VARCHAR;
}

[0-9]+ {
	yylval.intValue = atoi(yytext);
	return NUMBER;
}

[a-zA-Z_][a-z0-9A-Z_]+ {
	yylval.strValue = yytext;
	return IDENT;
}

[(),;*.><=] {
	return (int)yytext[0];
}

\+ {
	return (int)yytext[0];
}

\- {
	return (int)yytext[0];
}

\"(\\.|[^"\\])*\" {
	yylval.strValue = substrwork(yytext); 
	return STRING;
}

'(\\.|[^'\\])*' {
	yylval.strValue = substrwork(yytext);
	return STRING;
}

[ ] {

};

[\t\n\r\s]+ {

};

%%


int yywrap(void)
{
	return 1;
}
