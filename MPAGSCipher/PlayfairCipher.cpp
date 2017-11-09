
// Standard library includes
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
// Out project headers
#include "PlayfairCipher.hpp"

PlayfairCipher::PlayfairCipher( const std::string& key )
{
 setKey(key);
}

void PlayfairCipher::setKey(const std::string& key) 
{
	//store the original key
	key_ = key;

	//Append the alphabet
	key_ += alphabet_;
//	std::cout << key_ << std::endl;

	//Make sure the key is upper case
	//std::string::iterator key_iter = key_.begin();
	std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);
//	std::cout << key_ << std::endl;
	//Remove non-alpha characters
	auto isntalpha = [] (char c) {
	if (std::isalpha(c)) 
		return false;
	else
		return true;
	}; 
	auto iter = std::remove_if(key_.begin(), key_.end(), isntalpha);
	std::cout << key_ << std::endl;
	key_.erase(iter,key_.end());
	std::cout << key_ << std::endl;
	//Change J -> I
	auto jtoi = [] (char d) {
	if (d == 'J')
	{d = 'I';
	return d;
	}
	else
		return d;
	};
	std::transform(key_.begin(), key_.end(), key_.begin(), jtoi);
	std::cout << key_ << std::endl; 

	//Remove duplicated letters
	std::string encountered;
	auto findduplicates = [&] (char e) {
	if ( encountered.find(e) == std::string::npos )
	{	
		encountered += e;		
		return false;
	}
	else
		return true;
	};
	auto iter2 = std::remove_if(key_.begin(), key_.end(), findduplicates);
	std::cout << key_ << std::endl;
	key_.erase(iter2,key_.end());
	std::cout << key_ << std::endl;

	//Store the coords of each letter

	//STore the playfair cipher key map
}

std::string PlayfairCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
  std::cout << "Cipher coming soon" << std::endl;

	if (cipherMode == CipherMode::Encrypt) {
	std::cout << "Encrypting" <<std::endl;
	}

	// Change J -> I

	//If repeated chars in a diagraph add an X or Q if XX

	//If the size of input is odd, add a trailing Z

	//Loop over the input Digraphs

	// 	- Find the coords in the grid for each digraph

	//	- Apply the rules of these coords to get 'new' coords

	// 	- Find the letter associated with the new coords

	// Return the text
	return inputText;
}
