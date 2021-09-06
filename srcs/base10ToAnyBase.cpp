#include "base10ToAnyBase.h"
#include "integerToCharDigit.h"

std::string base10ToAnyBase(long base10number, unsigned output_base)
{
    //input: base10number
    std::string output_number;
    int singledigit;

    if (base10number == 0)
        return "0";
    
    const bool isNegative = (base10number < 0);
    if(isNegative)
        base10number *= -1;

    while(base10number > 0)
    {
        singledigit = base10number%output_base;
        output_number += integerToCharDigit(singledigit);
        base10number /= output_base; 
    }

    //reverse string to get actual correct number
    for (int i = 0, j = output_number.size() - 1; i < j; i++, j--)
        std::swap(output_number[i], output_number[j]);

    if (isNegative)
        return "-" + output_number;
    return output_number;
}