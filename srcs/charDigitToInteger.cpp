#include "charDigitToInteger.h"

int charDigitToInteger(char digit)
{
    if (digit >= 'A' && digit <= 'Z')
        return digit - 'A' + 10;
    if (digit >= 'a' && digit <= 'z')
        return digit - 'a' + 10;
    if(digit >= '0' && digit <= '9')
        return digit - '0';
    
    return -1; //error condition, digit was not valid
}