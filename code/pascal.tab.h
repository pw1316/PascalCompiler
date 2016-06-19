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

#ifndef YY_YY_PASCAL_TAB_H_INCLUDED
# define YY_YY_PASCAL_TAB_H_INCLUDED
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
    NOT = 258,
    MUL = 259,
    DIV = 260,
    IDIV = 261,
    MOD = 262,
    AND = 263,
    PLUS = 264,
    MINUS = 265,
    OR = 266,
    DOT = 267,
    COLON = 268,
    COMMA = 269,
    SEMI = 270,
    ASSIGN = 271,
    EQUAL = 272,
    UNEQUAL = 273,
    GE = 274,
    GT = 275,
    LE = 276,
    LT = 277,
    LP = 278,
    RP = 279,
    LB = 280,
    RB = 281,
    TRUE = 282,
    FALSE = 283,
    MAXINT = 284,
    SYST_BOOLEAN = 285,
    SYST_CHAR = 286,
    SYST_INTEGER = 287,
    SYST_REAL = 288,
    SYST_STRING = 289,
    SYSP_WRITELN = 290,
    SYSP_WRITE = 291,
    SYSP_READLN = 292,
    SYSP_READ = 293,
    PROGRAM = 294,
    TYPE = 295,
    VAR = 296,
    CONST = 297,
    ARRAY = 298,
    RECORD = 299,
    FUNCTION = 300,
    PROCEDURE = 301,
    OF = 302,
    PBEGIN = 303,
    END = 304,
    IF = 305,
    THEN = 306,
    ELSE = 307,
    REPEAT = 308,
    UNTIL = 309,
    WHILE = 310,
    DO = 311,
    FOR = 312,
    TO = 313,
    DOWNTO = 314,
    CASE = 315,
    GOTO = 316,
    ID = 317,
    INTEGER = 318,
    REAL = 319,
    CHAR = 320,
    STRING = 321,
    IFX = 322
  };
#endif
/* Tokens.  */
#define NOT 258
#define MUL 259
#define DIV 260
#define IDIV 261
#define MOD 262
#define AND 263
#define PLUS 264
#define MINUS 265
#define OR 266
#define DOT 267
#define COLON 268
#define COMMA 269
#define SEMI 270
#define ASSIGN 271
#define EQUAL 272
#define UNEQUAL 273
#define GE 274
#define GT 275
#define LE 276
#define LT 277
#define LP 278
#define RP 279
#define LB 280
#define RB 281
#define TRUE 282
#define FALSE 283
#define MAXINT 284
#define SYST_BOOLEAN 285
#define SYST_CHAR 286
#define SYST_INTEGER 287
#define SYST_REAL 288
#define SYST_STRING 289
#define SYSP_WRITELN 290
#define SYSP_WRITE 291
#define SYSP_READLN 292
#define SYSP_READ 293
#define PROGRAM 294
#define TYPE 295
#define VAR 296
#define CONST 297
#define ARRAY 298
#define RECORD 299
#define FUNCTION 300
#define PROCEDURE 301
#define OF 302
#define PBEGIN 303
#define END 304
#define IF 305
#define THEN 306
#define ELSE 307
#define REPEAT 308
#define UNTIL 309
#define WHILE 310
#define DO 311
#define FOR 312
#define TO 313
#define DOWNTO 314
#define CASE 315
#define GOTO 316
#define ID 317
#define INTEGER 318
#define REAL 319
#define CHAR 320
#define STRING 321
#define IFX 322

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PASCAL_TAB_H_INCLUDED  */
