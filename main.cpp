#include <iostream>

//constant variables
using namespace std;
constexpr int smallGridSize = 3;
constexpr int bigGridSize = 4;
char smallBoard[3][3];
char  largeBoard[4][4];
const string padding = "                ";
const string paddingLarge = "           ";
//Colour constants
const string RED = "\033[0;31m";
const string GREEN = "\033[0;32m";
const string BLUE = "\033[0;34m";
const string YELLOW = "\033[0;33m";
const string RESET = "\033[0m";
const string PURPLE = "\033[0;35m";


//intalise the small grid
void intSmallGrid() {
    //nested loop
    for(int i = 0; i < smallGridSize; i++) {
        for (int j = 0; j < smallGridSize; j++) {
            //i & j to iterate to over the each index in the array and fill it with a blank space
            smallBoard[i][j] = ' ';
        }
    }
}
//This is where the function ends

//initalise the large grid
void intLargeGrid() {
    //nested loop
    for(int i = 0; i < bigGridSize; i++) {
        for (int j = 0; j < bigGridSize; j++) {
            //i & j to iterate to over the each index in the array and fill it with a blank space
            largeBoard[i][j] = ' ';
        }
    }
}
//This is where the function ends

//This is where the small grid is displayed
void DisplaySmallGrid() {
    //Ascii Art
    string art = R"( _____ _     _____         _____
|_   _(_) __|_   _|_ _  __|_   _|__   ___
  | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
  | | | | (__ | | (_| | (__ | | (_) |  __/
  |_| |_|\___||_|\__,_|\___||_|\___/ \___|)";
    cout << PURPLE << art << "\n\n" << RESET << endl;
    cout << BLUE <<"          ========================" << RESET << endl;
    //Nested loop to display the board with padding
    for (int i = 0; i < smallGridSize; i++) {
        cout << padding;
        for (int j = 0; j < smallGridSize; j++) {
            //iterates over all the indexes in the array to check the state of the board
            cout << PURPLE <<  " " << smallBoard[i][j]  << "";
            // - 1 so the row does not print at the end  of the grid
            if (j < smallGridSize - 1)
                cout << RED << " |" << RESET;
        }
        cout << endl;
        // - 1 so col does not print at the bottom of the grid
        if (i < smallGridSize - 1) {
            cout << BLUE << "            |~~~~~~~~~~~~~~~~~|" << RESET << endl;
        }
    }
    cout << BLUE <<  "         =========================" << RESET <<  endl;
}
//End of function

//This is function start
void DisplayLargeGrid() {
    //Ascii art
    string art = R"( _____ _     _____         _____
|_   _(_) __|_   _|_ _  __|_   _|__   ___
  | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
  | | | | (__ | | (_| | (__ | | (_) |  __/
  |_| |_|\___||_|\__,_|\___||_|\___/ \___|)";
    cout << PURPLE << art << "\n\n" << RESET << endl;
    cout << BLUE <<"        ========================" << RESET << endl;
    //Nested loop for displaying the large grid
    for (int i = 0; i < bigGridSize; i++) {
        cout << paddingLarge;
        for (int j = 0; j < bigGridSize; j++) {
            //iterates over all the indexes in the array to check the state of the board
            cout << PURPLE << " " << largeBoard[i][j] << " ";
            // - 1 so the row does not print at the end  of the grid
            if (j < bigGridSize - 1)
                cout << RED <<  " |" << RESET;
        }
        cout << endl;
        // - 1 so col does not print at the bottom of the grid
        if (i < bigGridSize - 1) {
            cout << BLUE << "           |~~~~~~~~~~~~~~~~~|" << RESET << endl;
        }
    }
    cout << BLUE << "        ========================" << RESET << endl;
}
//End of function

//start of function
void largeGridTurn(char player) {
    //Define variables
    char rows;
    int cols;
    int bigRowIndex;

    //Gets the users input
    cin >> rows >> cols;

    //Use a switch case statement to assign letters to numbers which in turn correspond with the array
    switch (rows) {
        case 'a': bigRowIndex = 0; break;
        case 'b': bigRowIndex = 1; break;
        case 'c': bigRowIndex = 2; break;
        case 'd': bigRowIndex = 3; break;
        default:
            cout << RED << "Invalid row input." << RESET << endl;
        return;
    }

    //Validate columns on the large grid
    if (cols < 1 || cols > bigGridSize) {
        cout << RED << "Invalid column input." << RESET << endl;
        return;
    }

    //Update board
    if (largeBoard[bigRowIndex][cols - 1] == ' ') {
        largeBoard[bigRowIndex][cols - 1] = player;
    } else {
        cout << RED << "This spot is already taken." << RESET << endl;
    }
}

//This is the user input function
void smallGridTurn (char player) {
    //Define variables
    char row;
    int col;
    int rowIndex;
    //Telling the user how to play
    cout << BLUE << "\n          ----------------------\n          | [a1] | [a2] | [a3] |\n          | [b1] | [b2] | [b3] |\n          | [c1] | [c2] | [c3] | \n          ----------------------" << "\n          it's your turn player: " << player << RESET << endl;
    cin >> row >> col;

    //Use a switch case statement to assign letters to numbers which in turn correspond with the array
    switch (row) {
        case 'a': rowIndex = 0;
        break;
        case 'b': rowIndex = 1;
        break;
        case 'c': rowIndex = 2;
        break;
        default:
            cout << RED << "Invalid input." << RESET << endl;
            return;
    }
    //validation for coloums on small grid
    if (row < 1 || col > smallGridSize) {
        cout << RED << "Invalid input." << RESET << endl;
        return;
    }

    //update board
    if (smallBoard[rowIndex][col -1] == ' ') {
        smallBoard[rowIndex][col - 1] = player;
    } else {
        cout << RED << "This spot is taken" << RESET << endl;
    }
}
//This is the end of the function

//iterates over i (rows) from 0 - 2 to check for a straight winning combination horizontaly
bool checkWin(char player) {
    for (int i = 0; i < smallGridSize; i++) {
        if (smallBoard[i][0] == player && smallBoard[i][1] == player && smallBoard[i][2] == player) {
            return true;
    }
}
    //check cols
    //iterates over i (cols) from 0 - 2 to check for a straight winning combination vertically
    for (int i = 0; i < smallGridSize; i++) {
        if (smallBoard[0][i] == player && smallBoard[1][i] == player && smallBoard[2][i] == player) {
            return true;
    }
}
    //Check diagonals in the array
    if (smallBoard[0][0] == player && smallBoard[1][1] == player && smallBoard[2][2] == player) {
        return true;
    }
    if (smallBoard[0][2] == player && smallBoard[1][1] == player && smallBoard[2][0] == player) {
        return true;
    }
    return false;
}
//End of function

//Start of function
bool checkDraw() {
    //iterates over the array to check if no empty spaces are left in turn causing a draw, this function is called after the winning conditions have been checked
    for (int i = 0; i < smallGridSize; i++) {
        for (int j = 0; j < smallGridSize; j++) {
            if (smallBoard[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
//End of function

//Start of the function
bool checkLargeWin(char player) {
    //iterates over i (rows) from 0 - 2 to check for a straight winning combination horizontaly
    for (int i = 0; i < bigGridSize; i++) {
        if (largeBoard[i][0] == player && largeBoard[i][1] == player && largeBoard[i][2] == player) {
            return true;
        }
    }
    //iterates over i (cols) from 0 - 2 to check for a straight winning combination vertically
    for (int i = 0; i < bigGridSize; i++) {
        if (largeBoard[0][i] == player && largeBoard[1][i] == player && largeBoard[2][i] == player) {
            return true;
        }
    }
    //check diagonals
    if (largeBoard[0][0] == player && largeBoard[1][1] == player && largeBoard[2][2] == player) {
        return true;
    }
    if (largeBoard[0][2] == player && largeBoard[1][1] == player && largeBoard[2][0] == player) {
        return true;
    }
    return false;
}
//End of the function

//Start of the function
bool checkLargeDraw() {
    //iterates over the array to check if no empty spaces are left in turn causing a draw, this function is called after the winning conditions have been checked
    for (int i = 0; i < bigGridSize; i++) {
        for (int j = 0; j < bigGridSize; j++) {
            if (largeBoard[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}
//End of the function

//Start of function
void displayMenu() {
    //Ascii art
    string art = R"( _____ _     _____         _____
|_   _(_) __|_   _|_ _  __|_   _|__   ___
  | | | |/ __|| |/ _` |/ __|| |/ _ \ / _ \
  | | | | (__ | | (_| | (__ | | (_) |  __/
  |_| |_|\___||_|\__,_|\___||_|\___/ \___|)";
    cout << PURPLE << art << "\n\n" << RESET << endl;
    //Displays all menu options
    cout << PURPLE << "         ======== MENU =========\n" << RESET;
    cout << BLUE << "               Start game\n";
    cout << "              Instructions\n";
    cout << RED << "         ======== EXIT =========\n" << RESET;
    cout << "\n           [1] Start game\n           [2] How to play\n           [3] Exit" << endl;
}
//End of function

//Start of the function
void instructions() {
    //Displays the instructions for the game
    cout << "=======Instructions=======" << endl;
    cout << PURPLE << "It's noughts and crosses but with a twist! for each game you win\nyou get to place your marker on a larger grid extending your game" << RESET << endl;
    cout << PURPLE << "What are grid coordinates?\nGrid coordinates are a combination of numbers and letters that represent a location on the grid, here's a grid to get you started " << RESET << endl;
    cout << BLUE << "\n          -----------------------------\n          | [a1] | [a2] | [a3] | [a4] |\n          | [b1] | [b2] | [b3] | [b4] |\n          | [c1] | [c2] | [c3] | [c4] | \n          | [d1] | [d2] | [d3] | [d4] | \n          -----------------------------" << RESET << endl;
    cout << PURPLE << "" << RESET << endl;
    cin.ignore();
    cin.get();

}
//End of the function

void startGame() {
    char currentPlayer = 'X';
    //initalise the small grid
    intSmallGrid();
    //initalise the large grid
    intLargeGrid();
    //var for checking if game loop is true
    bool gameInProgress = true;

    while (gameInProgress) {
        //displays the small grid for the main mini games
        DisplaySmallGrid();
        //players turn for small grid
        smallGridTurn(currentPlayer);
        //check if the the current player has won by checking if the checkwin function returns true
        if (checkWin(currentPlayer)) {
            cout << PURPLE << "Player " << currentPlayer << YELLOW << " wins the small grid!" << RESET << endl;
            cout << YELLOW << "Now, choose a spot on the large grid!" << RESET << endl;
            //Displays the large grid for the winners input
            DisplayLargeGrid();
            //Allows user to inout into the large grid
            largeGridTurn(currentPlayer);
            if (checkLargeWin(currentPlayer)) {
                cout << PURPLE << "Player " << currentPlayer << YELLOW << " Wins the game congratulations!" << RESET << endl;
                cout << "Press enter to return to the main menu" << endl;
            }
            //reinitalises the small grid for a new mini game
            intSmallGrid();

            //switches player moves for the small grid
            if (currentPlayer == 'X') {
                currentPlayer = 'O';
            } else {
                currentPlayer = 'X';
            }
        }
        //Checks for draw
        else if (checkDraw()) {
            cout << "Draw!" << endl;
            gameInProgress = false;  //ends game if draw
        }
        else {
            //A more concise way of the if else statement for switching player moves on the small grid
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    //game ends display final grid
    cout << "Final Large Grid: " << endl;
    DisplayLargeGrid();
}

//This is the main function all functions above will be called into this function.
int main() {
    int choice;
    bool exitMenu = false;

    while (!exitMenu) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                startGame();
                break;
            case 2:
                instructions();
            break;
            case 3:
                cout << "Goodbye!\n";
                exitMenu = true;
            default: cout << "That is not a valid option, please try again!\n";
        }
    }
    return 0;
}