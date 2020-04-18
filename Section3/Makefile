CC		= gcc
FLAGS	= -Wall -Wextra -Wpedantic
ACS		= ../access.log
CMD		= $$(cut -d " " -f 4,7 ../access.log)

# This target is the final compile and depends on other targets
link: build/main.o
	gcc $< -o main

build/main.o: main.c
	gcc -c $< -o main.o ${FLAGS}

# tail is the function to shows last n line from input/file. Default is 10 lines.
run-task-1:
	tail ${ACS}

# print the file as the input for next phase, , uniq is used to terminate the repeat data and print the result in terminal
run-task-2:
	cat ${ACS} | cut -d " " -f 1 | uniq

# search for 404 code with space at start and end which able to know as RESULT CODE
# cut the line with the delimeter of " " and remain the range 3 to 5 of the line as those range is REQEUST portion. The range is determined as the string before the delimeter.
# Example, deliemter of " " and String "Operating System is fun"
#		1		2		3		4
#	Operating System	is	   fun
run-task-3:
	cat ${ACS} | egrep ' 404 ' | cut -d " " -f 3-5

# MSIE and Trident/7.0 stands for Microsoft Internet Explorer, so just need to find those words in those line
# then > is insert, so > access.ie.log is means insert to a file called access.ie.log
# reference for IE explorer user agent: https://developers.whatismybrowser.com/useragents/explore/software_name/internet-explorer/3
# reference : https://alvinalexander.com/linux-unix/linux-egrep-multiple-regular-expressions-regex/
run-task-4:
	cat ${ACS} | (egrep 'MSIE|Trident/7.0') > access.ie.log

# In this case, the $() is to identify as priorty work however in Makefile it determined $( ... ) as empty.
# So we need to add $ at front of $(...), $$(...), for let it know that $() is there
# reference: https://unix.stackexchange.com/questions/512023/why-does-my-find-sed-command-work-in-the-terminal-but-not-in-a-makefile
run-task-5:
	./main1 $(CMD)



