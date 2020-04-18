#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
	for(int i = 1; i<argc; i = i+2) {
		long arg = strtol(argv[i+1], NULL, 10);		//use to convert argv[i] from char to long
		int n = arg;
		if(n>5) {
			printf("%s %s \n",argv[i],argv[i+1]);
		}
	}

	return 0;
}