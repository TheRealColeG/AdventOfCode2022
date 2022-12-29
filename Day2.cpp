#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int winner(char left, char right);
int calculateTotal(std::string line);
char whichToPick(char left, char right);

//Given the second character
//X = lose, Y = tie, Z = win
//If A, win = 2+6, lose = 3+0, tie = 1+3
//If B, win = 3+6, lose = 1+0, tie = 2+3
//If B, win = 1+6, lose = 2+0, tie = 3+3
char whichToPick(char left, char right) {

    //default to tie - can choose any of the three, no reason
    char choose;

    switch (left) {
        case 'A': 
            choose = 'X'; 
            break;
        case 'B': 
            choose = 'Y'; 
            break;
        case 'C': 
            choose = 'Z'; 
            break;
    }

    switch (right) {
    case 'X':
        //lose
        if (left == 'A') choose = 'Z';
        if (left == 'B') choose = 'X';
        if (left == 'C') choose = 'Y';
        break;
    case 'Z':
        //win
        if (left == 'A') choose = 'Y';
        if (left == 'B') choose = 'Z';
        if (left == 'C') choose = 'X';
        break;
    }

    return choose;
}

//unfortunately has to be int because ties exist
//0 lost, 1 win, else tie
//return 0 loss, 6 win, 3 tie
int winner(char left, char right) {

    int win = 6;
    int loss = 0;
    int tie = 3;

    //im putting breaks in the nested switch JUST in case
    //father forgive me for i have sinned
    switch (left) {
        case 'A': //rock
            switch (right) {
                case 'X': //rock
                    //tie
                    return tie;
                    break;
                case 'Y': //paper
                    //win
                    return win;
                    break;
                case 'Z': //scissors
                    //loss
                    return loss;
                    break;
            }
            break;
        case 'B': //paper
            switch (right) {
                case 'X': //rock
                    //loss
                    return loss;
                    break;
                case 'Y': //paper
                    //tie
                    return tie;
                    break;
                case 'Z': //scissors
                    //win
                    return win;
                    break;
            }
            break;
        case 'C': //scissors
            switch (right) {
                case 'X': //rock
                    //win
                    return win;
                    break;
                case 'Y': //paper
                    //loss
                    return loss;
                    break;
                case 'Z': //scissors
                    //tie
                    return tie;
                    break;
            }
            break;
    }

    return 0;
}

//will take each line (A Z) and calculate the round value
int calculateTotal(std::string line) {
    /*
    * A / X = Rock, score + 1
    * B / Y = Paper, score + 2
    * C / Z = Scissors, score + 3
    * +6 points for winning (Rock + win = 1 + 6 = 7)
    * 
    * Away = A,B,C
    * Home = X,Y,Z
    * 
    * Away = line[0]
    * Home = line[2]
    */

    char left = line[0];
    char right = whichToPick(line[0], line[2]);

    int total = winner(left, right);

    
    switch (right) {
        case 'X' :
            total += 1;
            break;
        case 'Y' :
            total += 2;
            break;
        case 'Z' :
            total += 3;
            break;
    }
    
       
    return total;
}

int main()
{
    std::ifstream day2;
    std::string eachLine;

    day2.open("day2.txt", std::ios::in);
    int total = 0;

    while (std::getline(day2, eachLine)) {
        total += calculateTotal(eachLine);
    }

    std::cout << total;

    return 0;
}
