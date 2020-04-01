//
//  main.c
//  Year4CA2
//
//  Created by Yifan Lim on 01/04/2020.
//  Copyright © 2020 Yifan Lim. All rights reserved.
//
#pragma clang diagnostic ignored "-Wstrict-prototypes"
#include <stdio.h>
static int CountChar(char *string);
static void Section1();
static void Section2();
static void Section3();


int main(int argc, const char * argv[]) {
    Section1();
    Section2();
    Section3();
    return 0;
}

static int CountChar(char *string) {
    const char * z = string;
    int m;
    int charcount;
    
    charcount = -1;
    for(m=0; z[m]; m++) {
        if(z[m] != ' ') {
            charcount ++;
        }
    }
    return charcount;
}
static void Section1() {
    
}
static void Section2() {
    FILE *fp = fopen("/Users/charles/Documents/c/Year4CA2/Year4CA2/colours.txt", "r");
    if (fp==NULL)
    {
        printf("File not found...\n");
    }
    char output[256];
    
    for(int i=1;fgets(output,sizeof(output),fp)!=NULL;i++)
    {
        int charcount = CountChar(output)-1;
        printf("%02d: %s",charcount,output);
    }
    fclose(fp);
}
static void Section3() {
    
}
