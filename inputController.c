//@author Dylan Poole
//This will control the input gained from the system.
//It decides how to save information.
#include <stdlib.h>
#include <stdio.h>
#include "hashMap.c"
//#include "input.c"

//string is the data you are checking for.
//make this function better later right now do shitty things
void findPlagrism(char * string)//Use this to find a string of characers that are atleast three chars long.
{
	char stringThree[strlen(string)];
	char stringTwo []= "Hello World, lol.\n";
	int loop = 0, ctr= 0, index = 0;
	for(int x = 0; x < strlen(string); x++){
		while(ctr < strlen(stringTwo))
		{
			if(string[x] == stringTwo[index])
			{
				printf("%d\n", loop);
				loop++;
				x++;
			}
			else if(loop >= 3)
			{
				for(int j = loop; j > 0; j--)
				{
					strcat(string[j], stringThree);
				}
			}
			else
			{
				//printf("%c\n", string[x]);
				loop = 0;
			}
			ctr++;
			index++;
		}
		if(loop >= 3)
		{
			for(int j = loop; j > 0; j--)
				{
					strcat(string[j], stringThree);
				}
		}
		ctr = 0;
		index = 0;
	}
	printf("%s\n", stringThree);
}



int main()
{
	if(getMapSize() == 0)//if map is empty give it this value to start it off.
	{
		add("Hello World, lol.\n");
		findPlagrism("Goodbye World, lol.\n");
		printf("Nope\n");
	}
	return 0;
}