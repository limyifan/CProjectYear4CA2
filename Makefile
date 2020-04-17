CC      = gcc
FLAGS   = -Wall -Wextra -Wpedantic
STRING 	=  'The quick brown fox jumps over the lazy dog\n'
HTML 	= 'https://www.dkit.ie'
ACS		= access.log

# Run the solution (FYI: we could make run dependent on link)
run:
	./build/main
	
build/main:
	gcc -c ${FLAGS} main.c -o build/main.o

# echo the STRING words then pass result (input) to word count function with the option of count the number of words
run-task-1:
	echo ${STRING} | wc -w

# echo the STRING words to determine then pass the result (input) to translate function with the option of convert text from lower case to upper case
run-task-2:
	echo ${STRING} | tr [:lower:] [:upper:]

# curl used for transmit data from or to server. In this case, the html link is transfer to file name dkit.html
run-task-3:
	curl ${HTML} > dkit.html

# get first line and last line from dkit.html then pass the result (input) to sort function with the option of -reverse
# After that, tr (translate function) translate the <> to [] then insert to mangled.txt file
run-task-4: dkit.html
	(head -n1 dkit.html & tail -n1 dkit.html) | sort -r | tr '<>' '[]'> mangled.txt

# tail is the function to shows last n line from input/file. Default is 10 lines.
task1:
	tail ${ACS}

# print the file as the input for next phase, , uniq is used to terminate the repeat data and print the result in terminal
task2: 
	cat ${ACS} | cut -d " " -f 1 | uniq
	
task3:
	cat ${ACS} | egrep ' 404 ' | cut -d " " -f 3-5


	
