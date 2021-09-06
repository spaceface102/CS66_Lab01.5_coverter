#include "baseConverter.h"
#include "base10ToAnyBase.h"
#include "anyBaseToBase10.h"

std::string baseConverter(const std::string& input_number, 
    unsigned input_base, unsigned output_base)
{
    return baseConverter(input_number.c_str(), 
                        input_number.size(),
                        input_base,
                        output_base);
}

std::string baseConverter(const char* input_number, unsigned number_size,
    unsigned input_base, unsigned output_base)
{
    if(input_base == output_base)
        return input_number;

    return 
    base10ToAnyBase(
        anyBaseToBase10(input_number, number_size, input_base),
        output_base);
}