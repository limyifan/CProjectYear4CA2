
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
static int CountChar(char *string);
static bool checkHexValid(const char *str,int length);
static int convertDecimal(const char *hex);
char* substr(const char *src, int m, int n);
static void ExtractGreenValues(char *link);
