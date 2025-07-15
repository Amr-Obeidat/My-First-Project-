// Libraries

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>


#include <iostream>
using namespace std;
  
// Input Functions
float ReadNumber(const string& promt) {
    cout << promt << endl;
    float number;
    while (!(cin >> number)) {
        cout << "Invalid value" << promt;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return number;
}

int ReadPositiveNumber(const string& prompt) {
    int number;
    cout << prompt;
    while (!(cin >> number) || number < 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a positive number: ";
    }
    return number;
}

int ReadNumberInRange(const string& message, int from, int to) {
    int number;
    cout << message << " [" << from << " - " << to << "]: ";
    while (!(cin >> number) || number < from || number > to) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter a number between " << from << " and " << to << ": ";
    }
    return number;
}


// Random‑Number & Key‑Generation Functions
int RandomNumber(int From, int To) {
    if (From > To) {
        cout << "Inavlid Range Enter a Valid Range\n";
        return -1;
    }
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}


/////////////////////////////////////////////////////////////////////////////////////////////
short GamesPlayerWon = 0;
short GamesComputerWon = 0;
short GamesOfDraw = 0;
short NumberOfRounds = 0;
bool DoYouWantToPlayAgain() {
    int number = ReadNumberInRange("Do You want to Play again YES(1):NO(0)  ", 0, 1);
    
    
    return static_cast<bool>(number);
}
void ResetTheScreenColor() {
    system("color 07");
}

void PrintSpace() {
    cout << "\n\n";
}
void PrintTabs() {
    cout << "_________________________________________";
}
int ReadTheNumberOfRounds() {
    int Rounds = ReadNumberInRange("Enter the number of rounds : ", 1, 10);
    return Rounds;

}
enum enRockPaperScissor { Rock = 1, Paper = 2, Scissor = 3 };
enRockPaperScissor ReadFromUser() {
    int Userchoice = ReadNumberInRange("Enter your choice Rock(1):Paper(2):Scissor(3): ", 1, 3);
    return static_cast<enRockPaperScissor>(Userchoice);
}
enRockPaperScissor ReadFromComputer() {
    int ComputerChoice = RandomNumber(1, 3);
    return static_cast<enRockPaperScissor>(ComputerChoice);

}
void PrintUserChoice(enRockPaperScissor UserChoice) {
    cout << "Player Choice :";
    if (UserChoice == ::Rock) {
        cout << "Rock\n";

    }
    else {
        if (UserChoice == ::Paper) {
            cout << "Paper\n";

        }
        else if (UserChoice == ::Scissor) {
            cout << "Scissor\n";

        }
    }


}
void PrintComputerChoice(enRockPaperScissor ComputerChoice) {
    cout << "Computer choice :";
    if (ComputerChoice == ::Rock) {
        cout << "Rock\n";

    }
    else {
        if (ComputerChoice == ::Paper) {
            cout << "Paper\n";

        }
        else if (ComputerChoice == ::Scissor) {
            cout << "Scissor\n";

        }
    }

}
enum enWinner { User = 1, Computer = 2, draw = 3 };
enWinner  CalculateRoundResult(enRockPaperScissor UserChoice, enRockPaperScissor ComputerChoice) {
    if (UserChoice == ComputerChoice) {
        return enWinner::draw;
   }
    
        else if (UserChoice == enRockPaperScissor::Paper && ComputerChoice == enRockPaperScissor::Rock) {
            return enWinner::User;
        }
        else if (UserChoice == enRockPaperScissor::Rock && ComputerChoice == enRockPaperScissor::Scissor) {
            return enWinner::User;

        }
        else if (UserChoice == enRockPaperScissor::Scissor && ComputerChoice == enRockPaperScissor::Paper) {
            return enWinner::User;
        }
    
    else {
        return enWinner::Computer;
    }


   

}
void PrintTheWinner(enWinner Winner) {
    if (Winner == enWinner::User) {
        cout << "The Winner is the user " << endl;
        system("color 2");
        GamesPlayerWon++;
    }
    else if (Winner == enWinner::Computer) {
        cout << "\aThe winner is the computer " << endl;
        system("color 4");
        GamesComputerWon++;
    }
    else {
        cout << "No Winner(draw) " << endl;
        system("color 6");
        GamesOfDraw++;
    }
}

void StartTheGame();
void EndGame();

void StartTheGame() {
    ResetTheScreenColor();
    GamesComputerWon = 0;
    GamesPlayerWon = 0;
    GamesOfDraw = 0;




   NumberOfRounds = ReadTheNumberOfRounds();
    for (int i = 1; i <= NumberOfRounds; i++) {

        cout << "Round " << "[" << i << "]" << " begins : " << endl;


        enRockPaperScissor UserChoice = ReadFromUser();

        ResetTheScreenColor();

        enRockPaperScissor ComputerChoice = ReadFromComputer();

        PrintTabs();

        cout << "Round " << i;

        PrintTabs();

        cout << endl;
        PrintUserChoice(UserChoice);
        PrintComputerChoice(ComputerChoice);
        PrintTheWinner(CalculateRoundResult(UserChoice, ComputerChoice));

        PrintTabs(); PrintTabs(); cout << "_______";

        PrintSpace();



    }
    EndGame();


}
void PrintTheWinner();
void EndGame() {
    ResetTheScreenColor();
    cout << "-----------------------------------------------------------------------------------------\n\n";
    cout << "\t\t\t" << "+++" << " Game  Over " << "+++" << "\t\t\t" << endl;
    cout << "-----------------------------------------------------------------------------------------\n\n";
    cout << "---------------------------[" << "Game  Results " << "]" << "----------------------------------------------\n";
    cout << "Number Of Rounds \t\t "<<NumberOfRounds << endl;
    cout << "Number of user wins \t\t " << GamesPlayerWon << endl;
    cout << "Number of Computer wins\t\t " << GamesComputerWon << endl;
    cout << "Number of Draws  \t\t " << GamesOfDraw << endl;
    PrintTheWinner();
    cout << "-----------------------------------------------------------------------------------------\n\n";
  
    bool PlayAgain = DoYouWantToPlayAgain();
    if (PlayAgain == true) {
        StartTheGame();
    }
}
void PrintTheWinner(){
    if (GamesComputerWon > GamesPlayerWon) {
        cout << "The Winner is Computer\n";

    }
    else if(GamesComputerWon < GamesPlayerWon){
        cout << "The Winners is user\n";
    }
    else {
        cout << "There is no winner (draw)\n";
    }

}




int main()
{
   // srand((unsigned)time(NULL));
    srand(time(0));  // Seed the random generator once
    StartTheGame();
   

    
   
}
