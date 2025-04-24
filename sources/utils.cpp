#include "longtrip.h"

bool	isInteger(const string &str)
{
	size_t	i;

	i = 0;
	if (str.empty())
	{
		return (false);
	}
	while (isspace(str[i]))
	{
		i++;
	}
	if (i >= str.size() || !isdigit(str[i]))
	{
		return (false);
	}
	while (i < str.size() && isdigit(str[i]))
	{
		i++;
	}
	while (str[i] && isspace(str[i]))
	{
		i++;
	}
	return (i == str.size());
}

bool	isFloat(const string &str)
{
	size_t	i;

	i = 0;
	if (str.empty())
	{
		return (false);
	}
	while (str[i] && isspace(str[i]))
	{
		i++;
	}
	if (i >= str.size() || !isdigit(str[i]))
	{
		return (false);
	}
	while (str[i] && isdigit(str[i]))
	{
		i++;
	}
	if (i < str.size() && str[i] == '.')
	{
		i++;
		if (i >= str.size() || !isdigit(str[i]))
		{
			return (false);
		}
		while (i < str.size() && isdigit(str[i]))
		{
			i++;
		}
	}
	while (i < str.size() && isspace(str[i]))
	{
		i++;
	}
	return (i == str.size());
}
