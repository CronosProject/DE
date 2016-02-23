#ifndef H_STRING_H
#define H_STRING_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Fix me; Need errorhandler */

// Formatting Function definitions
extern int replace_if_match_string(const char* source, char **dest, const char *pattern);
extern int replace_if_match_int(const char* source, int *dest, const char *pattern);

#endif