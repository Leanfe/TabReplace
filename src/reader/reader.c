//
// Created by ulynaxe on 29.10.22.
//

#include "reader.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../util/messages.h"

char** readFile(FILE* in) {

    char** arr = NULL;
    size_t arr_size = 0;
    char buffer[BUFSIZ];
    char *temp_str = NULL;
    size_t temp_len = 0;
    while (fgets(buffer, BUFSIZ, in)) {
        size_t len = strlen(buffer);
        if (len) {
            if (buffer[len-1] == '\n') {
                // Последняя порция строки
                buffer[--len] = '\0';
                temp_str = realloc(temp_str, temp_len + len + 1);
                strcpy(temp_str + temp_len, buffer);
                arr_size++;
                arr = realloc(arr, sizeof(char*) * (arr_size + 1));
                arr[arr_size-1] = temp_str;
                temp_str = NULL;
                temp_len = 0;
            } else {
                // Очередная не последняя порция строки
                temp_str = realloc(temp_str, temp_len + len + 1);
                strcpy(temp_str + temp_len, buffer);
                temp_len += len;
            }
        } else {
            printReadError();
        }
    }
    if (temp_len) {
        arr_size++;
        arr = realloc(arr, sizeof(char*) * (arr_size + 1));
        arr[arr_size-1] = temp_str;
    }
    if (!arr_size) {
        arr = malloc(sizeof(char*) * (arr_size + 1));
    }
    arr[arr_size] = NULL;
    return arr;
}