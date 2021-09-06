#include "anyBaseToBase10.h"
#include "charDigitToInteger.h"
#include "integerToCharDigit.h"
#include <iostream>

long anyBaseToBase10(const char* input_number, unsigned number_size,
    unsigned input_base)
{
    long base10Number = 0;
    long currentDigit;

    if (number_size <= 0)
    {
        std::cerr << "Can not input empty string for number!\n";
        return 0;
    }

    const bool isNegative = (input_number[0] == '-');
    if(isNegative)
    {
        input_number++; //point to the next character in the str
        number_size--;  //account for the size of str shrinking by 1
    }

    for(unsigned i = 0; i < number_size; i++)
    {

        currentDigit = charDigitToInteger(input_number[i]);
        //currentDigit input_number[i] was not a valid character
        //for conversion
        if (currentDigit == -1)
        {
            std::cerr << input_number[i] <<  " is not a valid character.\n";
            return 0;
        }
        if (currentDigit >= input_base)
        {
            std::cerr << input_number[i] 
            <<  " is not a valid character in base " << input_base << "\n";
            std::cerr << "Max valid character for base "
            << input_base << ": " << integerToCharDigit(input_base - 1) << "\n";
            return 0;
        }
        base10Number *= input_base;
        base10Number += currentDigit;
    }

    if (isNegative)
        return base10Number*-1;
    return base10Number;
}