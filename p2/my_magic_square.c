// add your own File Header information here (as described in Commenting guide)
////////////////////////////////////////////////////////////////////////////////
// Main File:        my_magic_square.c
// This File:        my_magic_square.c
// Other Files:      check_sudoku_board.c
// Semester:         CS 354 Lecture 01 Fall 2024
// Grade Group:      gg12  (See canvas.wisc.edu/groups for your gg#)
// Instructor:       deppeler
// 
// Author:           Artem Lyu
// Email:            alyu3@wisc.edu
// CS Login:         artem
//
///////////////////////////  OPTIONAL WORK LOG  //////////////////////////////
//  Document your work sessions here or on your copy http://tiny.cc/work-log
//  Keep track of commands, structures, code that you have learned.
//  This will help you focus your review on this from each program that
//  are new to you. There is no need to submit work log.
/////////////////////////// OTHER SOURCES OF HELP ////////////////////////////// 
// Persons:          Identify persons by name, relationship to you, and email.
//                   Describe in detail the the ideas and help they provided.
//
// Online sources:   avoid web searches to solve your problems, but if you do
//                   search, be sure to include Web URLs and description of 
//                   of any information you find.
// 
// AI chats:         save a transcript and submit with project.
//////////////////////////// 80 columns wide ///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
// Used by permission, CS 354 Fall 2024, Deb Deppeler
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure that represents a magic square
typedef struct {
	int size;           // dimension of the square
	int **magic_square; // 2D heap array that stores magic square
} MagicSquare;

/* TODO:
 * Prompts the user for the magic square's size, read size,
 * check if it's an odd number >= 3 
 * (if not valid size, display the required error message and exit)
 *
 * return the valid number
 */
int getSize() {
	int myNum = 0;
	printf("Enter magic square's size (odd integer >= 3)\n");
	scanf("%d", &myNum);
	if (myNum % 2 != 1) {
		printf("Magic square size must be odd.");
		exit(1);
	}

	if (myNum < 3) {
		printf("Magic square size must be >= 3.");
		exit(1);
	} 
	
	return myNum;   
} 

/* TODO:
 * Creates a magic square of size n on the heap.
 *
 * May use the Siamese magic square algorithm or alternate
 * valid algorithm that produces a magic square. 
 *
 * n - the number of rows and columns
 *
 * returns a pointer to the completed MagicSquare struct.
 */
MagicSquare *generateMagicSquare(int n) {
	MagicSquare *board = (MagicSquare *)malloc(sizeof(MagicSquare));
	board->size = n;

	int **square = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < n; i++) {
		*(square + i) = (int *)malloc(n * sizeof(int));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(square + i) + j) = 0;
		}
	}
	
	int num = 1;
	int row = 0;
	int col = n / 2;

	while (num <= n * n) {		
		*(*(square + row) + col) = num;
		
		int new_row = (row - 1 + n) % n;
		int new_col = (col + 1) % n;		


		if (*(*(square + new_row) + new_col) != 0) {
			row = (row + 1) % n;
		} else {
			row = new_row;
			col = new_col;
		}

		num++;
	}

	board->magic_square = square;
	return board;
} 

/* TODO:  
 * Open a new file (or overwrites the existing file)
 * and write the magic square values to the file
 * in the format specified by assignment.
 *
 * See assigntment for required file format.
 *
 * magic_square - the magic square to write to a file
 * filename - the name of the output file
 */
void fileOutputMagicSquare(MagicSquare *magic_square, char *filename) {
	FILE *fp;
	
	fp = fopen(filename, "w");

	if (fp == NULL) {
		printf("Error opening file!\n");
		exit(1);
	}
	fprintf(fp, "%d\n", magic_square->size);
	for (int i = 0; i < magic_square->size; i++) {
		for (int j = 0; j < magic_square->size; j++) {
			fprintf(fp, "%d", *(*(magic_square->magic_square + i) + j));
			if (j < magic_square->size - 1) {
				fprintf(fp, ",");
			}
		}
		fprintf(fp, "\n");
	}
	fclose(fp);
}


/* TODO:
 * Call other functions to generate a magic square 
 * of the user specified size and outputs 
 * the created square to the output filename.
 * 
 * Add description of required CLAs here
 */
int main(int argc, char **argv) {
	// TODO: Check input arguments to get output filename
	if (argc != 2) {
		printf("Usage: ./my_magic_square <output_filename>\n");
		exit(1);
	}
	// TODO: Get magic square's size from user
	int size = getSize();
	// TODO: Generate the magic square by correctly interpreting 
	//       the algorithm(s) in the write-up or by writing or your own.  
	//       You must confirm that your program produces a 
	//       Magic Square. See description in the linked Wikipedia page.
	MagicSquare *boardTwo = generateMagicSquare(size);
	fileOutputMagicSquare(boardTwo, *(argv + 1));
	// TODO: Output the magic square
	for (int i = 0; i < boardTwo->size; i++) {
        free(*(boardTwo->magic_square + i));
    }

    // Free the array of pointers (the magic square itself)
    free(boardTwo->magic_square);

    // Free the MagicSquare struct
    free(boardTwo);	
	return 0;
} 

// 202409



