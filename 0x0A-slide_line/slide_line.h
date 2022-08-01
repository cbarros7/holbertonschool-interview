#ifndef SLIDE_LINE_H
#define SLIDE_LINE_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* DEFINITIONS */
#define SLIDE_LEFT -5
#define SLIDE_RIGHT 5

/* FUNCTION PROTOTYPES */
int slide_line(int *line, size_t size, int direction);
void slide(int *line, int index, int placeholder);

#endif
