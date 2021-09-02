#include "baseConverter.h"
#include <iostream>
//here is where we will define the functions
//to convert between base10 to binary, octal, and hex

void binaryConverter(const std::string& number, std::ostream& output = std::cout);
void octalConverter(const std::string& number, std::ostream& output = std::cout);
void decimalConverter(const std::string& number, std::ostream& output = std::cout);
void hexConverter(const std::string& number, std::ostream& output = std::cout);
void standardConversionOutput(const std::string& number, unsigned input_base,
     std::ostream& output);

int main(void)
{
    binaryConverter("1001");
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