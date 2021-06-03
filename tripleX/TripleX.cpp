#include <iostream>
#include <ctime>

void PrintIntroduction(int Difficulty){
    std::cout << "\n\nYou are a secret agent breaking into a level " << Difficulty;
    std::cout << " secure server room...\nYou need to enter the correct codes to continue..." << std::endl;
}

bool PlayGame(int Difficulty)
{
    srand(time(NULL)); // create new random sequence based on time of day
    
    // Print welcome messages to terminal
    PrintIntroduction(Difficulty);
    
    // Declare 3 number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and prodcut to terminal
    std::cout << std::endl;
    std::cout << "\n+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add-up to: " << CodeSum;
    std::cout << "\n+ The codes multiply to give: " << CodeProduct << std::endl;
    
    // Store player Guess
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << "You entered: " << GuessA << GuessB << GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if players guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\nYou win!";
        return true;
    }

    else
    {
        std::cout << "\nYou lose!";
        return false;
    }
}


int main()
{
    int LevelDifficulty = 1;
    const int MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty)
    {   
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }
        
    }

    std::cout << "\n*** Great work agent! You got all the files! Now get out of there! ***\n";
    return 0;
}