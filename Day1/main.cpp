#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>

int main(){

    std::string fileName = "input.txt";
    std::ifstream file(fileName);

    if (!file.is_open()){
        std::cerr << "Error opening file:" << fileName << std::endl;
        return 1;
    }

    std::string line;
    std::vector<int> numbers;
    int total = 0;

    while (std::getline(file, line)) {

        char firstDigit = '\0';
        char lastDigit = '\0';

        for (char ch : line)
        {
            if (isdigit(ch)) {
                if(firstDigit == '\0') {
                    firstDigit = ch;
                }
                lastDigit = ch;
            }
        }

        if (firstDigit != '\0' && lastDigit != '\0') {
                std::string concatenatedDigits = std::string(1, firstDigit) + lastDigit;
                int resultNumber = std::stoi(concatenatedDigits);
                numbers.push_back(resultNumber);
        }
    }

    total = std::accumulate(numbers.begin(), numbers.end(), 0);
    std::cout << total << std::endl;
    file.close();

    return 0;
}