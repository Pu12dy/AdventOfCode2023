#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <unordered_map>

// Function to convert spelled-out numbers into numeric values
int convSpelledNumbers(const std::string& word) {
    static const std::unordered_map<std::string, int> spelledNumbers = {
        {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5},
        {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}
    };
    auto it = spelledNumbers.find(word);
    return (it != spelledNumbers.end()) ? it->second : 0;
};


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
