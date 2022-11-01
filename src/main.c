#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>
#include <limits.h>

#include "util/messages.h"
#include "editor/editor.h"

int main(int argc, char* argv[]) {
    int opt;
    FILE* infile = stdin;
    FILE* outfile = stdout;

    int tab_spaces = 4;

    while((opt = getopt(argc, argv, ":f:o:t:h")) != -1) {
        switch(opt) {
            case 'f':
                infile = fopen(optarg, "rt");
                break;
            case 'o':
                outfile = fopen(optarg, "wt");
                break;
            case 't':
            {
                // Этот кусок нужен, чтобы обрабатывать ошибки.
                /*
                 * Функция strtol() возвращает результат преобразования, если значение не вызвало "переполнения" или не было крайне маленьким
                 *  Если происходит последнее, то strtol() возвращает LONG_MIN.
                 *  Если же произошло "переполнение", то strtol() возвращает LONG_MAX.
                 *  . В обоих случаях глобальной переменной errno присваивается значение ERANGE.
                 */
                long result = strtol(optarg, NULL, 10);
                if ((errno == ERANGE && (result == LONG_MAX || result == LONG_MIN))
                    || (errno != 0 && result == 0)) {
                    printLimits();
                    exit(EXIT_FAILURE);
                }
                tab_spaces = (int) result;
            }
             break;
            case 'h':
                printHelp();
                return EXIT_SUCCESS;
            case ':':
                printOptionNeed();
                return EXIT_FAILURE;
            case '?':
                printUnknowOption();
                return EXIT_FAILURE;
            default:
                break;
        }
    }

    if (!(infile || outfile)) {
        printNullPointer();
        return EXIT_FAILURE;
    }

    replaceWithPush(infile, outfile, tab_spaces);

    return EXIT_SUCCESS;
}