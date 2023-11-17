#include<iostream>
#include<string>
using namespace std;





const int ROW = 3;
const int COLUMN = 3;
string Board[ROW][COLUMN];
bool xTurn;

void printCurrentState();
void runGame();
void initializeGame();
void getUserInput(bool xTurn);
void changeBoard(bool xTurn, int row_move, int column_move);
string IsDoneWithWinner(bool xTurn);

int main() {

	runGame();



	return 0;
}

void runGame() {
	initializeGame();


	for (int i = 0; i < 8; i++)
	{
		if (i % 2 != 0) {
			xTurn = true;
		}
		else
		{
			xTurn = false;
		}
		getUserInput(xTurn);
		printCurrentState();

		string finalResualt = IsDoneWithWinner(xTurn);

		if (finalResualt.compare("X") == 0) {
			cout << "X is the  winner." << endl;
			cout << "Thanks for playing." << endl;
			exit(0);
		}
		else if (finalResualt.compare("O") == 0)
		{
			cout << "O is the  winner." << endl;
			cout << "Thanks for playing." << endl;
			exit(0);
		}

	}

	cout << "It's a Tie." << endl;
	cout << "See you next Time." << endl;



}

void initializeGame() {

	for (int r = 0;r < ROW;r++) {
		for (int c = 0;c < COLUMN;c++) {

			Board[r][c] = " ";
		}
	}

}

void printCurrentState() {

	cout << "------" << endl;
	for (int i = 0;i < ROW;i++) {
		for (int j = 0;j < COLUMN;j++) {

			cout << Board[i][j] <<" ";
		}
		cout << endl;
		

	}
	cout << "------" << endl;

}

void getUserInput(bool xTurn) {

	string line;
	if (xTurn) {
		cout << "X's Turn" << endl;
	}
	else
	{
		cout << "O's Turn" <<endl;
	}
	cout << "Please enter your first play in the form of one number: ";
	int row_move = cin.get() - 48;
	cin.get();
	cout << "Please enter your second play in the form of one number: ";
	int column_move = cin.get() -48;

	cin.get();

	if (Board[row_move-1][column_move-1].compare(" ") == 0) {
		changeBoard(xTurn, row_move, column_move);
	}
	else
	{
		cout << "Move already done";
	}
	

}

void changeBoard(bool xTurn,int row_move,int column_move) {

	string targetChar;
	if (xTurn) {
		targetChar = "X";
	}
	else
	{
		targetChar = "O";
	}

	Board[row_move-1][column_move-1] = targetChar;
}

string IsDoneWithWinner(bool xTurn) {

	if (Board[0][0].compare(Board[1][0]) == 0 && Board[1][0].compare(Board[2][0]) == 0 && Board[1][0].compare(" ") != 0 && Board[0][0].compare(" ") != 0 && Board[2][0].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else
		{
			return "O";
		}

	} else if (Board[0][1].compare(Board[1][1]) == 0 && Board[1][1].compare(Board[2][1]) == 0 && Board[1][1].compare(" ") != 0 && Board[0][1].compare(" ") != 0 && Board[2][1].compare(" ") != 0) {
		if (xTurn) {
		
			return "X";
		}
		else
		{
			return "O";
		}

	}else if (Board[0][2].compare(Board[1][2]) == 0 && Board[1][2].compare(Board[2][2]) == 0 && Board[1][2].compare(" ") != 0 && Board[0][2].compare(" ") != 0 && Board[2][2].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else
		{
			return "O";
		}

	}else if (Board[0][0].compare(Board[1][1]) == 0 && Board[1][1].compare(Board[2][2]) == 0 && Board[1][1].compare(" ") != 0 && Board[0][0].compare(" ") != 0 && Board[2][2].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else
		{
			return "O";
		}

	}else if (Board[0][2].compare(Board[1][1]) == 0 && Board[1][1].compare(Board[2][0]) == 0 && Board[1][1].compare(" ") != 0 && Board[0][2].compare(" ") != 0 && Board[2][0].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else
		{
			return "O";
		}

	}
	else if (Board[0][0].compare(Board[0][1]) == 0 && Board[0][1].compare(Board[0][2]) == 0 && Board[0][1].compare(" ") != 0 && Board[0][2].compare(" ") != 0 && Board[0][0].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else
		{
			return "O";
		}

	}
	else if (Board[1][0].compare(Board[1][1]) == 0 && Board[1][1].compare(Board[1][2]) == 0 && Board[1][1].compare(" ") != 0 && Board[1][2].compare(" ") != 0 && Board[1][0].compare(" ") != 0) {
		if (xTurn) {
			return "X";
		}
		else if (Board[2][0].compare(Board[2][1]) == 0 && Board[2][1].compare(Board[2][2]) == 0 && Board[2][1].compare(" ") != 0 && Board[2][2].compare(" ") != 0 && Board[2][0].compare(" ") != 0) {
			if (xTurn) {
				return "X";
			}
			else
			{
				return "O";
			}

		}
		else
		{
			return "O";
		}

	}
	else {
		return "N";
	}


}


