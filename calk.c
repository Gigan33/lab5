#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

char operations() {
    clear_stacks(); // очистка стеков для чисел и операций
    char c, bufer[100]; // временные переменные
    int key = 0, i = 0;
    push_o('\n'); // ввод переменной, которая покажет конец обработки стека
    while ((c = getchar()) != '\n') {
        if ((c >= '0' && c <= '9') || c == '.') {
            bufer[i++] = c;
            key = 1;
        } else if (key) {
            bufer[i] = '\0';
            push(atof(bufer));
            key = 0;
            i = 0;
        } else if (c == EOF) {
            return EOF;
        } else if (c != ' ') {
            push_o(c);
        }
    }
    return '0';
}

int calk() {
    char o;
    double op2;
    while (operations() != EOF) {
        while ((o = pop_o()) != '\0')
            switch (o) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '^':
                    op2 = pop();
                    push(pow(pop(), op2));
                    break;
                case '/' :
                    op2 = pop();
                    if (op2 != 0.0)
                        push(pop() / op2);
                    else {
                        printf("error: zero divisor\n");
                        return -1;
                    }
                    break;
                case '%' :
                    op2 = pop();
                    if (op2 != 0.0)
                        push((int) (pop() / op2));
                    else {
                        printf("error: zero divisor\n");
                        return -1;
                    }
                    break;
                case 's':
                    push(sin(pop()));
                    break;
                case 'c':
                    push(cos(pop()));
                    break;
                case '\n' :
                    printf("\t%.8g\n", pop());
                    break;
                default:
                    printf("mistake\n", o);
                    return -1;
            }
    }
    return 0;
}
