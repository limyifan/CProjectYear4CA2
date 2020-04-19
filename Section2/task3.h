
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
static int CountChar(char *string);
static bool checkHexValid(const char *str,int length);
static int convertDecimal(const char *hex);
char* substr(const char *src, int m, int n);
static void ConvertAndOutputRGBA(const char *link,const char *outputLink);
static double ConvertAlpha(const char *hex);
static void BubbleSort(int i, double size);

struct RGBA
{
    int r;
    int g;
    int b;
    double a;
};
struct RGBA RGBAList[10];
