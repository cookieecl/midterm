#include <iostream>
#include <string>

bool	strIsUpper(std::string str)
{
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (false);
	}
	return (true);
}

char	letter_encrypter(char text, char key)
{
	int		text_number = text - 'A';
	int 	key_number = key - 'A';
	int 	result_number = text_number + key_number;
	int		mod_result_number = result_number % 26;
	char	result = mod_result_number + 'A';

	// std::cout << "text: " << text << "(" << text_number << ")";
	// std::cout << ", key: " << key << "(" << key_number << ")";
	// std::cout << ", result: " << result_number << " % 26 = " << result << "(" << mod_result_number << ")" << std::endl;

	return (result_number % 26 + 'A');
}

std::string	cipher(std::string plaintext, std::string key)
{
	std::string result;

	if (!strIsUpper(plaintext) || !strIsUpper(key))
	{
		std::cerr << "Ensure that both text and key only contain capital letters" << std::endl;
		return 0;
	}

	if (key.length() < plaintext.length())
	{
		std::cerr << "Ensure that the key length is greater than or equal to the length of the text" << std::endl;
		return 0;
	}

	for (int i = 0; i < plaintext.length(); ++i)
	{
		result.push_back(letter_encrypter(plaintext[i], key[i]));
	}

	return (result);
}

int	main()
{
	std::cout << "/// Testing cipher(\"ANGELLINE\", \"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM\") ///" << std::endl;
	std::cout << "Result: " << cipher("ANGELLINE", "THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM") << std::endl;
}
