#include "task1.h"

int main() {
    char inputPath[100]="../colours.txt";
    FilterHexColors(inputPath);
    return 0;
}

static void FilterHexColors(char *path) {
    FILE *fp = fopen(path, "r");
    
    //Exceptions if no file is found within the path
    if (fp==NULL)
    {
        printf("File not found...\n");
    }
    char output[256];
    printf("****Valid Colours List****\n");
    for(int i=1;fgets(output,sizeof(output),fp)!=NULL;i++)
    {
        int charcount = CountChar(output)-1;
        bool isHex=checkHexValid(output,charcount);
        
        if(isHex==true)
        {
            //add ff to the end of the color codes if it is a 6digit color codes
            if(charcount==6)
            {
                char *ro=substr(output,0,7);
                printf("%s\n",strncat( strncat( ro,"ff", 1),"ff", 1));
            }
            else
            {
                char *ro=substr(output,0,9);
                printf("%s\n",strncat(ro,"", 1));
            }
            
        }
        
    }
    fclose(fp);
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


