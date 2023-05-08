#include <stdio.h>
#include "input.h"
#include "finder.h"
#include "calk.h"

int main() {
    char s1[100], s2[100];
    puts("Num 1\nwrite 2 lines");
    input(s1);
    input(s2);
    puts("First Number");
    printf("%d", finder(s1, s2));

    puts("\n\nNum 2");
    calk();
}