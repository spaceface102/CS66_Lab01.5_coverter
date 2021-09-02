#ifndef BASE_CONVERTER_H
#define BASE_CONVERTER_H

#include <string>

std::string baseConverter(const std::string& input_number, 
    unsigned input_base, unsigned output_base);
std::string baseConverter(const char* input_number, unsigned number_size,
    unsigned input_base, unsigned output_base);

#endif //BASE_CONVERTER_H