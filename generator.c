#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFERSIZE 64

void welcome()
{
	printf("-----Voicing Generator-----\n");
	printf("Written by August Cho\n");
	printf("Designed for jazz piano\n");
	printf("\nInstructions:\n");
	printf("Type your chord root followed by quality.\n");
}

const char * toNote(int number)
{
	char * note = malloc(BUFFERSIZE);

	if (number % 12 == 1)
	{
		strcpy(note, "C");
	}
	else if (number % 12 == 2)
	{
		strcpy(note, "Db");
	}
	else if (number % 12 == 3)
	{
		strcpy(note, "D");
	}
	else if (number % 12 == 4)
	{
		strcpy(note, "Eb");
	}
	else if (number % 12 == 5)
	{
		strcpy(note, "E");
	}
	else if (number % 12 == 6)
	{
		strcpy(note, "F");
	}
	else if (number % 12 == 7)
	{
		strcpy(note, "Gb");
	}
	else if (number % 12 == 8)
	{
		strcpy(note, "G");
	}
	else if (number % 12 == 9)
	{
		strcpy(note, "Ab");
	}
	else if (number % 12 == 10)
	{
		strcpy(note, "A");
	}
	else if (number % 12 == 11)
	{
		strcpy(note, "Bb");
	}
	else if (number % 12 == 0)
	{
		strcpy(note, "B");
	}

	return note;
}

int main()
{
	/*char chordRoot[BUFFERSIZE];*/
	int chordRoot[1];
	int chordQuality[1];	
	int root, quality, bottomShell, topShell, ninth, fifth;
	int chord[4];

	while (1 == 1)
	{
		system("clear");
		
		welcome();
		printf("Current voicing:\n");
		int i;
		for (i = 3; i >= 0; --i)
		{
			printf("%s \n", toNote(chord[i]));
		}	

		printf("For now, enter chord root as number, starting on 1 = C and ending on 11 = B\n");
		printf("Same with quality, 0 = major, 1= dom, 2 = min, 3 = halfdim, 4 = full dim");
		printf("> ");
		scanf("%i %i", chordRoot, chordQuality);
	
		root = chordRoot[0];
		quality = chordQuality[0];

		/**
		 * Generates basic shell voicing
		 */
		if (quality == 0)
		{
			bottomShell = root + 4;
			topShell = root + 11;
		}
		else if (quality == 1)
		{
			bottomShell = root + 4;
			topShell = root + 10;
		}
		else if (quality == 2)
		{
			bottomShell = root + 3;
			topShell = root + 10;
		}

		/**
		 * Inverts shell if too high
		 */
		if (topShell > 11)
		{
			topShell = topShell - 12;
		}
		if (bottomShell > 11)
		{
			bottomShell = bottomShell - 12;
		}
		if (bottomShell > topShell)
		{
			int temp = bottomShell;
			bottomShell = topShell;
			topShell = temp;
		}

		/**
		 * Checks to make sure not half-dim or full-dim
		 */
		if (!(quality > 2))
		{
			ninth = root + 2;
			fifth = root + 7;
		}

		if (ninth < bottomShell)
		{
			ninth = ninth + 12;
		}
		if (fifth < bottomShell)
		{
			fifth = fifth + 12;
		}

		chord[0] = bottomShell;
		if (fifth < ninth)
		{
			chord[1] = fifth;
			chord[3] = ninth;
		}
		else
		{
			chord[1] = ninth;
			chord[3] = fifth;
		}
		chord[2] = topShell;
	}

	return 0;
}

