/**
  * Lars Haavaldsen
  * COMP 362L
  * Spring 2023
 **/

#include <stdio.h>
#include <string.h>

// use freopen, getc, putc, strlen, exit, fclose, strchr

int main(int argc, char **argv) {
    if(argc <= 1) {
        printf("Not enough arguments provided\n");
        return 1;
    }
    char *input = NULL;
    char *output = NULL;

    char *fromChar = NULL;
    char *toChar = NULL;

    for(int i = 1; i < argc; i++) {
        char c = argv[i][0];
        switch (c) {
            case '-':z
                switch (argv[i][1]) {
                    case 'h': 
                        printf("Help Menu\n"); return 0; break;
                    case '-': 
                        fromChar = argv[i] + 2; 
                        break;
                    case '+': 
                        toChar = argv[i] + 2;
                        break;
                    case 'i': 
                        input = argv[i + 1];
                        break;
                    case 'o':
                        output = argv[i + 1]; 
                        break;
                    default: printf("Unrecognized argument number %i\n", i); 
                        return 1;
                }
            
            default: break; // ignore filenames
        }  
    }
    
    // make sure characters are specified
    if( (toChar == NULL) || (fromChar == NULL)) {
        printf("sub: ERROR - no characters to change provided\n");
        return 1;
    }

    //  setup replacement chars
    if (strlen(toChar) < strlen(fromChar)) {
        printf("sub: ERROR - missing replacement character\n");
        return 1;
    }
    if (strlen(fromChar) < strlen(toChar)) {
        printf("sub: WARNING - extraneous replacement character\n");
    }

    // files or stdin/stdout
    if (input) {
        freopen(input, "r", stdin);
    }
    
    if(output) {
        freopen(output, "w+", stdout);
    }

    char ch;
    char *str;

    while((ch=getc(stdin)) != EOF) {
        str = strchr(fromChar, ch);
        if(str){
            int charLoc = (int) (str - fromChar);
            putc(toChar[charLoc], stdout);
        } else {
            putc(ch, stdout);
        }
            
    }

    fclose(stdin);
    fclose(stdout);
}