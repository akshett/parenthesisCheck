#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>


bool parenthesisCheck(const std::string& pattern){
	std::unordered_map<char, char> pairs;
	pairs['}'] = '{';
	pairs[')'] = '(';
	pairs[']'] = '[';

	std::vector<char> open_vec;
	open_vec.push_back('{');
	open_vec.push_back('(');
	open_vec.push_back('[');
	int count = 0;
	std::vector<char> temp;
	
        for (auto str_it = pattern.begin(); str_it < pattern.end(); ++str_it)
	{
		if (std::find(open_vec.begin(), open_vec.end(), *str_it) != open_vec.end())
		{
			temp.push_back(*str_it);
			count++;
		}
		else if(pairs.find(*str_it) != pairs.end())
		{
			if (temp.empty())
				return false;
			if (temp.back() != pairs[*str_it])
				return false;
			else
			{
				temp.pop_back();
				count--;
			}
		}
		if (count < 0)
			return false;
	}
	if (count != 0)
		return false;
	else
		return true;	
}

int main()
{
	std::cout << "Enter a string: " << '\n';
	std::string input_string;
	std::cin >> input_string;
	
	bool parenthesis_result;
	parenthesis_result = parenthesisCheck(input_string);

	if (parenthesis_result)
		std::cout << "Parenthesis fit!" << '\n';
	else
		std::cout << "Wrong parenthesis!!" << '\n';

	return 0;

}
