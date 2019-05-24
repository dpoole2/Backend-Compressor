//@author Dylan Poole
//@description: This file will be a simple input text that will grab text from a file and integrate it into the program

#include <stdio.h>
#include<stdlib.h>



void readFile(FILE *file)
{
	char c;
	while((c = fgetc(file)) != EOF)
	{
		printf("%c", c);
	}
}

void  main()//later on add an arg to this to take in the file name from the header. Since we run the show we can just use a user defined string
{
	char *fileName = "test.text";//Store testing data in this file
	FILE *fileOpen = fopen(fileName, "r");
	readFile(fileOpen);
}
