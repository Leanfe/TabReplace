//
// Created by ulynaxe on 29.10.22.
//

#include <stdio.h>

#ifndef TABREPLACE_EDITOR_H
#define TABREPLACE_EDITOR_H

char** replaceTabs(FILE* input, int tab_replaces);
void replaceWithPush(FILE* input, FILE* output, int tab_replaces);

#endif //TABREPLACE_EDITOR_H
