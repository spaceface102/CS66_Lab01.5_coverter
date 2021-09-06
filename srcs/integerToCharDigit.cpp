#include "integerToCharDigit.h"

char integerToCharDigit(int integer_digit)
{
    const char* CONVERTION_TABLE 
    = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (integer_digit < 0 || integer_digit > 35)
        return -1;

    return CONVERTION_TABLE[integer_digit];
}