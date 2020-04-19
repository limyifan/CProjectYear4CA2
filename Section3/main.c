#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	char* pathname;
	int count;
	int longest;
	int shortest;
	int total;
}Rpathlist;

int main(int argc, char* argv[]) {
	int size = 0;														//struct size
	Rpathlist *pathlist[argc / 2];
	for(int i = 1; i<argc; i = i+2) {

		long arg = strtol(argv[i+1], NULL, 10);							//use to convert argv[i] from char to long
		int proc = arg;

		Rpathlist *path = (Rpathlist*) malloc(sizeof(Rpathlist));		//define Object
		if(proc>=5) {
			if (size==0) {												//At start, the struct is empty so just need to insert the first data inside it
				path->pathname = argv[i];								//Object for struct
				path->count = 1;
				path->longest = proc;
				path->shortest = proc;
				path->total = 0;
				pathlist[size] = path;
				size++;													//ready for next
				
			} else if(size == 1) {										//At second, the arraylist size is 1 as unable for loop 
				
			    if(strcmp(pathlist[0]->pathname, argv[i])==0) {			//if path name same
					pathlist[0]->count = pathlist[0]->count + 1;
					
					if(proc > pathlist[0]->longest) {					//Compare the longest processing time
						pathlist[0]->longest = proc;
					} else if(proc < pathlist[0]->shortest) {			//Compare the shortest processing time
						pathlist[0]->shortest = proc;
					}
					pathlist[0]->total = pathlist[0]->total + proc;		//Total of processsing time
					
				} else {
				    path->pathname = argv[i];
    				path->count = 1;
    				path->longest = proc;
    				path->shortest = proc;
    				path->total = 0;
    				pathlist[1] = path;
    				size++;
				}
			} else {
				bool exist = false;										//check the pathname in the struct or not, prevent duplicate
				for (int j=0;j<size;j++) {
					
					if(strcmp(pathlist[j]->pathname, argv[i])==0) {
					    exist = true;
						pathlist[j]->count = pathlist[j]->count + 1;
						
						if(proc > pathlist[j]->longest) {
							pathlist[j]->longest = proc;
						} else if(proc < pathlist[j]->shortest) {
							pathlist[j]->shortest = proc;
						}
						pathlist[j]->total = pathlist[j]->total + proc;
					}
				}
				if (!exist) {
					path->pathname = argv[i];
					path->count = 1;
					path->longest = proc;
					path->shortest = proc;
					path->total = 0;
					pathlist[size] = path;
					size++;
				}
			}
			printf("%s %s \n",argv[i],argv[i+1]);
		}
	}
	
	// print the result
	for (int i = 0;i<size; i++) {
		double avg = (double)  pathlist[i]->total / pathlist[i]->count;					//calculate the average of processing time
		printf("Path: %s, Total requests: %d, Longest: %d, Shortest: %d, Average: %.5f\n", pathlist[i]->pathname, pathlist[i]->count, pathlist[i]->longest, pathlist[i]->shortest, avg);
	}
	return 0;
}