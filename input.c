//
// Created by dzhik on 06.05.2023.
//

#include "input.h"

void input(char a[]) {
    int c, i = 0;
    while((c = getchar()) != '\n') {
        a[i++] = c;
    }
    a[i] = '\0';
}