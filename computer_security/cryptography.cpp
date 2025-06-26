#include <iostream>
#include <string>

// Checks if all characters in the string are uppercase letters (A-Z)
bool	strIsUpper(std::string str)
{
	// Loop through all characters in the string to check
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (false); // Return false if the character is not uppercase
	}
	return (true); // Return true if all characters are uppercase
}

// Decrypts a single uppercase character
char	letter_decrypter(char text, char key)
{
	// Convert the character to 0-25 range
	int	text_number = text - 'A';
	int key_number = key - 'A';

	/* Decrypt by subtracting text with key number, 
	adding 26 to ensure that its not a negative number, wrap it in the range of 0-25,
	and convert back to character */
	return ((text_number - key_number + 26) % 26 + 'A');
}

// Encrypts a single uppercase character
char	letter_encrypter(char text, char key)
{
	// Convert the character to 0-25 range
	int		text_number = text - 'A';
	int 	key_number = key - 'A';

	/* Encrypt by adding both text and key, wrap it in the range of 0-25, 
	and convert back to character */
	return ((text_number + key_number) % 26 + 'A');
}


// Encrypts an entire plaintext string using the key
std::string	cipher(std::string plaintext, std::string key)
{
	std::string result;

	// Check if both input strings consist of only uppercase letters
	if (!strIsUpper(plaintext) || !strIsUpper(key))
	{
		std::cerr << "Ensure that both text and key only"
			" contain capital letters" << std::endl;
		return "";
	}

	// Check if key is long enough (must be greater than or equal to the length of the text)
	if (key.length() < plaintext.length())
	{
		std::cerr << "Ensure that the key length is greater"
			" than or equal to the length of the text" << std::endl;
		return "";
	}

	// Encrypt each letter using the corresponding key character and push back to the result string
	for (int i = 0; i < plaintext.length(); ++i)
	{
		result.push_back(letter_encrypter(plaintext[i], key[i]));
	}

	// Return the result
	return (result);
}

// Decrypts an entire ciphertext string using the key
std::string	decipher(std::string plaintext, std::string key)
{
	std::string	result;

	// Check if both input strings consist of only uppercase letters
	if (!strIsUpper(plaintext) || !strIsUpper(key))
	{
		std::cerr << "Ensure that both text and key only "
			<< "contain capital letters" << std::endl;
		return "";
	}

	// Check if key is long enough (must be greater than or equal to the length of the text)
	if (key.length() < plaintext.length())
	{
		std::cerr << "Ensure that the key length is greater than or equal to the "
			<< "length of the text" << std::endl;
		return "";
	}

	// Decrypt each letter using the corresponding key character and push back to the result string
	for (int i = 0; i < plaintext.length(); ++i)
	{
		result.push_back(letter_decrypter(plaintext[i], key[i]));
	}

	// Return the result
	return (result);
}

// Main function for testing encryption and decryption
int	main()
{
	// Console output statement to note which function is being tested 
	std::cout << std::endl << "--- Testing cipher(\"ANGELLINE\","
		<< " \"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM\") ---" << std::endl;

	/* Encrypt the string "ANGELLINE" using the key "THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM"
	and store it in the variable cipher_result for future use */
	std::string	cipher_result = cipher("ANGELLINE", 
								"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM");
	
	// Print the result
	std::cout << "Result: " << cipher_result << std::endl;

	// Console output statement to note which function is being tested 
	std::cout << std::endl << "--- Testing decipher((result of cipher function),"
		<< "\"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM\") ---" << std::endl;
	
	// Decrypt the result from the cipher to verify that it returns the original
	std::cout << "Result: " << decipher(cipher_result, 
						"THISISANEXAMPLEKEYINCOMPUTERSECURITYEXAM") << std::endl
						<< std::endl;
}
