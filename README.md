# CS F363 Compiler Construction

## Lexical Analysis
- To run the lexer, ensure you're in the **'Lexical Analysis'** directory
- Once in the directory, run the command `./lexer.sh` in the terminal
- At this stage, the file needs to be hard-coded into the ```lexer.l``` file (this will be fixed in later iterations of the code)

## Syntax Analysis
- To run the parser, ensure you're in the **'Syntax Analysis'** directory
- Once in the directory, run the command `./parser.sh <test_file.c>` in the terminal
- Here, the `test_file` can be any file with a `.c` extension. Some working sample test files are given in the same directory

## Semantic Analysis
- To run the parser, ensure you're in the **'Semantic Analysis'** directory
- Once in the directory, run the command `./parser.sh <test_file.c>` in the terminal
- Here, the `test_file` can be any file with a `.c` extension. Some working sample test files are given in the same directory
- If the `.c` file does not contain any errors, it will appropriately generate the Symbol Table for the given program and print it in an `output.txt` file<br>
**Note: If the `.c` file contains errors, the Symbol Table will not be generated**

## Quadruple (Three Address Code) Generation
- To run the parser, ensure you're in the **'TAC'** directory
- Once in the directory, run the command `./tac.sh <test_file.c>` in the terminal
- Here, the `test_file` can be any file with a `.c` extension. Some working sample test files are given in the same directory
- The program will appropriately generate the Three-Address code for the given input file and print it in an `output.txt` file<br>