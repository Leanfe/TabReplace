//
// Created by ulynaxe on 29.10.22.
//

#include <string.h>
#include <stdlib.h>
#include "editor.h"

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
            int resultTabs = tab_replaces-(i%tab_replaces);
            for (int k = 0; k < resultTabs; k++) {
                output_string[j] = ' ';
                j++;
            }
        } else {
            output_string[j] = input_string[i];
            j++;
        }
    }
    output_string[j] = '\0';

    return output_string;
}

void replaceWithPush(FILE* in, FILE* output, int tab_replaces) {
    /* BUFSIZ - Default buffer size. (stdio.h) */
    char buffer[BUFSIZ];
    while (fgets(buffer, BUFSIZ, in)) {
        fputs(deTab(buffer, tab_replaces), output);
    }

}