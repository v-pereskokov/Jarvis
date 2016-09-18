#include <iostream>
#include <vector>
#include <string>

void pushAlphabet(std::vector<char> &symbols)
{
    for (std::size_t i = 0; i < 26; ++i)
        symbols.push_back(i + 65);
}

void toBin(std::vector<int> &digits, std::size_t target, std::size_t notation)
{
    while (target != 0) {
        digits.push_back(target % notation);
        target /= notation;
    }
}

// Перевод из 10 системы счисления
const std::string toNotation(std::size_t target, std::size_t notation)
{
    std::vector<int> digits;
    std::vector<char> symbols;
    pushAlphabet(symbols);
    toBin(digits, target, notation);
    std::string result;
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] >= 10)
            result += symbols[digits[i] - 10];
        else
        {
            result += std::to_string(digits[i]);
        }
    }
    return result;
}
