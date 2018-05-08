#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#define MIN 0
#define MAX 100 

#define DIGITS 3			// max characters from input
#define BUFSIZE DIGITS+2	// carrige retrun + null

bool isValid(unsigned int r, unsigned int c, unsigned int n, unsigned int m) {

	if(r < 0 || r > (n -1))		// row boundry scan
		return false;
	if (c < 0 || c > (m -1))		// column boundry scan
		return false;

	return true;
}

unsigned int getInput(unsigned int maxinput) {

	unsigned int counter = 1; // console input packet counter
	char* chk = NULL;		// string residue from console input
	unsigned int value;				//filtered number
	char input[BUFSIZE];	// console input buffer
	bool validInput = true;	//loop until valid input
	bool error = false;		// error flag

	memset(input, '0', sizeof input);

	while (validInput){

		/* reset flags */
		counter = 1;
		error = false;
		chk = NULL;

		/* get whatever input */
		while (fgets(input, sizeof input, stdin) && !strchr(input, '\n')) {
			counter++;
		}
		
		/* check if input is too long - error */
		if (counter > 1)
			printf("Input is too long!\n");

		/* check if empty input - error */
		else if (input[0] == '\n')
			printf("No input!\n");

		/* check for exit */
		else if (input[0] == 'X' || input[0] == 'x') {
			printf("Exit!");
			exit(-1);
		}

		/* check if input contains spaces - error */
		else if (strchr(input, ' '))
			printf("Input must not contain a space character!\n");

		else {

		/* clearn carrige return from input */
		char find = '\n';
		const char *ptr = strchr(input, find);

		if (ptr) {
			int index = ptr - input;
			/* clean input, leave numbers */
			for (unsigned int z = index; z < strlen(input); z++) {
				input[z] = '\0';
			}
		}

		/* check if input is alphanumeric - error */
		for (unsigned int z = 0; z < strlen(input); z++) {
			if (!isdigit(input[z])) {
				printf("Input cannot have characters!\n");
				error = true;
				break;
			}
		}

		/* when input is clean - success */
		if (!error) {
			/* string to unsigned long */
			value = (int)strtol(input, &chk, 10); 

			if (value == 0)
				printf("Input cannot be zero!\n");
			else if (value > maxinput)
				printf("Input cannot be greater then %d!\n", maxinput);
			else{
					printf("Input is %d\n", value);
					validInput = false;
				} // else
			} // if	
		} // else
	} // while

	return (unsigned int) value;
}


void createField(unsigned int num, unsigned int n, unsigned int m) {
	unsigned int i, j;
	// make space for some row pointers
	unsigned char **field = (unsigned char **)malloc(n * sizeof(unsigned char *));
	// get some pointers to columns
	for (i = 0; i < n; i++)
		field[i] = (unsigned char *)malloc(m * sizeof(unsigned char));
	//clear field with zero
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {

			field[i][j] = '0';
		}

	unsigned int minesPlaced = 0;
	time_t t;

	/* Intializes random number generator */
	srand((unsigned)time(&t));

	while (minesPlaced < n) { // use number of rows as mzximum number of mines
		int x = rand() % n;
		int y = rand() % m;
		// make sure we don't place a mine on top of another
		if (field[x][y] != '*') {
			field[x][y] = '*';
			minesPlaced++;
		}
	}


	for (unsigned int r = 0; r < n; r++) {
		for (unsigned int c = 0; c < m; c++) {

			if (field[r][c] == '*') continue;

			if (isValid(r - 1, c, n, m))
			{
				if (field[r - 1][c] == '*')
					field[r][c]++;
			}

			if (isValid(r + 1, c, n, m))
			{
				if (field[r + 1][c] == '*')
					field[r][c]++;
			}


			if (isValid(r, c + 1, n, m))
			{
				if (field[r][c + 1] == '*')
					field[r][c]++;
			}

			if (isValid(r, c - 1, n, m))
			{
				if (field[r][c - 1] == '*')
					field[r][c]++;
			}


			if (isValid(r - 1, c + 1, n, m))
			{
				if (field[r - 1][c + 1] == '*')
					field[r][c]++;
			}

			if (isValid(r - 1, c - 1, n, m))
			{
				if (field[r - 1][c - 1] == '*')
					field[r][c]++;
			}

			if (isValid(r + 1, c + 1, n, m))
			{
				if (field[r + 1][c + 1] == '*')
					field[r][c]++;
			}

			if (isValid(r + 1, c - 1, n, m))
			{
				if (field[r + 1][c - 1] == '*')
					field[r][c]++;
			}
		}
	}

	printf("\nField #%d:\n", num);

	for (unsigned int r = 0; r < n; r++) {
		for (unsigned int c = 0; c < m; c++) {
			printf("%c", field[r][c]);
		}
		printf("\n");
	}
}

int main() {

	unsigned int map = 0;
	unsigned int* n;
	unsigned int* m;

	printf("Enter number of fields.\nMust be between 1 and 5.\n");

	map = getInput(5);

	printf("\nEnter field dimensions for each field.\n \
			\rRows value must be greater then %d \
			\rand columns value must be less then or equal to %d. \n\
			\rPress enter to confirm or x to quit.\n", MIN, MAX);

	/* store field dimensions to create space in mem with later */
	n = (unsigned int*)malloc(sizeof(unsigned int*) * map);
	m = (unsigned int*)malloc(sizeof(unsigned int*) * map);

	for (unsigned int z = 0; z < map; z++) {
		printf("\nField #%d - n: ", z+1);
			n[z] = getInput(MAX);
		printf("\nField #%d - m: ", z+1);
			m[z] = getInput(MAX);			
	}

	for (unsigned int z = 0; z < map; z++) {

		createField(z + 1, n[z], m[z]);
	}


	free(n);
	free(m);
	getchar();
	return 0;
}