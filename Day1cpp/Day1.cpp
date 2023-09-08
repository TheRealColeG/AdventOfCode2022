#include <iostream>
#include <fstream>
#include <string>
#include <vector>

/*
@each represents the list of calories each elf is carrying
@total is straightforward - total calories carried by that elf (sum of each)
*/
int eachElf(std::vector<int> each) {

    //size of the vector
    size_t size = each.size();

    //total value to increment by each caloric value
    int total = 0;

    //for loop summation
    for (size_t i = 0; i < size; i++) {
        total += each[i];
    }

    //returning total calories
    return total;
}

int main()
{
    //new input ifstream because input file
    std::ifstream input;

    //string to hold value of each line
    std::string eachline;

    //input file is "input" with "in" as ios for input
    input.open("day1", std::ios::in);

    //vector to hold each caloric value of the 
    std::vector<int> allCalories;

    //If new eachElf is higher than this, reassign it to that value
    //put them all on different lines because it looks nice :-)
    int highestVal =    0;
    int secondHighest = 0;
    int thirdHighest =  0;

    //until end of file, put each new line in eachLine
    while (std::getline(input, eachline)) {

        //if the line is blank
        if (eachline == "") {

            //check total of this elf
            int thisElf = eachElf(allCalories);

            //check if this elf is higher than the highest elf
            //I know it's ugly but I'm learning ok
            //Its fewer if checks - short circuit technique
            if (thisElf > thirdHighest) {

                if (thisElf > secondHighest) {
                    if (thisElf > highestVal) {
                        thirdHighest = secondHighest;
                        secondHighest = highestVal;
                        highestVal = thisElf;
                    }
                    else {
                        thirdHighest = secondHighest;
                        secondHighest = thisElf;
                    }
                }
                else {
                    thirdHighest = thisElf;
                }
            }

            //reset the vector / clear it / new elf
            allCalories.clear();
        }

        //if the line has content
        else {
            //append the calories to the current elf
            allCalories.insert(allCalories.begin(), stoi(eachline));
        }
    }
    //close the file for posterity
    input.close();

    //calculate top 3 elves
    int absoluteTotal = highestVal + secondHighest + thirdHighest;
    //print them because i wanted to
    std::cout << highestVal << "\n" << secondHighest << "\n" << thirdHighest << "\n\n" << absoluteTotal;

    //I know this isn't the prettiest solution, but I wanted to work more with vectors since I've never used them
    return 0;
}
