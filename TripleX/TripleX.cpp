#include<iostream>  //preprocessor directive and header file 
#include<ctime>

void PrintIntroduction(int Difficulty) {
    std::cout << "\n\nYou are a secret agent braking into a Level " << Difficulty;
    std::cout << " secure server room...\nEnter the correct code to continue...\n";
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    std::cout << std::endl;
    std::cout << "The codes add up to: " << CodeSum << "\n";
    std::cout << "The codes multiply to give: " << CodeProduct<< "\n";

    int GuessA, GuessB, GuessC, GuessSum, GuessProduct;

    std::cin >> GuessA >> GuessB >> GuessC;

    std::cout << "You entered: " << GuessA << GuessB << GuessC << "\n";

    GuessSum = GuessA + GuessB + GuessC;
    GuessProduct = GuessA * GuessB * GuessC;

    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        std::cout << "You win!\n";
        return true;
    } else {
        std::cout << "You entered the wrong answer.\n";
        return false;
    }


}

int main() {
    int LevelDifficulty = 2;
    const int MaxLevel = 10;

    while (LevelDifficulty <= MaxLevel) {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();
        if (bLevelComplete) {
            LevelDifficulty += 1;
        }
        
    }

    std::cout << "\n Great work agent! You got all the files! \n";
    return 0;
}