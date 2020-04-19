#include "task3.h"

int main() {
    char inputPath[100]="../colours.txt";
    char outputPath[100]="../rgba-colours.txt";
    ConvertAndOutputRGBA(inputPath,outputPath);
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
static void ConvertAndOutputRGBA(const char *inputPath,const char *outputPath)
{  FILE *fp = fopen(inputPath, "r");
    
    //Exceptions if no file is found within the path
    if (fp==NULL)
    {
        printf("File not found...\n");
    }
    char output[256];
    int size=0;
    for(int j=1;fgets(output,sizeof(output),fp)!=NULL;j++)
    {
        int charcount = CountChar(output)-1;
        bool isHex=checkHexValid(output,charcount);
        int r=0;
        int g=0;
        int b=0;
        double a=0;
        if(isHex==true)
        {
            //assign ff to the alpha color codes if it is a 6digit color codes
            if(charcount==6)
            {
                
                char *red=substr(output,1,3);
                char *green=substr(output,3,5);
                char *blue=substr(output,5,7);
                char *alpha="ff";
                RGBAList[j].r=convertDecimal(red);
                RGBAList[j].g=convertDecimal(green);
                RGBAList[j].b=convertDecimal(blue);
                RGBAList[j].a=ConvertAlpha(alpha)/255;
                
                
            }
            else
            {
                
                char *red=substr(output,1,3);
                char *green=substr(output,3,5);
                char *blue=substr(output,5,7);
                char *alpha=substr(output,7,9);
                r=convertDecimal(red);
                g=convertDecimal(green);
                b=convertDecimal(blue);
                a=ConvertAlpha(alpha)/255;
                RGBAList[j].r=convertDecimal(red);
                RGBAList[j].g=convertDecimal(green);
                RGBAList[j].b=convertDecimal(blue);
                RGBAList[j].a=ConvertAlpha(alpha)/255;
                
            }
            
        }
        size++;
    }
    fclose(fp);
    BubbleSort(1,size);
    fp = fopen (outputPath,"w");
    for(int i=1;i<size;i++)
    {
        //printf("RGBA(%d,%d,%d,%.1f)\n",RGBAList[i].r,RGBAList[i].g,RGBAList[i].b,RGBAList[i].a);
        fprintf (fp,"RGBA(%d,%d,%d,%.1f)\n",RGBAList[i].r,RGBAList[i].g,RGBAList[i].b,RGBAList[i].a);
    }
    fclose (fp);
}
//Bubble sort the list by alpha value from  lowest to highest
//ref: https://www.geeksforgeeks.org/bubble-sort/
static void BubbleSort(int i, double size) {
    for (int a = i; a <= size; ++a)
    {
        for (int b = a + 1; b <=size; ++b)
        {
            if (RGBAList[a].a > RGBAList[b].a)
            {
                struct RGBA temp=RGBAList[a];
                RGBAList[a]=RGBAList[b];
                RGBAList[b]=temp;
            }
        }
    }
}

//https://stackoverflow.com/questions/4265161/how-to-convert-hexadecimal-to-rgb
static int convertDecimal(const char *hex)
{
    int len = 2;
    int val = 0;
    len--;
    int decimal=0;
    
    /*
     * Iterate over each hex digit
     */
    for (int i = 0; i <2; i++)
    {
        
        /* To find the decimal representation of hex[i] */
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }
        
        decimal += val * pow(16, len);
        len--;
        
    }
    
    return decimal;
}

static double ConvertAlpha(const char *hex)
{
    int len = 2;
    int val = 0;
    len--;
    double decimal=0;
    
    /*
     * Iterate over each hex digit
     */
    for (int i = 0; i <2; i++)
    {
        
        /* To find the decimal representation of hex[i] */
        if(hex[i]>='0' && hex[i]<='9')
        {
            val = hex[i] - 48;
        }
        else if(hex[i]>='a' && hex[i]<='f')
        {
            val = hex[i] - 97 + 10;
        }
        else if(hex[i]>='A' && hex[i]<='F')
        {
            val = hex[i] - 65 + 10;
        }
        
        decimal += val * pow(16, len);
        len--;
        
    }
    
    return decimal;
}

//https://www.techiedelight.com/implement-substr-function-c/
char* substr(const char *src, int m, int n)
{
    // get length of the destination string
    int len = n - m;
    
    // allocate (len + 1) chars for destination (+1 for extra null character)
    char *dest = (char*)malloc(sizeof(char) * (len + 1));
    
    // extracts characters between m'th and n'th index from source string
    // and copy them into the destination string
    for (int i = m; i < n && (*(src + i) != '\0'); i++)
    {
        *dest = *(src + i);
        dest++;
    }
    
    // null-terminate the destination string
    *dest = '\0';
    
    // return the destination string
    return dest - len;
}

static bool checkHexValid(const char *str,int length)
{
    // printf("length:%d\n",length);
    bool isHex=false;
    if(length==6 || length==8)
    {
        str=substr(str,0,length);
        
        if (str[strspn(str, "#0123456789abcdefABCDEF")] == 0)
        {
            isHex=true;
        }
    }
    return isHex;
}



