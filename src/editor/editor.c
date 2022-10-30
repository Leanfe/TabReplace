//
// Created by ulynaxe on 29.10.22.
//

#include <string.h>
#include <stdlib.h>
#include "editor.h"
#include "../reader/reader.h"

char* deTab(const char* input_string, const int tab_replaces) {
    int len = strlen(input_string);
    char* output_string = (char*) malloc((tab_replaces*len+1)*sizeof(char));

    int j = 0;
    for (int i = 0; i < len; i++) {
        if (input_string[i] == '\t') {
            //Заполняем массив нужными символами.
            /*
             * PARAM 1 – указатель на заполняемый массив.
             * PARAM 2 – код символа для заполнения.
             * PARAM 3 – размер заполняемой части массива в байтах.
             */
            memset(output_string+j, ' ', tab_replaces*sizeof(char));
            j += tab_replaces;
        } else {
            output_string[j] = input_string[i];
            j++;
        }
    }
    output_string[j] = '\0';

    return output_string;
}

char** replaceTabs(FILE* input, int tab_replaces) {
    char** arr = readFile(input);
    for (int i = 0; arr[i]; i++) {
        arr[i] = deTab(arr[i], tab_replaces);
    }
    return arr;
}

void replaceWithPush(FILE* in, FILE* output, int tab_replaces) {
    /* BUFSIZ - Default buffer size. (stdio.h) */
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, in)) {
        fputs(deTab(buffer, tab_replaces), output);
    }
}