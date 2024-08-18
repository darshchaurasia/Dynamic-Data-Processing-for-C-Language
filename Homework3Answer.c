// CSE240 Fall 2023 HW3

// Darsh Chaurasia
// Your code will be compiled and ran using GCC. Keep this in mind. 

#include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)  // compiler directive for Visual Studio only. You can remove this if just using GCC.

// Read before you start:
// You are given a partially complete program. Your job is to complete the functions in order for this program to work successfully.
// All instructions are given above the required functions, please read them and follow them carefully. 
// You shoud not modify the function return types or parameters.
// You can assume that all inputs are valid. Ex: If prompted for an integer, the user will input an integer.
// You can use only the strlen() of strings.h library to check string length. Do not use any other string functions 
// because you are supposed to use pointers/array values for this homework. 
// Global Macro Values. They are used to define the size of 2D arrays
#define NUM_ROWS 5
#define NUM_COLUMNS 5
#define NUM_STRINGS 5 
#define STRING_LENGTH 50

// Forward Declarations
// TA Provided Functions
void printMatrix(int[NUM_ROWS][NUM_COLUMNS]); 
void printStrings(char[NUM_STRINGS][STRING_LENGTH]);

// To be written using Array Notation
void createMatrix(); 
void scalarMatrix(int[NUM_ROWS][NUM_COLUMNS], int);
void sumRowsMult(int[NUM_ROWS][NUM_COLUMNS]);
void transposeMatrix(int[NUM_ROWS][NUM_COLUMNS]); 

// To be written using Pointer Notation
void initializeStrings(char[NUM_STRINGS][STRING_LENGTH]); 
void toUppercase(char s[NUM_STRINGS][STRING_LENGTH]); 
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]); 

// To be written using either Array or Pointer Notation
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH]); 
int wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]); 
void splitAndPrintWords(char s[NUM_STRINGS*STRING_LENGTH]);

/*********************************************** TA PROVIDED FUNCTIONS ************************************************************/

// Traverses the 2D array of the integers 'matrix' (input from main)
// and print the contents in the following format (actual contents may vary)
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15
// 16 17 18 19 20
// 21 22 23 24 25
void printMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	for (int i = 0; i < NUM_ROWS; i++)
	{
		for (int j = 0; j < NUM_COLUMNS; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

// Uses pointer 'ptr' to traverse the 2D character array 'strings' and print each string.
// See the example outputs provided in the word document. Each string should be printed on a new line.
void printStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
	for (int i = 0; i < NUM_STRINGS; i++)
	{
		for (int j = 0; j < STRING_LENGTH; j++)
		{	
			printf("%c", *ptr++);			// print char after char to print a string
		}
		printf("\n");					// go to new line after printing one string
	}
}

/********************************************* ARRAY NOTATION PROBLEMS ************************************************************/

// Problem 1: createMatrix (4 points)
// Create and return a 2D array of integers
// to create the following matrix:
// 1 2 3 2 1
// 2 3 4 3 2
// 3 4 5 4 3
// 4 5 6 5 4
// 5 6 7 6 5
// Hint: You should call printMatrix();
void createMatrix(){
	// Use this matrix to store each element
	int matrixResult[NUM_ROWS][NUM_COLUMNS] = {
	{1, 2, 3, 2, 1},
  	{2, 3, 4, 3, 2},
 	 {3, 4, 5, 4, 3},
  	{4, 5, 6, 5, 4},
  	{5, 6, 7, 6, 5}
		};

	
	
	
	
	printMatrix(matrixResult);
	// Enter code Below (or above)
}

// Problem 2: scalarMatrix (4 points)
// Traverse the 2D array of integers 'matrix' and multiply each element of the matrix by a scalar value
// return the resulting matrix
// e.g.
// 1 2 3	    2 4 6
// 4 5 6	=>  8 10 12
// 7 8 9            14 16 18
// Hint: You should call printMatrix();
void scalarMatrix(int matrix[NUM_ROWS][NUM_COLUMNS], int multiple)
{
	// Use this matrix to store each element
	int matrixResult[NUM_ROWS][NUM_COLUMNS];
	for(int i = 0; i<NUM_ROWS; ++i) {
		for(int j = 0; j<NUM_COLUMNS;++j){
			matrixResult[j][i]= matrix[j][i] * multiple;
		}
	}
	printMatrix(matrixResult);
	// Enter code below (or above)
}

// Problem 3: sumRowsMult (4 points)
// Traverse the 2D array of the integers 'matrix', sum each row, and multiply that sum by 2.
// Use one array to store each total and return the array. 
// e.g.
// 1 2 3 4 5
// 6 7 8 9 10
// 11 12 13 14 15	=> 30 80 130 180 230
// 16 17 18 19 20
// 21 22 23 24 25
void sumRowsMult(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Use this matrix to store each element
	int matrixResult[NUM_ROWS];
	// Enter code below
	for (int k = 0; k < NUM_ROWS; k++) {
		matrixResult[k]=0;
	}

	for(int i = 0; i < NUM_ROWS; i++ )
	{
		for(int j = 0;j < NUM_COLUMNS; j++)
		{
			matrixResult[i] += matrix[i][j];
		}
		matrixResult[i] *= 2;
		}


	// Use this to print your solution
	for(int i = 0 ; i < 5 ; i ++){
		printf("%d ", matrixResult[i]);
	}
	printf("\n");
}


// Problem 4: transposeMatrix (4 points)
// Take the 2D array of integers in your 'matrix' and store the tranpose in another 2D array.
// Return this array. 
// You may assume that row and column counts are equal.
// e.g.
// 1 2 3 4 5			1 6 11 16 21
// 6 7 8 9 10			2 7 12 17 22
// 11 12 13 14 15	=>	3 8 13 18 23
// 16 17 18 19 20		4 9 14 19 24
// 21 22 23 24 25		5 10 15 20 25
// Hint: You should call printMatrix();
void transposeMatrix(int matrix[NUM_ROWS][NUM_COLUMNS])
{
	// Use this matrix to store each element
	int matrixResult[NUM_ROWS][NUM_COLUMNS];
	// Enter code below

	for( int i = 0 ; i < NUM_ROWS ; i++)
	 {
		for( int j = 0 ; j< NUM_COLUMNS ; j++)
		{
			matrixResult[i][j]  = matrix[j][i];
		}
	 }
	 printMatrix(matrixResult);
}

/********************************************* POINTER NOTATION PROBLEMS **********************************************************/

// Problem 5: initializeStrings (4 points)
// Use pointer 'ptr' to traverse the 2D array of characters variable 'strings' (input from user in main()) and set all characters in each
// array to a null terminator so that there is a 4 row and 50 column 2D array full of null terminators.
// The null terminator '\0' or ascii value 0 is used to denote the end of a string.
void initializeStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char* ptr = &strings[0][0];
	// Enter the code below
	for (int i =0 ; i < NUM_STRINGS; ++i)
	 
	{
	for (int j = 0; j<STRING_LENGTH; ++j)	 
		
		{
			*ptr =  '\0' ;
			ptr++;
		}
	}
}


// Problem 6: toUppercase (4 points)
// Convert the string in the array 'strings' to an uppercase string.
// Traverse the input using pointer 'p' and covert the character to an uppercase letter if it is lowercase.
// You need to write down the code to check whether or not the character is lowercase.
// HINT: Use a pointer to change the ASCII value of a character.
// The ASCII value of 'a'= 97 and the ASCII value of 'A' = 65 so the difference between them is 32.
// Hint: You'll want to pay special attention '\0' characters
void toUppercase(char strings[NUM_STRINGS][STRING_LENGTH]) {
	char* p = &strings[0][0];
	// enter code here
	for (int i = 0; i < NUM_STRINGS; ++i) 
	{
		for (int j = 0; j < STRING_LENGTH; ++j) {
		while (*p !='\0') {
			if (*p >= 97 && *p <= 122)
			{
				*p -=  32; // convert lower case letters into upper case
			}
			++p; 
		}
		p = &strings[i][0];
		}
	}
}


// Problem 7: concatStr (4 points)
// This function must be working as follows:
// 1. Concatenate the string in the array 'strings' together in a sentence.
// 2. Store the string to the array 'p_result'.
// 3. End 'p_result' with a Null Terminator
// The sample output is shown in document
// NOTE: This is the function partially containing what you have implemented so far.
// You may declare and use more pointers if needed.
// Hint: You'll want to pay special attention '\0' characters
void concatStr(char strings[NUM_STRINGS][STRING_LENGTH], char result[NUM_STRINGS * STRING_LENGTH]) {
	char* p_result = result;
	char* p_input = &strings[0][0];
	for (int i=0; i < NUM_STRINGS; i++) {
		p_input = &strings[i][0];
		while (*p_input!= '\0')
		{
			*p_result = *p_input;
			p_input++;
			p_result++;
		
		}

		if (i < NUM_STRINGS - 1) {
			*(p_result)= ' ';
			p_result++;
		}
		
	}

	*p_result= '\0';
	*p_result = ' ';
}

/******************************************* ARRAY OR POINTER NOTATION PROBLEMS ***************************************************/

// Problem 8: reverseStrings (4 points)
// Reverse all the strings in 'strings[][]' 
// Hint: You'll want to pay special attention '\0' characters
void reverseStrings(char strings[NUM_STRINGS][STRING_LENGTH])
{
	char temp;						// not necessary to use this variable
	char* ptr;						// pointer you'll use to keep track of your current string
	int len;						// len of current string
	// Enter the code below
	 // Iterate over each string in the array
  for (int i = 0; i < NUM_STRINGS; i++)
   {
    // Getting pointer to the beginning of the string
    ptr = strings[i];

    // Calculating the length of the string
    len = 0;
    while (*ptr != '\0') {
      len++;
      ptr++;
    }

    // Reverse the string
    for (int j = 0; j < len / 2; j++) {
      temp = strings[i][j];
      strings[i][j] = strings[i][len - j - 1];
      strings[i][len - j - 1] = temp;
    }
  }

}

// Problem 9: splitWords (4 points)
// Split s[] into individual words and store them in str[][].
// Read s[] character by character and copy into str[][], such that word 1 is in str[0][], 
// word 2 is in str[1][], and so on. Print the char array str[][], so that the separated words are 
// printed on their own line. Finally return str[][].
// Hint: Don't forget to initialize str[][] with the null terminator character '\0'.
// Hint: Words are separated by whitespace characters
// e.g. 
// "The quick brown fox jumped over the lazy dog"
// The
// quick
// brown
// fox
// jumped
// over
// the
// lazy
// dog
//
// *** IMPORTANT NOTE: Test Problem 9 under GCC. VS has been known to cause some minor character trimming issues, 
// if you experience these, try with GCC. ***
void splitWords(char s[NUM_STRINGS * STRING_LENGTH]) {
    char str[NUM_STRINGS][STRING_LENGTH];
    int word_num = 0, char_index = 0;

    // Initialize str[][] with null terminators
    for (int i = 0; i < NUM_STRINGS; i++) {
        for (int j = 0; j < STRING_LENGTH; j++) {
            str[i][j] = '\0';
        }
    }

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n') {
            if (char_index > 0) {
                word_num++;
                char_index = 0;
            }
        } else {
            str[word_num][char_index++] = s[i];
        }
    }

    // Print the separated words
    for (int i = 0; i <= word_num; i++) {
        printf("%s\n", str[i]);
    }
}

// Problem 10: wordMatch (4 points)
// This function must be working as follows:
// 1. Compare the strings in the 2D array with input string
// 2. If one of them matches with input string, return 1
// 3. Else return 0 
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Sun"  => return 1
// Example: strings array -> ["Hi", "Sun", "Devils"], input -> "Hello"  => return 0
// Hint: Be very aware of the Null Terminator '\0'
int wordMatch(char strings[NUM_STRINGS][STRING_LENGTH], char input[STRING_LENGTH]) {
    char* p;
    char* ip;
    int flag = 0;

    for (int i = 0; i < NUM_STRINGS; i++) {
        p = &strings[i][0];
        ip = input;

        while (*p == *ip && *p != '\0' && *ip != '\0') {
            p++;
            ip++;
        }

        if (*p == '\0' && *ip == '\0') {
            flag = 1;
            break;
        }
    }

    return flag;
}



// You should study and understand how this main() works.
// *** DO NOT modify it in any way ***
// *** Modifying this code will disrupt the autograder ***
int main()
{
	// Begin Array Section 
	printf("CSE240 HW3: Array Notation\n\n");

	// Question 1
	printf("\nChecking created Matrix.\n");
	createMatrix();
	printf("\n\n");
	
	// For Questions 2-4
	int matrix[NUM_ROWS][NUM_COLUMNS] = { 
		{25, 20, 15, 10, 5},
		{20, 16, 12, 8, 4},
		{15, 12, 9, 6, 3},
		{10, 8, 6, 4, 2},
		{5, 4, 3, 2, 1}
	};
	
	// Question 2
	printf("\nChecking scalar Matrix.\n");
	scalarMatrix(matrix,2);
	printf("\n\n");
	
	// Question 3
	printf("\nChecking summed Rows.\n");
	sumRowsMult(matrix);
	printf("\n\n");
	
	// Question 4
	printf("\nChecking transposition of Matrix.\n");
	transposeMatrix(matrix);
	printf("\n\n");

	// Begin Pointer Section
	printf("\nCSE240 HW3: Pointer Notation\n\n");

	char words[NUM_STRINGS * STRING_LENGTH];
	printf("\nEnter sentence with max 5 words: ");
	fgets(words, sizeof(words), stdin);

	char strings[NUM_STRINGS][STRING_LENGTH];
	char strings2[NUM_STRINGS][STRING_LENGTH]; // will store four strings each with a max length of 34
	char input[STRING_LENGTH];
	char result[NUM_STRINGS * STRING_LENGTH];
	
	// Question 5
	initializeStrings(strings);

	for (int i = 0; i < NUM_STRINGS; i++)
	{
		printf("Enter a string: ");				// prompt for string
		fgets(input, sizeof(input), stdin);			// store input string
		input[strlen(input) - 1] = '\0';			// convert trailing '\n' char to '\0' (null terminator)
		strcpy(strings[i], input);				// copy input to 2D strings array
		strcpy(strings2[i], input);
	}
	
	printf("\nInitialized Print:\n");
	printStrings(strings);
	printf("\n\n");
	

	//Question 6 
	printf("\nChecking conversion to uppercase.\n");
	toUppercase(strings);
	printStrings(strings);
	printf("\n\n");
	
	//Question 7
	printf("\nThe concatenated string is: \n");
	concatStr(strings, result);
	for (int i = 0; i < NUM_STRINGS * STRING_LENGTH; i++) {
		if (result[i] != '\0') {
			printf("%c", result[i]);
		}
		else
		{
			break;
		}
	}
	printf("\n\n\n\n");

	printf("CSE240 HW3: Combined Notation\n\n");
	
	//Question 8
	printf("\nChecking Reversing of Strings.\n");
	reverseStrings(strings);
	printStrings(strings);
	printf("\n");
	
	// Question 9
	printf("\n\nSplit String: ");
	splitWords(words);
	printf("\n\n");

	//Question 10
	printf("Current strings:\n");
	for(int i = 0 ; i < NUM_STRINGS ; i++){
		printf("%s\n", strings2[i]);
	}
	printf("\nEnter a string to find a match: "); // prompt for string
	fgets(input, sizeof(input), stdin); // store input string
	input[strlen(input) - 1] = '\0'; // convert trailing '\n' char to '\0' (null terminator)
	// Word match function call
	int flag = wordMatch(strings2, input);
	if(flag == 0){
		printf("Match Not Found!\n");
	}
	else if(flag == 1){
		printf("Match Found!\n");
	}

	return 0;
}
