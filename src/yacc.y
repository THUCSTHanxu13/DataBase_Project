%{
	#include "main.h"
	#include "Terminal.h"

	extern "C"			
	{					
		void yyerror(const char *s);
		extern int yylex(void);
	}

	DBManger terminal;

	std::string regexChange(std::string con) {
		std::string res = "";
		for (int i = 0; i < con.length(); i++)
			if (con[i] == '%') res = res + ".*"; else
			if (con[i] == '_') res = res + "."; else
			res = res + con[i];
		return res;
	}
	int hxtot=0;

%}

%token CREATE DROP USE DESC SHOW INSERT
%token DATABASE TABLE INTO VALUES WHERE SET
%token UPDATE SELECT DELETE OP_FROM OP_GROUP OP_BY
%token OP_INT VARCHAR OP_SUM OP_MAX OP_MIN OP_AVG OP_CHECK OP_IN OP_LIKE
%token OP_NOT OP_NULL OP_PRIMARY OP_KEY OP_AND OP_OR OP_LE OP_GE OP_IS OP_EQUAL OP_NOT_EQUAL
%token<intValue> NUMBER 
%token<strValue> STRING IDENT
%type<strValue> DatabaseIdent
%type<strValue> TableIdent
%type<strValue> StmtBlock
%type<dbIdent> DBIDENT
%type<expr> IdIsNULL;
%type<expr> Id2Id;
%type<expr> Id2Str;
%type<expr> Id2Num;
%type<expr> Expr;
%type<assign> Assign;
%type<assignLists> AssignList
%type<dbIdentLists> DBIDENTList
%type<TableEntityLists> TableEntityList
%type<ValueEntityLists> Value
%type<PriceEntityLists> Price
%type<tableEntity> TableEntity
%type<tableStmt> TableStmt;


%left OP_OR
%left OP_AND 
%nonassoc OP_EQUAL OP_NOT_EQUAL
%nonassoc OP_LE OP_GE '<' '>'
%left  '+' '-'
%left  '*' '/' '%'  
%nonassoc OP_NOT
%nonassoc ')'


%%

StmtBlock :
		StmtBlock Stmt {
	
		}
		|
		Stmt {
	
		};

Stmt:
	TableStmt ';' {
	
	}
	|
	DatabaseStmt ';' {
	
	}
	|
	InsertStmt ';' {

	}
	|
	UpdateStmt ';' {

	}
	|
	SelectStmt ';' {

	}
	|
	DeleteStmt ';' {

	}
	;

//***************Insert instruction***************
InsertStmt :
	INSERT INTO IDENT VALUES Value {
		hxtot=hxtot+1;
		if (hxtot == 52)
			int hx= 0;
		terminal.insertIntoValues($3, $5);
	}
	;


UpdateStmt : 
	UPDATE IDENT SET AssignList WHERE Expr {
		terminal.updateTable($2, $4, $6);
		$6->deleteExpr();
		delete $6;
	}
	;

SelectStmt :
	SELECT DBIDENTList OP_FROM DBIDENTList WHERE Expr {
		terminal.selectFromTable($2, $4, $6);	
		$6->deleteExpr();
		delete $6;
	}
	|
	SELECT '*' OP_FROM DBIDENTList WHERE Expr {
		terminal.selectAllFromTable($4, $6);
		$6->deleteExpr();
		delete $6;
	}
	|
	SELECT DBIDENTList OP_FROM DBIDENTList {
		Expr * con = new ConstExpr();
		terminal.selectFromTable($2, $4, con);	
		delete con;
	}
	|
	SELECT '*' OP_FROM DBIDENTList {
		Expr * con = new ConstExpr();
		terminal.selectAllFromTable($4, con);
		delete con;
	}
	|
	SELECT DBIDENTList OP_FROM DBIDENTList OP_GROUP OP_BY DBIDENTList {
		terminal.selectFromTable($2, $4, $7);
	}
	;

DeleteStmt :
	DELETE OP_FROM IDENT WHERE Expr {
		terminal.deleteTable($3, $5);
		$5->deleteExpr();
		delete $5;
	}
	;


//***************EXPR instruction***************

DBIDENTList : 
	DBIDENTList ',' DBIDENT
	{
		$$.push_back($3);
	}
	|
	DBIDENT
	{
		$$.clear();
		$$.push_back($1);
	}
	;

AssignList :
	AssignList ',' Assign {
		$$.push_back($3);
	}
	|
	Assign {
		$$.clear();
		$$.push_back($1);
	}
	;

Assign :
	DBIDENT '=' STRING {
		$$ = Assign($1, $3);	
	}
	|
	DBIDENT '=' NUMBER {
		$$ = Assign($1, $3);
	}
	|
	DBIDENT '=' OP_NULL {
		$$ = Assign($1);
	}
	|
	DBIDENT '=' Expr {
		$$ = Assign($1, $3);
	}
	;

Expr : 
	Id2Num {
		$$ = $1;
	}
	|
	Id2Str {
		$$ = $1;
	}
	|
	Id2Id {
		$$ = $1;
	}
	|
	IdIsNULL {
		$$ = $1;
	}
	|
	'(' Expr ')' {
		$$ = new Unary($2);
		$$ -> setType(TREE_OP_EQ);
	}
	|
	Expr OP_AND Expr {
		$$ = new Binary($1, $3);
		$$ -> setType(TREE_OP_AND);
	}
	|
	Expr OP_OR Expr {
		$$ = new Binary($1, $3);
		$$ -> setType(TREE_OP_OR);
	}
	|
	OP_NOT Expr {
		$$ = new Unary($2);
		$$ -> setType(TREE_OP_NOT);
	}
	|
	'-' Expr {
		$$ = new Unary($2);
		$$ -> setType(TREE_OP_NEG);
	}
	;

Id2Num :
	DBIDENT '+' NUMBER {
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_PLUS);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT '-' NUMBER {
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_MINUS);
		$$ -> setDBIdent($1);
	}
	|
	NUMBER '+' DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_PLUS);
		$$ -> setDBIdent($3);
	}
	|
	NUMBER '-' DBIDENT   {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_MINUS1);
		$$ -> setDBIdent($3);
	}
	|
	DBIDENT '>' NUMBER {
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_GT);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT '<' NUMBER {
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_LT);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT '=' NUMBER {
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_EQ);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT OP_GE NUMBER	{
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_GE);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT OP_LE NUMBER	{
		$$ = new Id2Num($3);
		$$ -> setType(TREE_OP_LE);
		$$ -> setDBIdent($1);
	}
	|
	NUMBER '>' DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_LT);
		$$ -> setDBIdent($3);
	}
	|
	NUMBER '<' DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_GT);
		$$ -> setDBIdent($3);
	}
	|
	NUMBER '=' DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_EQ);
		$$ -> setDBIdent($3);
	}
	|
	NUMBER OP_GE DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_LE);
		$$ -> setDBIdent($3);
	}
	|
	NUMBER OP_LE DBIDENT {
		$$ = new Id2Num($1);
		$$ -> setType(TREE_OP_GE);
		$$ -> setDBIdent($3);
	}
	;

Id2Str :
	DBIDENT '>' STRING {
		$$ = new Id2Str($3);
		$$ -> setType(TREE_OP_GT);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT '<' STRING {
		$$ = new Id2Str($3);
		$$ -> setType(TREE_OP_LT);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT '=' STRING {
		$$ = new Id2Str($3);
		$$ -> setType(TREE_OP_EQ);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT OP_GE STRING	{
		$$ = new Id2Str($3);
		$$ -> setType(TREE_OP_GE);
		$$ -> setDBIdent($1);
	}
	|
	DBIDENT OP_LE STRING	{
		$$ = new Id2Str($3);
		$$ -> setType(TREE_OP_LE);
		$$ -> setDBIdent($1);
	}
	|
	STRING '>' DBIDENT {
		$$ = new Id2Str($1);
		$$ -> setType(TREE_OP_LT);
		$$ -> setDBIdent($3);
	}
	|
	STRING '<' DBIDENT {
		$$ = new Id2Str($1);
		$$ -> setType(TREE_OP_GT);
		$$ -> setDBIdent($3);
	}
	|
	STRING '=' DBIDENT {
		$$ = new Id2Str($1);
		$$ -> setType(TREE_OP_EQ);
		$$ -> setDBIdent($3);
	}
	|
	STRING OP_GE DBIDENT {
		$$ = new Id2Str($1);
		$$ -> setType(TREE_OP_LE);
		$$ -> setDBIdent($3);
	}
	|
	STRING OP_LE DBIDENT {
		$$ = new Id2Str($1);
		$$ -> setType(TREE_OP_GE);
		$$ -> setDBIdent($3);
	}
	|
	DBIDENT OP_LIKE STRING {
		$$ = new Id2Str(regexChange($3));
		$$ -> setType(TREE_OP_EQ);
		$$ -> setDBIdent($1);
	}
	;

Id2Id : 
	DBIDENT '>' DBIDENT {
		$$ = new Id2Id();
		$$ -> setType(TREE_OP_GT);
		$$ -> setLefDBIdent($1);
		$$ -> setRigDBIdent($3);
	}
	|
	DBIDENT '<' DBIDENT {
		$$ = new Id2Id();
		$$ -> setType(TREE_OP_LT);
		$$ -> setLefDBIdent($1);
		$$ -> setRigDBIdent($3);
	}
	|
	DBIDENT '=' DBIDENT {
		$$ = new Id2Id();
		$$ -> setType(TREE_OP_EQ);
		$$ -> setLefDBIdent($1);
		$$ -> setRigDBIdent($3);
	}
	|
	DBIDENT OP_GE DBIDENT {
		$$ = new Id2Id();
		$$ -> setType(TREE_OP_GE);
		$$ -> setLefDBIdent($1);
		$$ -> setRigDBIdent($3);
	}
	|
	DBIDENT OP_LE DBIDENT {
		$$ = new Id2Id();
		$$ -> setType(TREE_OP_LE);
		$$ -> setLefDBIdent($1);
		$$ -> setRigDBIdent($3);
	}
	;

IdIsNULL : 
	DBIDENT OP_IS OP_NULL {
		$$ = new IdIsNULL();
		$$ -> setType(TREE_OP_IS);
		$$ -> setDBIdent($1);
	}
	;

DBIDENT :
	IDENT '.' IDENT {
		$$.work = -1;
		$$.table = $1;
		$$.ident = $3;
	}
	|
	IDENT {
		$$.work = -1;
		$$.table = "";
		$$.ident = $1;
	}
	|
	OP_SUM '(' DBIDENT ')' {
		$$ = $3;
		$$.work = 0;
	}
	|
	OP_AVG '(' DBIDENT ')' {
		$$ = $3;
		$$.work = 1;
	}
	|
	OP_MAX '(' DBIDENT ')' {
		$$ = $3;
		$$.work = 2;
	}
	|
	OP_MIN '(' DBIDENT ')' {
		$$ = $3;
		$$.work = 3;
	}			
	;

Price :
	NUMBER {
		$$.clear();
		$$.push_back(PriceEntity($1, 0));
	}
	|
	STRING {
		$$.clear();
		$$.push_back(PriceEntity($1, 0));
	}
	| 
	OP_NULL {
		$$.clear();
		$$.push_back(PriceEntity(0, 1));
	}
	|
	Price ',' OP_NULL {
		$$.push_back(PriceEntity(0, 1));	
	}
	|
	Price ',' NUMBER {
		$$.push_back(PriceEntity($3, 0));
	}
	|
	Price ',' STRING {
		$$.push_back(PriceEntity($3, 0));
	}
	;

Value :
	'(' Price ')'  {
		$$.clear();
		$$.push_back($2);
	}
	|
	Value ',' '(' Price ')' {
		$$.push_back($4);
	}

//***************Database instruction***************
DatabaseStmt :
	CREATE DatabaseIdent {
		terminal.createDatabase($2);
	}
	|
	DROP DatabaseIdent {
		terminal.dropDatabase($2);
	}
	|
	SHOW DatabaseIdent {
		terminal.showDatabase($2);
	}
	|
	USE IDENT {
		terminal.useDatabase($2);
	}
	;

DatabaseIdent :
	DATABASE IDENT {
		$$ = $2;
	}
	;

//***************Table instruction***************
TableStmt :
	CREATE TableIdent '(' TableEntityList ')' {
		terminal.createTable($2, $4);
	}
	|
	DROP TableIdent {
		terminal.dropTable($2);
	}
	|
	DESC TableIdent {
		terminal.showTable($2);
	}
	|
	SHOW TableIdent {
		terminal.showTable($2);
	}
	;

TableIdent :
	TABLE IDENT {
		$$ = $2;
	}
	;

TableEntity :
			IDENT OP_INT '(' NUMBER ')' {
				$$ = TableEntity($1, "int", $4, 0);
			}
			|
			IDENT VARCHAR '(' NUMBER ')' {
				$$ = TableEntity($1, "varchar", $4, 0);
			}
			|
			IDENT OP_INT '(' NUMBER ')' OP_NOT OP_NULL {
				$$ = TableEntity($1, "int", $4, 1);
			}
			|
			IDENT VARCHAR '(' NUMBER ')' OP_NOT OP_NULL {
				$$ = TableEntity($1, "varchar", $4, 1);
			}
			|
			OP_PRIMARY OP_KEY '(' IDENT ')' {
				$$ = TableEntity($4, "", 0, 0, 1);
			}
			|
			OP_CHECK '(' IDENT OP_IN '(' Price ')' ')' {
				$$ = TableEntity($3, $6);
			}
			;

TableEntityList : 
			TableEntityList ',' TableEntity {
				$$.push_back($3);
			}
			|
			TableEntity {
				$$.clear();
				$$.push_back($1);
			};

%%

void yyerror(const char *s)	{
	printf("err!\n");
}

int main()
{
		yyparse();
	return 0;
}
