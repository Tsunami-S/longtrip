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

/* 
 * If 'std::regex' does not compile,
 * (due to compiler or library support issues with C++17),
 * replace with the following implementation. 
 * This might happen in certain environments where
 * 'std::regex' is not fully supported or enabled by default.
 */

//bool	isInteger(const string &str)
//{
//	size_t	i;
//
//	i = 0;
//	if (str.empty())
//	{
//		return (false);
//	}
//	while (isspace(str[i]))
//	{
//		i++;
//	}
//	if (i >= str.size() || !isdigit(str[i]))
//	{
//		return (false);
//	}
//	while (i < str.size() && isdigit(str[i]))
//	{
//		i++;
//	}
//	while (str[i] && isspace(str[i]))
//	{
//		i++;
//	}
//	return (i == str.size());
//}
//
//bool	isFloat(const string &str)
//{
//	size_t	i;
//
//	i = 0;
//	if (str.empty())
//	{
//		return (false);
//	}
//	while (str[i] && isspace(str[i]))
//	{
//		i++;
//	}
//	if (i >= str.size() || !isdigit(str[i]))
//	{
//		return (false);
//	}
//	while (str[i] && isdigit(str[i]))
//	{
//		i++;
//	}
//	if (i < str.size() && str[i] == '.')
//	{
//		i++;
//		if (i >= str.size() || !isdigit(str[i]))
//		{
//			return (false);
//		}
//		while (i < str.size() && isdigit(str[i]))
//		{
//			i++;
//		}
//	}
//	while (i < str.size() && isspace(str[i]))
//	{
//		i++;
//	}
//	return (i == str.size());
//}
