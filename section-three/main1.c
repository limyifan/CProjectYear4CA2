#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	int size = 0;
	for(int i = 1; i<argc; i = i+2) {
	
	printf("%s %s\n",argv[i],argv[i+1]);
	}
	
	return 0;
}