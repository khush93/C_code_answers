/* take a file input(fileName) and a number input(x). 
	restructure content to fixed number (x) of chars per line and write to fileName.out
	sort words and get word count. write to fileName.words
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int cmp_str(const void *a, const void *b)
{
    const char* aa = *(const char**)a;
    const char* bb = *(const char**)b;
    return strcmp(aa, bb);
}
int main(int argc, char const *argv[])
{
    int const numchars = atoi(argv[1]);

    char const *fileName = argv[2];
    char fileName2[255];
    strcat(fileName2,fileName);
    strcat(fileName2,".out");
    char fileName3[255];
    strcat(fileName3,fileName);
    strcat(fileName3,".words");

	char **wordlist = malloc(sizeof(char*));
	int i, wordcount, numwords = 0;


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
	FILE* file3 = fopen(fileName3,"w+");
	char word[1024], lastword[1024];
	char *outLine = malloc(numchars*sizeof(char*));

	if(file == NULL){
		perror("File cannot be opened : ");
		exit(0);
	}
	else{
		while(fscanf(file, "%1023s", word) == 1){
			
			if(numwords == 0){
				wordlist[0] = strdup(word);
			}
			else{
				wordlist = realloc( wordlist, (numwords + 1) * sizeof( char * ) );
				wordlist[ numwords ] = strdup(word);
			}
			numwords++;

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
		qsort(wordlist,numwords,sizeof(char*),cmp_str);

		wordcount = 1;
		

		for(i = 1; i<numwords; i++){
			
			printf(" %d\n", strcmp(wordlist[i], wordlist[i-1]));
			if(strcmp(wordlist[i] , wordlist[i-1]) == 0){
				wordcount++;
			}
			else{
				fprintf(file3,"%s - %d\n",wordlist[i-1],wordcount);
				wordcount = 1;
				strcat(lastword, "\0");
				strcat(lastword, wordlist[i]);
			}
			

		}
		for( i = 0; i < numwords; i++ )
			printf( "%s\n", wordlist[ i ] );
	}
	fclose(file);
	fclose(file2);
	fclose(file3);

	return 0;
}

