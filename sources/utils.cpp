#include "longtrip.h"

bool isInteger(const string& str)
{
    regex int_pattern("^\\s*\\d+\\s*$");
    return std::regex_match(str, int_pattern);
}

bool isFloat(const string& str)
{
    regex float_pattern("^\\s*\\d*\\.?\\d+\\s*$");
    return std::regex_match(str, float_pattern);
}
