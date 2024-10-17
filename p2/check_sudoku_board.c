// Add your file header here
// Fix compiler error
// Implement remaining functionality
////////////////////////////////////////////////////////////////////////////////
// Main File:        check_sudoku_board.c
// This File:        check_sudoku_board.c
// Other Files:      board.txt
// Semester:         CS 354 Lecture 001 Fall 2024
// Grade Group:      gg12
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
// Copyright 2021-24 Deb Deppeler
// Posting or sharing this file is prohibited, including any changes/additions.
//
// We have provided comments and structure for this program to help you get 
// started.  Later programs will not provide the same level of commenting,
// rather you will be expected to add same level of comments to your work.
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *DELIM = ",";  // commas ',' are a common delimiter character for data strings

/* TODO: implement this function
 * Returns 1 if and only if the 2D array of ints in board 
 * is in a valid Sudoku board state.  Otherwise returns 0.
 *
 * DOES NOT PRODUCES ANY PRINTED OUTPUT
 * 
 * A valid row or column contains only blanks or the digits 1-size, 
 * with no duplicate digits, where size is the value 1 to 9.
 * 
 * Note: This function requires only that each row and each column are valid.
 * 
 * board: heap allocated 2D array of integers 
 * size:  number of rows and columns in the board
 */
int valid_sudoko_board(int **board, int size) {
	if (size < 1 || size > 9) {
		return 0;
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (*(*(board + i) + j) < 0 || *(*(board + i) + j) > size) {
				return 0;
			}
		}
	}

	// Check for duplicate row elements

	for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = j + 1; k < size; k++) {
                if (*(*(board + i) + j) == *(*(board + i) + k) && *(*(board + i) + j) != 0) {
                    return 0;  // Duplicate found in row
                }
            }
        }
    }

	// Check for duplicate column elements	
	for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            for (int k = i + 1; k < size; k++) {
                if (*(*(board + i) + j) == *(*(board + k) + j) && *(*(board + i) + j) != 0) {
                    return 0;  // Duplicate found in column
                }
            }
        }
    }	


	return 1;   
}    

/* COMPLETED (DO NOT EDIT)       
 * Read the first line of file to get the size of that board.
 * 
 * PRE-CONDITION #1: file exists
 * PRE-CONDITION #2: first line of file contains valid non-zero integer value
 *
 * fptr: file pointer for the board's input file
 * size: a pointer to an int to store the size
 *
 * POST-CONDITION: the integer whos address is passed in as size (int *) 
 * will now have the size (number of rows and cols) of the board being checked.
 */
void get_board_size(FILE *fptr, int *size) {      
	char *line = NULL;
	size_t len = 0;

	// 'man getline' to learn about <stdio.h> getline
	if ( getline(&line, &len, fptr) == -1 ) {
		printf("Error reading the input file.\n");
		free(line);
		exit(1);
	}

	char *size_chars = NULL;
	size_chars = strtok(line, DELIM); // 'man strtok' string tokenizer
	*size = atoi(size_chars);         // 'man atoi' alpha to integer
	free(line);                       // free memory allocated for line 
}


/* TODO: COMPLETE THE MAIN FUNCTION
 * This program prints "valid" (without quotes) if the input file contains
 * a valid state of a Sudoku puzzle board wrt to rows and columns only.
 * It prints "invalid" (without quotes) if the input file is not valid.
 *
 * Usage: A single CLA that is the name of a file that contains data.
 *
 * argc: the number of command line args (CLAs)
 * argv: the CLA strings, includes the program name
 *
 * Returns 0 if file exists and is readable.
 * Exit with any non-zero result if unable to open and read the file given.
 */
int main( int argc, char **argv ) {              

	// TODO: Check if number of command-line arguments is correct.
	if (argc != 2) {
		printf("Number of command line arguments is not 1.\n");
		exit(1);
	}

	// Open the file 
	FILE *fp = fopen(*(argv + 1), "r");
	if (fp == NULL) {
		printf("Can't open file for reading.\n");
		exit(1);
	}

	// will store the board's size, number of rows and columns
	int size;
	size = 0;
	// TODO: Call get_board_size to read first line of file as the board size.
	get_board_size(fp, &size);
	// TODO: Dynamically allocate a 2D array for given board size.
	// You must dyamically create a array of pointers to other arrays of ints
	int **m = malloc(size * sizeof(int*));
	for (int i = 0; i < size; i++) {
		*(m+i) = malloc(size * sizeof(int));
	}
	// Read the remaining lines of the board data file.
	// Tokenize each line and store the values in your 2D array.
	char *line = NULL;
	size_t len = 0;
	char *token = NULL;
	for (int i = 0; i < size; i++) {

		// read the line
		if (getline(&line, &len, fp) == -1) {
			printf("Error while reading line %i of the file.\n", i+2);
			exit(1);
		}

		token = strtok(line, DELIM);
		for (int j = 0; j < size; j++) {
			// TODO: Complete the line of code below
			// to initialize elements of your 2D array.
			*(*(m + i)+ j) = atoi(token); 
			token = strtok(NULL, DELIM);
		}
	}

	// TODO: Call valid_sudoku_board and print the appropriate
	//       output depending on the function's return value.
	if (valid_sudoko_board(m, size) == 0) {
		printf("invalid");
	} else {
		printf("valid");
	}
	// TODO: Free dynamically allocated memory.
	for (int i = 0; i < size; i++) {
		free(*(m + i));
	}
	free(m);
	//Close the file.
	if (fclose(fp) != 0) {
		printf("Error while closing the file.\n");
		exit(1);
	} 

	return 0;       
}       

