/*
 * Kim Magidhi
 * Circle Game - hw01
 *
 *Description:
 * 1. Get the number of game board gamme spaces from the user
 * 2. Randomly choose two spaces for the Goal and the Pit
 * 3. While the game is not over:
 *    a. Player and computer take turns rolling dice
 *    b. Players move based on dice rolls
 *    c. Check if a player reached the Goal or falls into the Pit
 *    d. Show the winner or loser
 * 4. Ask the user to play another game or quit
 *
 * Date: 10/13/2023
*/

#include <iostream>
#include <cstdlib> // To use the rand() function
#include <ctime> // To use the time() function

using namespace std;

//Function to roll the dice
int rollDice() {
    return (rand() % 6 + 1) + (rand() % 6 + 1);//Takes into account the fact that dice have 6 sides
}

int main() {
    srand(time(0));//This ensures that random numbers are different each run

    cout << "Welcome to the Circle Game!" << endl;
    
    //Variables to keep track of the scores
    int playerWins = 0;
    int computerWins = 0;
	
    //While loop that runs the game until the player says no	
    while (true) {
    	//Sets up the board
        int boardSize;
        cout << "Enter the number of spaces on the game board (at least 5): ";
        cin >> boardSize;

        //Keeps prompting the player to enter a number bigger than 5
        if (boardSize < 5) {
            cout << "Board size must be at least 5." << endl;
            continue;
        }

        //Generates the goal and pit
        int goal = (rand() % (boardSize - 2)) + 2;
        int pit = (rand() % (boardSize - 2)) + 2;
        //If the pit and goal are the same generate another pit
        while (pit == goal) {
            pit = (rand() % (boardSize - 2)) + 2;
        }

        cout << "Goal is at space #" << goal << ", and the Pit is at space #" << pit << "." << endl;

        //Initializes the player and computers positions
        int playerPosition = 0;
        int computerPosition = 0;

        //Loop that runs until someone wins or loses
        while (true) {
            cout << "Press Enter to roll the dice... \n \n";
            cin.get();//Waits for the enter 

            //Users play
            int userRoll = rollDice();
            playerPosition = (playerPosition + userRoll) % boardSize;
            cout << "You are now on space #" << playerPosition << "." << endl;
            //Checks if they are onn the goal or the pit
            if (playerPosition == goal) {
                cout << "Congratulations! You reached the Goal and won!" << endl;
                playerWins++;
                break;
            } else if (playerPosition == pit) {
                cout << "Sorry, you fell into the Pit and lost!" << endl;
                computerWins++;
                break;
            }

            //Computers play
            int computerRoll = rollDice();
            computerPosition = (computerPosition + computerRoll) % boardSize;
            cout << "Computer is now on space #" << computerPosition << "." << endl;
            //Checks if they are onn the goal or the pit
            if (computerPosition == goal) {
                cout << "The computer reached the Goal and won!" << endl;
                computerWins++;
                break;
            } else if (computerPosition == pit) {
                cout << "The computer fell into the Pit and lost!" << endl;
                playerWins++;
                break;
            }
        }
	
	    //Askes the user if they want to play again if not break the loop
        char playAgain;
        cout << "Do you want to play another game? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y' && playAgain != 'Y') {
            break;
        }
        
        cout << "Player wins: " << playerWins << ", Computer wins: " << computerWins << endl;
    }
    
    cout << "\nPlayer wins: " << playerWins << ", Computer wins: " << computerWins << endl;
    cout << "Thank you for playing the Game!" << endl;

    return 0;
}

