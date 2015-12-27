/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_YACC_TAB_H_INCLUDED
# define YY_YY_YACC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CREATE = 258,
    DROP = 259,
    USE = 260,
    DESC = 261,
    SHOW = 262,
    INSERT = 263,
    DATABASE = 264,
    TABLE = 265,
    INTO = 266,
    VALUES = 267,
    WHERE = 268,
    SET = 269,
    UPDATE = 270,
    SELECT = 271,
    DELETE = 272,
    OP_FROM = 273,
    OP_GROUP = 274,
    OP_BY = 275,
    OP_INT = 276,
    VARCHAR = 277,
    OP_SUM = 278,
    OP_MAX = 279,
    OP_MIN = 280,
    OP_AVG = 281,
    OP_CHECK = 282,
    OP_IN = 283,
    OP_LIKE = 284,
    OP_NOT = 285,
    OP_NULL = 286,
    OP_PRIMARY = 287,
    OP_KEY = 288,
    OP_AND = 289,
    OP_OR = 290,
    OP_LE = 291,
    OP_GE = 292,
    OP_IS = 293,
    OP_EQUAL = 294,
    OP_NOT_EQUAL = 295,
    NUMBER = 296,
    STRING = 297,
    IDENT = 298
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_YACC_TAB_H_INCLUDED  */
