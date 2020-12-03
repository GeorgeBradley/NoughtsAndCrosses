#include <iostream>
#include <vector>
#include <map>
#include <utility>

void DisplayGrid(const std::vector<std::vector<std::pair<int, unsigned char>>>&Grid) 
{
    for (auto i = 0; i < Grid.size(); i++) {
        for (auto i2 = 0; i2 < Grid.size(); i2++) {

            if (Grid.at(i).at(i2).second != '-')
            {
                std::cout << Grid.at(i).at(i2).second << "    ";
            }
            else 
            {
                std::cout << Grid.at(i).at(i2).first << "    ";
            }
        }
        std::cout << "\n\n";
    }
    std::cout << "\n";
}

bool CheckForAWinner(const std::vector<std::vector<std::pair<int, unsigned char>>>&Grid, const unsigned char key) {
  
    if (Grid.at(0).at(0).second == key  && Grid.at(0).at(1).second == key && Grid.at(0).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(1).at(0).second == key && Grid.at(1).at(1).second == key && Grid.at(1).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(2).at(0).second == key && Grid.at(2).at(1).second == key && Grid.at(2).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(0).at(0).second == key && Grid.at(1).at(0).second == key && Grid.at(2).at(0).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(0).at(1).second == key && Grid.at(1).at(1).second == key && Grid.at(2).at(1).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(0).at(2).second == key && Grid.at(1).at(2).second == key && Grid.at(2).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(0).at(0).second == key && Grid.at(1).at(1).second == key && Grid.at(2).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(2).at(0).second == key && Grid.at(1).at(1).second == key && Grid.at(0).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else if (Grid.at(2).at(0).second == key && Grid.at(1).at(1).second == key && Grid.at(0).at(2).second == key) {
        std::cout << key << " is the winner" << std::endl;
        return true;
    }
    else 
    {
        return false;
    }
}

bool ClaimSquare(std::vector<std::vector<std::pair<int, unsigned char>>>& Grid, int iMove, const unsigned char player) 
{
    for (int iCount = 0; iCount < Grid.size(); iCount++)
    {
        for (int iCount2 = 0; iCount2 < Grid.size(); iCount2++)
        {
            if (Grid.at(iCount).at(iCount2).first == iMove)
            {
                if (Grid.at(iCount).at(iCount2).second == '-')
                {
                    Grid.at(iCount).at(iCount2).second = player;
                    return true;
                }
                else
                {
                    std::cout << "This square has already been claimed. Choose a different square!" << std::endl;
                    return false;
                }
            }     
        }
    }
}
void PlayerMove(std::vector<std::vector<std::pair<int, unsigned char>>>& Grid, unsigned char player) {
    int iMove = 0;
    bool bExit = false;
    do 
    {
        iMove = 0;
        DisplayGrid(Grid);
        std::cout << player << " turn: " << std::endl;
        std::cout << "Enter a number on the grid: ";
       std::cin >> iMove;
        bExit = ClaimSquare(Grid, iMove, player);

    } while (bExit == false);
}
void PlayNoughtsAndCrosses() {

    const unsigned char player1 = 'O';
    const unsigned char player2 = 'X';
    bool winner = false;
    bool isThereWinner = false;
    std::vector<std::vector<std::pair<int, unsigned char>>>Grid =
    {
        {std::make_pair(1,'-'), std::make_pair(2,'-'), std::make_pair(3,'-') },

        {std::make_pair(4,'-'), std::make_pair(5,'-'), std::make_pair(6,'-') },

        {std::make_pair(7,'-'), std::make_pair(8,'-'), std::make_pair(9,'-') }

    };

    do 
    {
        PlayerMove(Grid, player1);
        if (CheckForAWinner(Grid, player1)) 
        {
            break;
        }
        PlayerMove(Grid, player2);
    } 
    while (CheckForAWinner(Grid, player2) == false);
    
}
int main()
{
    unsigned char response = 0;
    std::cout << "Do you want to play a game of noughts and crosses?: ";
    std::cin >> response;
    response = tolower(response);
    if (response == 'y') 
    {
        PlayNoughtsAndCrosses();
    }
    
}
