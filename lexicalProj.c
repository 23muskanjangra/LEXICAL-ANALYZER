#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// List of C keywords
const char *keywords[] = {
    "auto", "break", "case", "char", "const", "continue", "default", "do",
    "double", "else", "enum", "extern", "float", "for", "goto", "if", "int",
    "long", "register", "return", "short", "signed", "sizeof", "static",
    "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
};
int num_keywords = 32;

// Function to check if a string is a keyword
int isKeyword(const char *str) {
    for (int i = 0; i < num_keywords; i++) {
        if (strcmp(str, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to check if a character is an operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' ||
            ch == '=' || ch == '<' || ch == '>' || ch == '!');
}

// Main lexical analyzer function
int main() {
    char ch, buffer[MAX];
    int i = 0;
    FILE *fp = fopen("input.c", "r");

    if (!fp) {
        printf(" Error: Cannot open input.c file!\n");
        return 1;
    }

    printf(" Lexical Analysis Output:\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        // Skip whitespace and newlines
        if (isspace(ch))
            continue;

        // Handle identifiers and keywords
        if (isalpha(ch) || ch == '_') {
            buffer[i++] = ch;
            while (isalnum(ch = fgetc(fp)) || ch == '_') {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            if (isKeyword(buffer))
                printf("<KEYWORD, %s>\n", buffer);
            else
                printf("<IDENTIFIER, %s>\n", buffer);
            ungetc(ch, fp); // Put back last read character
        }

        // Handle numbers
        else if (isdigit(ch)) {
            buffer[i++] = ch;
            while (isdigit(ch = fgetc(fp))) {
                buffer[i++] = ch;
            }
            buffer[i] = '\0';
            i = 0;
            printf("<NUMBER, %s>\n", buffer);
            ungetc(ch, fp);
        }

        // Handle comments
        else if (ch == '/') {
            char next = fgetc(fp);
            if (next == '/') {
                while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            } else if (next == '*') {
                while ((ch = fgetc(fp)) != EOF) {
                    if (ch == '*' && (ch = fgetc(fp)) == '/')
                        break;
                }
            } else {
                printf("<OPERATOR, />\n");
                ungetc(next, fp);
            }
        }

        // Handle operators
        else if (isOperator(ch)) {
            char next = fgetc(fp);
            if ((ch == '=' && next == '=') || 
                (ch == '!' && next == '=') || 
                (ch == '<' && next == '=') || 
                (ch == '>' && next == '=')) {
                printf("<OPERATOR, %c%c>\n", ch, next);
            } else {
                printf("<OPERATOR, %c>\n", ch);
                ungetc(next, fp);
            }
        }

        // Handle symbols and punctuation
        else if (ch == ';' || ch == ',' || ch == '(' || ch == ')' ||
                 ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            printf("<SYMBOL, %c>\n", ch);
        }

        // Handle string literals
        else if (ch == '"') {
            buffer[i++] = ch;
            while ((ch = fgetc(fp)) != '"' && ch != EOF) {
                buffer[i++] = ch;
            }
            buffer[i++] = '"';
            buffer[i] = '\0';
            i = 0;
            printf("<STRING, %s>\n", buffer);
        }

        // Ignore unrecognized characters
        else {
            // skip anything not matching
        }
    }

    fclose(fp);
    return 0;
}