# Compiler Construction Project

This project is an endeavor into the construction of a basic compiler for C programs. It encompasses the creation of a symbol table, lexical analysis, syntax and semantic analysis, and code optimization to generate assembly code. The project is structured into several key components, each responsible for different stages of the compilation process.

## Project Structure

- **1_Symbol Table**: A foundational data structure that stores information about various entities such as identifiers, objects, and function names encountered throughout the source code. It is implemented as a list of hash tables to manage symbols in different scopes efficiently.

- **2_Lexical Analyzer (Lexer)**: Implemented using Flex, this component tokenizes a C source file, outputting the tokens to `token.txt` and logs to `log.txt`. A shell script, `script.sh`, is provided to run the lexer.

- **3_Syntax and Semantic Analyzer (Parser)**: Developed with Bison, this parser uses a yacc file to parse C grammar. It is capable of identifying syntax and semantic errors, logging them to `error.txt`, and printing tokens and identifiers to `log.txt`. A shell script `script.sh` script facilitates running this component.

- **4_Code Optimization and Assembly Code Generation**: Modifications to the `parser.y` file enable the parser to optimize the source code and generate equivalent assembly code. It updates the symbol table with variables and types and reports any errors in `error.txt`. Successful parsing results in assembly code output for each line of the input C file.

- **Directed Acyclic Graph (DAG) and Three Address Code (TAC) for Simple Expressions**: This component of the project focuses on optimizing expressions and intermediate code generation. It constructs Directed Acyclic Graphs (DAG) to eliminate common subexpressions and efficiently represent the relationships between variables and operations. Furthermore, it generates Three Address Code (TAC) as an intermediate representation that simplifies code optimization and translation to machine code.

## Getting Started

### Prerequisites

- Flex
- Bison
- GCC

### Running each part of the Compiler

1. **Testing up the Symbol Table**: Go to `1_SymbolTable`Copy the input.txt file and pass this as std input to an executable file of SymbolTable.cpp
   To tokenize a C file and generate logs, run:
   ```bash
   gcc -o SymbolTable SymbolTable.cpp
   ./SymbolTable <content_from_input.txt>
   ```
2. **Lexer**: Go to `2_lexer`
   To tokenize a C file and generate logs, run:
   ```bash
   ./script.sh
   ```
3. **Parser**: Go to `3_parser/FUll`
   To parse a C file and generate logs, run:
   ```bash
   ./script.sh
   ```
4. **Code Generator**: Go to `4_assembly_generator`
   To parse a C file and generate assembly code, run:
   ```bash
   ./script.sh
   ```
5. **DAG\_&_TAC**: Go to `DAG & TAC`
   To parse an input expression file and generate equivalent DAG & TAC, run:
   ```bash
   ./script.sh
   ```
