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

	return ((text_number + key_number) % 26 + 'A');
}

char	letter_decrypter(char text, char key)
{
	int	text_number = text - 'A';
	int key_number = key - 'A';

	return ((text_number - key_number + 26) % 26 + 'A');
}

std::string	cipher(std::string plaintext, std::string key)
{
	std::string result;

	if (!strIsUpper(plaintext) || !strIsUpper(key))
	{
		std::cerr << "Ensure that both text and key only contain capital letters" << std::endl;
		return "";
	}

	if (key.length() < plaintext.length())
	{
		std::cerr << "Ensure that the key length is greater than or equal to the length of the text" << std::endl;
		return "";
	}

	for (int i = 0; i < plaintext.length(); ++i)
	{
		result.push_back(letter_encrypter(plaintext[i], key[i]));
	}

	return (result);
}

std::string	decipher(std::string plaintext, std::string key)
{
	std::string	result;

	if (!strIsUpper(plaintext) || !strIsUpper(key))
	{
		std::cerr << "Ensure that both text and key only contain capital letters" << std::endl;
		return "";
	}

	if (key.length() < plaintext.length())
	{
		std::cerr << "Ensure that the key length is greater than or equal to the length of the text" << std::endl;
		return "";
	}

	for (int i = 0; i < plaintext.length(); ++i)
	{
		result.push_back(letter_decrypter(plaintext[i], key[i]));
	}

	return (result);
}

int	main()
{
	std::cout << std::endl << "--- Testing cipher(\"ANGELLINE\", \"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM\") ---" << std::endl;
	std::string	cipher_result = cipher("ANGELLINE", "THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM");
	std::cout << "Result: " << cipher_result << std::endl;

	std::cout << std::endl << "--- Testing decipher((result of cipher function), \"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM\") ---" << std::endl;
	std::cout << "Result: " << decipher(cipher_result, "THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM") << std::endl;
}
