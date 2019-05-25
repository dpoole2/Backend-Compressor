//@Author Dylan Poole
//@Description: This class will hold our Hashmap function and most likely will store it in a file
//All functions such as hashValue, get, add, and export will go in here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Define the use of an Array for now we can change this later if needed.
char array[10][100];


//Take in a string to convert into a integer
int hashValue(char *string)//wonderful naming Dylan
{
	//Let's do a simple stupid algorthim first
	int value = 0;//return this
	for(int x = 0; x < strlen(string); x++)
	{
		value += string[x];
	}
	value = value * 77;
	return value;
}

//return 0 if not added correctly
int add(char * string)//I like seperate chaining but for now just make it go to the next open index
{
	int index = (hashValue(string) + 7) % 10;//size of the array
	while(array[index][0] != '\0')//dig ip any tombstones and plant a flower :6)
	{
		index++;
	}
	strcpy(array[index], string);
	return 1;
}
int removeString(char * string)
{
	int index = (hashValue(string) + 7) % 10;
	while(array[index] == string)
	{
		index++;
	}
	array[index][0] = '\0'; 
		return 1; //if one everything should be good.
}
void printHashTable()
{
	int x;
	for(x = 0; x < 10; x++)
	{
		if(array[x][0] != '\0')//This is a tombstone it means something is there, but lets just bury it in mermory.
		{
		
		for(int y = 0; y < 100; y++)
		{
			//print each character
			printf("%c", array[x][y]);
		}
		}
	}
	printf("\n");
}
//If return is 1 then the array does contain this
//else it does not
int contains(char * string)
{
	
	int x;
	for(x = 0; x < 10; x++)
	{
		if(strcmp(string, array[x]))//if one it returns true
		{
			return 1;
		}
	}
	return 0;
}
int main()//Need main for testing will intergrate it all later.
{
	add("Hello World\n");
	add("OH NO\n");
	printHashTable();
	removeString("Hello World\n");
	printHashTable();
	printf("Let's see \n");
	printf("%d\n", contains("OH NO\n"));
	return 0;
}