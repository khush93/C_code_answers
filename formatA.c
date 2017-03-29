/* take a file input(fileName) and a number input(x). 
	restructure content to fixed number (x) of chars per line and write to fileName.out
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int const numchars = atoi(argv[1]);

    char const *fileName = argv[2];
    char fileName2[255];
    strcat(fileName2,fileName);
    strcat(fileName2,".out");

	if(argc != 3){
		printf("Invalid number of arguments");
		exit(0);
	}
	else{
		if(numchars < 25 || numchars > 100){
			printf("Invalid number in first argument. Enter number between 25 and 100");
			exit(0);
		}
	}
	FILE* file = fopen(fileName, "rt");
	FILE* file2 = fopen(fileName2,"w+");
	char word[1024];
	char *outLine = malloc(numchars*sizeof(char*));

	if(file == NULL){
		perror("File cannot be opened");
		exit(0);
	}
	else{
		while(fscanf(file, "%1023s", word) == 1){
			
			if(strlen(outLine) + strlen(word) <= numchars){

				strcat(outLine, word);
				strcat(outLine, " ");
			}
			else{
				
				fprintf(file2,"%s\n",outLine);
				outLine[0] ='\0';
				strcat(outLine, word);
				
			}
		}
	}
	fclose(file);
	return 0;
}

