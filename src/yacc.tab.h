/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define CREATE 258
#define DROP 259
#define USE 260
#define DESC 261
#define SHOW 262
#define INSERT 263
#define DATABASE 264
#define TABLE 265
#define INTO 266
#define VALUES 267
#define WHERE 268
#define SET 269
#define UPDATE 270
#define SELECT 271
#define DELETE 272
#define OP_FROM 273
#define OP_GROUP 274
#define OP_BY 275
#define OP_INT 276
#define VARCHAR 277
#define OP_SUM 278
#define OP_MAX 279
#define OP_MIN 280
#define OP_AVG 281
#define OP_CHECK 282
#define OP_IN 283
#define OP_LIKE 284
#define OP_NOT 285
#define OP_NULL 286
#define OP_PRIMARY 287
#define OP_KEY 288
#define OP_AND 289
#define OP_OR 290
#define OP_LE 291
#define OP_GE 292
#define OP_IS 293
#define OP_EQUAL 294
#define OP_NOT_EQUAL 295
#define NUMBER 296
#define STRING 297
#define IDENT 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

