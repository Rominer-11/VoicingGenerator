#include <stdio.h>

#define BUFFERSIZE 64

int isExitCommand(char userCommand[])
{
	char exitCommand[BUFFERSIZE] = "exit\n";

	int n = 0;
	if (strcmp(userCommand, exitCommand) == 0)
	{
		n = 1;
	}
	return n;
}

void welcome()
{
	printf("-----Voicing Generator-----\n");
	printf("Written by August Cho\n");
	printf("Designed for jazz piano\n");
	printf("\nInstructions:\n");
	printf("Type your chord root followed by quality.\n");
}

int main()
{
	char userCommand[BUFFERSIZE];
	char exitCommand[BUFFERSIZE] = "exit\n";
	

	while (isExitCommand(userCommand) != 1)
	{
		system("clear");
		
		welcome();
		printf("> ");
		scanf("%s %s");
	}

	return 0;
}

