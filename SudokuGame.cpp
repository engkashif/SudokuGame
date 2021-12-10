#include <iostream>   // including library
#include <cstdlib>    // for random function
#include <ctime>      // also for random function
using namespace std;
int grid[9][9] = { 0,0,0 };    // 2 dimensional array
int fixedbox[9][9] = { 0,0,0 }; // same array for comparison
int k = 0;             // k is the number of correct entries made by the user // also a global variable
char w = 'y';          // in order to start playing the game enter 'y' as in yes // global variable also
void intro();        // function declared for the introduction to project
void inigrid();      // declaration for the function to print initial grid
int verify(int, int, int);  // function declaration for the verification of the entered coordinates and values
void solgrid(int, int, int); // function declaration so to print the grid every time when correct value is entered
int lettertonum(char);     // function declaration for converting column number to a digit in order to be used
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
int main()
{
	intro();             // function calling for printing the introduction
	while (w == 'y' || w == 'Y')   // as the y as in yes is entered the code for the game runs
	{
		char v;             // v be the column name
		int a = 0, b = 0, c = 0;    // a refers to column, b refers to row number and c is the number entered
		inigrid();          // function calling for the initial grid to be printed
		while (k < 61)         // until and unless k is not 61 game does not ends
		{
			cout << "\nEnter coordinates and value = ";  // prints the statement
			cin >> v >> a >> c;   // gives the values to the compiler
			b = lettertonum(v);  // function calling to convert the column name entered to a number in order to be used
			if (a >= 1 && a <= 9 && b >= 1 && b <= 9 && c >= 1 && c <= 9 && fixedbox[a - 1][b - 1] == 0)   // checks all the conditions, if satisfied code proceeds
			{
				solgrid(a, b, c);  // function calling to enter the value and print the grid with it
			}
			else
			{
				cout << "Invalid Coordinates!!";  // if not satisfied prints statement
			}
		}
	}
	cout << "   See You Later ................";   // if 'n' is entered game closes
	return 0;
}
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
void intro()      // function definition starts
{
	cout << "\n                       WELCOME TO SUDOKU\n\n";        // to print statement
	cout << "    Developed By :-\n                   KASHIF AHMED\n";
	cout << "   Instructions :-\n              Values must not repeat in each row, column and 3x3 box.\n\n";
	cout << "          For Coordinates  :  Enter column, row and press enter ( A4 )\n";
	cout << "          For Values       :  Enter values from 1 to 9 and press enter (A4    9 )\n\n\n";
	cout << "   To Play The Game Press [y / n]";
	cin >> w;  // gives the console a 'y' as yes or 'n' as in no
}
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
void inigrid()  // function definition starts
{
	int a = 0, b = 0, c = 0;  // variable declaration
	srand(time(0));   // function to alter the input for random function every second
	int z = 1;  // variable declaration
	while (z <= 20)  // loop to enter random digits at random places
	{
		a = rand() % 9;  // for random row
		b = rand() % 9;  // for random column
		c = (rand() % 9) + 1;  //for random values
		int i = verify(a, b, c);  // function calling to verify the rules if followed
		if (i == 0)  // if all the rules followed the value is printed in the grid
		{
			grid[a][b] = c;   // saving in that particular place
			fixedbox[a][b] = c; // again saving to compare
		}
		z = 1;     // z is again one
		for (int x = 0;x < 9;x++)  // moving along columns
		{
			for (int y = 0;y < 9;y++)  // moving along rows
			{
				if (grid[x][y] != 0)  // if there is a value in the place already code proceeds
				{
					z = z + 1; // 1 is added in z
				}
			}
		}
	}
	cout << "      A     B     C        D     E     F        G     H     I" << endl;  // to print statement
	cout << "   _____________________________________________________________" << endl;
	for (int row = 0;row < 9;row++)  // loop to move along columns
	{
		cout << row + 1;
		for (int col = 0;col < 9;col++)  // loop to move along rows
		{
			if (col == 3 || col == 6)  // condition
			{
				cout << "   ||   ";  // to print statement
			}
			else
			{
				cout << "  |  ";  // to print statement
			}
			cout << grid[row][col];
			if (col == 8)  // condition
			{
				cout << "  |";
			}
		}
		cout << endl;
		if (row == 2 || row == 5)  // condition
		{
			cout << "   _____________________________________________________________" << endl;  // to print statement
		}
		cout << "   _____________________________________________________________" << endl;
	}
}
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
int verify(int a, int b, int c)  // function definition starts
{
	int wrong = 0;  // variable declaration
	for (int e = 0;e < 9;e++)  // loop to check along a column
	{
		if (c == grid[a][e])  // condition
		{
			wrong = wrong + 1;  // wrong is added by one
		}
	}
	for (int f = 0;f < 9;f++)  // loop to check along a row
	{
		if (c == grid[f][b])  // condition
		{
			wrong = wrong + 1;  // wrong is added by one
		}
	}
	// start of the checking in the boxes of 3*3 dimensions i.e smaller boxes


	if (a < 3 && b < 3)  // condition for first box
	{
		for (int m = 0;m < 3;m++)  // moving along the column of small box
		{
			for (int n = 0;n < 3;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a < 3 && b < 6 && b>2)  // condition for 2nd box
	{
		for (int m = 0;m < 3;m++)  // moving along the column of small box
		{
			for (int n = 3;n < 6;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a < 3 && b>5)  // condition for 3rd box
	{
		for (int m = 0;m < 3;m++)  // moving along the column of small box
		{
			for (int n = 6;n < 9;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 2 && a < 6 && b < 3)  // condition for 4th box
	{
		for (int m = 3;m < 6;m++)  // moving along the column of small box
		{
			for (int n = 0;n < 3;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 2 && a < 6 && b>2 && b < 6)  // condition for 5th box
	{
		for (int m = 3;m < 6;m++)  // moving along the column of small box
		{
			for (int n = 3;n < 6;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 2 && a < 6 && b>5)  // condition for 6th box
	{
		for (int m = 3;m < 6;m++)  // moving along the column of small box
		{
			for (int n = 6;n < 9;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 5 && b < 3)  // condition for 7th box
	{
		for (int m = 6;m < 9;m++)  // moving along the column of small box
		{
			for (int n = 0;n < 3;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 5 && b > 2 && b < 6)  // condition for 8th box
	{
		for (int m = 6;m < 9;m++)  // moving along the column of small box
		{
			for (int n = 3;n < 6;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	else if (a > 5 && b > 5)  // condition for 9th box
	{
		for (int m = 6;m < 9;m++)  // moving along the column of small box
		{
			for (int n = 6;n < 9;n++)  // moving along the row of small box
			{
				if (c == grid[m][n])  // condition to check whether the entered value is in any entry of the small box
				{
					wrong = wrong + 1;  // wrong is added by one
				}
			}
		}
	}
	return wrong;  //  wrong is returned
}
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
void solgrid(int a, int b, int c)  // function definition starts
{
	a--;  // decrement in a
	b--;  // decrement in b
	int wrong = verify(a, b, c);  // the output of function verify is wrong
	if (wrong == 0)  // if wrong is 0 then the code proceeds
	{
		cout << "\n\n\n\n\n\n\n\n\n      A     B     C        D     E     F        G     H     I" << endl;  // prints statement
		cout << "   _____________________________________________________________" << endl;
		for (int row = 0;row < 9;row++)  // moving across a column
		{
			cout << row + 1;  // column number
			for (int col = 0;col < 9;col++)  // moving across a row
			{
				if (col == 3 || col == 6)  // condition
				{
					cout << "   ||   ";  // prints statement
				}
				else
				{
					cout << "  |  ";  // prints statement
				}
				if (row == a && col == b)  //condition
				{
					grid[row][col] = c;  // saves value in c
				}
				cout << grid[row][col];  // prints the value
				if (col == 8)  //condition
				{
					cout << "  |";
				}
			}
			cout << endl;  // next line
			if (row == 2 || row == 5)  // condition
			{
				cout << "   _____________________________________________________________" << endl;  // prints statement
			}
			cout << "   _____________________________________________________________" << endl;
		}
		k++;  // increment in k
		if (k == 61)  // condition
		{
			cout << "\nCongratulations!!\n";  // prints statement
			cout << "You Have Completed The Sudoku................\n";
			cout << "Play Again ?? [y / n] = ";
			cin >> w;  // gives value of w to console
			if (w == 'y' || w == 'Y')  // condition
			{
				cout << "Lets Restart The Game......\n";
			}
		}
	}
	else
	{
		cout << "Invalid Value!!" << endl;
	}
}
/*
*************************************************************************************
**************************     Visual Separator    **********************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*************************************************************************************
*/
int lettertonum(char v)  // function definition
{
	int b = 0;  // variable declaration
	switch (v)  // switch statement
	{
	case 'A':  // case
	case 'a':  // case
		b = 1;  // giving value
		break;  // break statement
	case 'B':
	case 'b':
		b = 2;
		break;
	case 'C':
	case 'c':
		b = 3;
		break;
	case 'D':
	case 'd':
		b = 4;
		break;
	case 'E':
	case 'e':
		b = 5;
		break;
	case 'F':
	case 'f':
		b = 6;
		break;
	case 'G':
	case 'g':
		b = 7;
		break;
	case 'H':
	case 'h':
		b = 8;
		break;
	case 'I':
	case 'i':
		b = 9;
		break;
	default:
		b = 0;
	}
	return b;  // return statement
}
