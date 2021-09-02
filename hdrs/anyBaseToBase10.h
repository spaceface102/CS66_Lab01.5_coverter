#ifndef ANYBASE_TO_BASE10_H
#define ANYBASE_TO_BASE10_H

//number_size is the number of characters that input_number
//is, aka what we would expect strlen() to return assuming
//that input_number does have a null terminating character
long anyBaseToBase10(const char* input_number, unsigned number_size,
    unsigned input_base);

#endif //ANYBASE_TO_BASE10_H