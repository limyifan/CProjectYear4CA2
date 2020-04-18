//
//  main.h
//  Year4CA2
//
//  Created by Yifan Lim on 02/04/2020.
//  Copyright © 2020 Yifan Lim. All rights reserved.
//

#ifndef main_h
#define main_h

#pragma clang diagnostic ignored "-Wstrict-prototypes"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
static int CountChar(char *string);
static void Section1();
static void Section2();
static void Section3();
static bool checkHexValid(const char *str,int length);
static int convertDecimal(const char *hex);
char* substr(const char *src, int m, int n);
static void ConvertAndOutputRGBA(const char *link,const char *outputLink);
static void FilterHexColors(char *link) ;
static double ConvertAlpha(const char *hex);
static void BubbleSort(int i, double size);
static void ExtractGreenValues(char *link);
struct RGBA
{
    int r;
  int g;
    int b;
    double a;
};
struct RGBA RGBAList[10];
#endif /* main_h */
