#include<stdio.h>
#include<ctype.h>

void count() {
    printf("Enter lines of text here: ...\n");
    int c, nc = 0, nt = 0, nl = 0, nbackslash = 0;
    while ((c = fgetc(stderr)) != EOF) {
        if (c == '\n') { ++nl;
        } else if (c == '\t') { ++nt;
        } else if (c == '\\') { nbackslash += 1;
        } else if (isspace(c)) { ++nc; }
        printf("lines: %d\n", nl);
        printf("tabs: %d\n", nt);
        printf("backslashes: %d\n", nbackslash);
        printf("alphanumeric: %d\n", nc);
    }
}

int main( int argc, const char* argv[]) {
    count();
    return 0;
} 

/*  Identify...
    (2) first character in a const char* s:
        char strchr(const char* s, char);
    
    (3) length of a prefix of const char* s that has characters in const char*t:
        size_t strspn(const char* s, const char* t);

    (4) Terminate a program immediately:
        exit(0);

    (5) Open the file "midterm.txt" in read mode:
        fopen("midterm.txt", "r");
*/

// strcpy
char* strcpy(const char* s, const char* t) {
    char* foo = s;
    while((*t++ = *s++) != '\0') { }
    return foo;
}

// strncat
char* strncat(char* s, const char* t, size_t n) {
  char* foo = s;

  while (*s != '\0') { s++; }
  while ( n-- != 0 ) { (*s++ = *t++) != '\0'}

  return foo;
}

// strcmp
int strcmp(const char* s, const char* t) {
    while (*s != '\0' && *t != '\0' && *s++ == *t++) { }
    
    return *s - *t;
}