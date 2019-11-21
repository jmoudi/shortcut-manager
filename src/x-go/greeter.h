#ifndef _GREETER_H
#define _GREETER_H

struct Greetee {
    const char *name;
    int year;
};


int greet2(const char *name, int year, char *out);

int greet(struct Greetee *g, char *out);

#endif