#include "baseConverter.h"
#include <iostream>
#include <cstring>
#include <cmath>

void binaryConverter(const std::string& number, std::ostream& output = std::cout);
void octalConverter(const std::string& number, std::ostream& output = std::cout);
void decimalConverter(const std::string& number, std::ostream& output = std::cout);
void hexConverter(const std::string& number, std::ostream& output = std::cout);
void standardConversionOutput(const std::string& number, unsigned input_base,
     std::ostream& output);

int main(void)
{
    unsigned short current_number;
    const int number_of_bits_current_number = sizeof(current_number)*8;
    char memory_for_number[number_of_bits_current_number + 1]; //+1 because of null terminating char
    char* binary_number_str = memory_for_number; //do this to allow pointer manipulation

    binary_number_str[number_of_bits_current_number] = '\0'; //set to null termating char

    current_number = 1;
    while (current_number != 0) //will stop at overflow
    {
        for (int i = 0; i < number_of_bits_current_number; i++)
        {
            bool isOne = current_number&(1 << (number_of_bits_current_number - 1 - i));
            binary_number_str[i] = isOne + '0';
        }
        //point to the first character with that is a one
        binary_number_str += number_of_bits_current_number - (int)std::log2f(current_number) - 1;

        //idea is that if we go through a full round of conversion and we still manage
        //to get back to the same number, then the conversion is most likely right
        //base 2 -> base 8 -> base 10 -> base16 -> base 2
        if (binary_number_str != baseConverter(
                                    baseConverter(
                                        baseConverter(
                                            baseConverter(
                                            binary_number_str,2,8), //convert binary to octal
                                        8,10), //convert octal to base 10
                                    10,16), //convert base 10 to hex
                                16,2)) //convert hex to binary
        {
            std::cerr 
            << "Failed Test!\n"
            << binary_number_str << " is not eq to:\n"
            << baseConverter(baseConverter(baseConverter(baseConverter(binary_number_str,2,8),8,10),10,16),16,2)
            << "\n";
        }
        current_number++;
        binary_number_str = memory_for_number;
    }

    std::cout << "End of test\n";
    return 0;
}
//EOF

void binaryConverter(const std::string& number, std::ostream& output)
{
    standardConversionOutput(number, 2, output);
}
//EOF

void octalConverter(const std::string& number, std::ostream& output)
{
    standardConversionOutput(number, 8, output);
}
//EOF

void decimalConverter(const std::string& number, std::ostream& output)
{
    standardConversionOutput(number, 10, output);
}
//EOF

void hexConverter(const std::string& number, std::ostream& output)
{
    standardConversionOutput(number, 16, output);
}
//EOF

void standardConversionOutput(const std::string& number, unsigned input_base,
     std::ostream& output)
{
    output
    <<  number << " conversion table:\n"
    << "Binary : " << baseConverter(number, input_base, 2) << "\n"
    << "Octal  : " << baseConverter(number, input_base, 8) << "\n"
    << "Decimal: " << baseConverter(number, input_base, 10) << "\n"
    << "Hex    : " << baseConverter(number, input_base, 16) << "\n";
}