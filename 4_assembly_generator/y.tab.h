/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IF = 258,
    ELSE = 259,
    FOR = 260,
    INT = 261,
    CHAR = 262,
    WHILE = 263,
    FLOAT = 264,
    VOID = 265,
    RETURN = 266,
    PRINTLN = 267,
    ID = 268,
    ADDOP = 269,
    MULOP = 270,
    INCOP = 271,
    DECOP = 272,
    RELOP = 273,
    NOT = 274,
    LPAREN = 275,
    RPAREN = 276,
    LCURL = 277,
    RCURL = 278,
    LTHIRD = 279,
    RTHIRD = 280,
    COMMA = 281,
    SEMICOLON = 282,
    ASSIGNOP = 283,
    CONST_CHAR = 284,
    CONST_INT = 285,
    CONST_FLOAT = 286,
    LOGICOP = 287,
    MAIN = 288,
    noelse = 289
  };
#endif
/* Tokens.  */
#define IF 258
#define ELSE 259
#define FOR 260
#define INT 261
#define CHAR 262
#define WHILE 263
#define FLOAT 264
#define VOID 265
#define RETURN 266
#define PRINTLN 267
#define ID 268
#define ADDOP 269
#define MULOP 270
#define INCOP 271
#define DECOP 272
#define RELOP 273
#define NOT 274
#define LPAREN 275
#define RPAREN 276
#define LCURL 277
#define RCURL 278
#define LTHIRD 279
#define RTHIRD 280
#define COMMA 281
#define SEMICOLON 282
#define ASSIGNOP 283
#define CONST_CHAR 284
#define CONST_INT 285
#define CONST_FLOAT 286
#define LOGICOP 287
#define MAIN 288
#define noelse 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
