//
// Created by ulynaxe on 29.10.22.
//

#include <stdio.h>

#ifndef TABREPLACE_MESSAGES_H
#define TABREPLACE_MESSAGES_H

//
// Created by ulynaxe on 29.10.22.
//

#define ESCSEQ "\033["

static void printHelp() {
    char* USAGE[] = {
            ESCSEQ"32;40mUSAGE: tabReplace [OPTION]\033[0m\n",
            ESCSEQ"33;40mReplaces the TAB in the FILE\033[0m\n",
            ESCSEQ"32;40mREQUIRED:\033[0m\n",
            "-f                       read from file\n",
            "-o                       output to file\n",
            ESCSEQ"32;40mOPTIONAL:\033[0m\n",
            "-t                       count of spaces\n",
            ESCSEQ"32;40mExamples:\033[0m\n",
            ESCSEQ"34;40mtabReplace -f obeme.txt -o output.txt\033[0m\n",
            ESCSEQ"34;40mtabReplace -f obeme.txt -o output.txt -t 4\033[0m\n",
            NULL
    };

    for (int i = 0; USAGE[i]; i++) {
        printf("%s", USAGE[i]);
    }
}

static void printOptionNeed() {
    printf(ESCSEQ"31;47mOption needs a value!\033[0m");
}

static void printUnknowOption() {
    printf(ESCSEQ"31;47mUnknown option!\033[0m");
}

static void printNullPointer() {
    printf(ESCSEQ"31;47mINPUT OR OUTPUT FILE IS NULL!\033[0m");
}

static void printLimits() {
    printf(ESCSEQ"31;47mTHIS PARAMETER REQUIRED INTEGER!!! NOT STRING!\033[0m");

}

static void printReadError() {
    printf(ESCSEQ"31;47mERROR ON READING FILE!!!\033[0m");
}

#endif //TABREPLACE_MESSAGES_H
