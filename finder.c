//
// Created by dzhik on 06.05.2023.
//

#include "finder.h"

int finder(char a[], char b[]) {
    int i, j;
    for (i = 0; a[i] != '\0'; i++) {
        for (j = 0; b[j] != '\0'; j++) {
            if (a[i] == b[j])
                return i;
        }
    }
    return -1;
}