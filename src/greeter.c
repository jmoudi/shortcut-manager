#include "greeter.h"
#include <stdio.h>

int greet2(const char *name, int year, char *out) {
    int n;
    
    n = sprintf(out, "Greetings, %s from %d! We come in peace :)", name, year);

    return n;
}
int greet(struct Greetee *g, char *out) {
    int n;

    n = sprintf(out, "Greetings, %s from %d! We come in peace :)", g->name, g->year);

    return n;
}