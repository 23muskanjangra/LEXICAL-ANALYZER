# Lexical Analyzer in C

A simple Lexical Analyzer (Tokenizer) written in C language that reads a C source file (input.c) and identifies different tokens such as:

Keywords

Identifiers

Numbers

Operators

Symbols

String Literals

Comments (Single-line & Multi-line)

📌 Project Overview

This project simulates the first phase of a compiler (Lexical Analysis).
It scans the input C program character by character and categorizes tokens into meaningful groups.

The output is displayed in the format:

<TOKEN_TYPE, VALUE>


Example:

<KEYWORD, int>
<IDENTIFIER, main>
<SYMBOL, (>
<SYMBOL, )>
<SYMBOL, {>
<NUMBER, 10>
<OPERATOR, =>

🚀 Features

✔️ Detects C Keywords (32 standard keywords)
✔️ Identifies Identifiers
✔️ Recognizes Numbers (Integers)
✔️ Handles Operators (+ - * / = == != <= >= < > !)
✔️ Detects Symbols (; , ( ) { } [ ])
✔️ Skips Single-line comments (//)
✔️ Skips Multi-line comments (/ /)
✔️ Handles String Literals
✔️ Ignores whitespace

🛠️ Technologies Used

C Programming Language

Standard Libraries:

stdio.h

ctype.h

string.h

📂 Project Structure
Lexical-Analyzer-C/
│
├── lexical_analyzer.c   # Main source code
├── input.c              # Input C file to analyze
└── README.md            # Documentation
