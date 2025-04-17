#include <stdio.h>

#define BUFFERSIZE 64

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
	/*char chordRoot[BUFFERSIZE];*/
	int chordRoot[1];
	int chordQuality[1];	
	int root, quality, bottomShell, topShell, ninth, fifth;

	while (1 == 1)
	{
		system("clear");
		
		welcome();

		printf("Root: %i \n", root);
		printf("Top Shell: %i \n", topShell);
		printf("Bot Shell: %i \n", bottomShell);
		printf("Fifth: %i \n", fifth);
		printf("Ninth: %i \n", ninth);
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

	}

	return 0;
}

