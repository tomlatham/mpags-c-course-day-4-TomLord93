
// Standard library includes
#include <string>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <map>
#include <utility>
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
	std::cout << key_ << std::endl;

	//Append the alphabet
	key_ += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::cout << key_ << std::endl;

	//Make sure the key is upper case
	//std::string::iterator key_iter = key_.begin();
	std::transform(key_.begin(), key_.end(), key_.begin(), ::toupper);
	std::cout << key_ << std::endl;

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
	int x{0};
	int y{0};
	for (char g : key_) {
	PlayfairCoords coord {std::make_pair(x,y)};
	charLookup_.insert(std::make_pair(g,coord));
	coordLookup_.insert(std::make_pair(coord,g));
	if(x==4){
	y++;
	x=0;
	}
	else if(x==4 && y==4){
	break;
	}
	else{
	x++;
	}
	}
	
	for (auto thing : charLookup_)
	{
	   std::cout<<thing.first<< ": "<<thing.second.first<<":"<<thing.second.second<<std::endl;
	}
	





/*
	for (char g : key_) {
	auto pos{key_.find(g)};
	std::pair< std::string, int > p0{g, pos};
	std::cout << g << std::endl;
	std::cout << p_pos.first << p_pos.second << std::endl;
//	mymap.insert(p_pos);
	}
*//*	
	auto assigncoords = [&] (char f) {
//	int position{iter3 - key_.begin()};
	

// 	long int position{*iter3 - key_.begin()};
	long int position = std::distance(key_.begin(), iter3);
	
	std::cout << f << std::endl;
	std::cout << position << std::endl;


	auto p_position{std::make_pair(f, position)};
//	std::pair< std::string,long int >  p0{f, position};

	mymap.insert( p_position );
	
//	}
	};

	for (auto iter4 = std::begin(key_); iter4!= key_.end(); ++iter4)
	{
	(key_.begin(), key_.end(), assigncoords);
	}
	std::cout << position << std::endl;
*/
/*	using Str2FltMap = std::map<std::string, float>; ///< Create map label
	Str2FltMap mymap; ///< Create map instance
	std::pair<std::string, float> p0{"A", 1.1}; ///< Create coordinate for letter
	auto p1 = std::make_pair("B",2);
	Str2FltMap::value_type p2{"C",3};
	mymap.insert(p0); ///< Insert coordinates into map
	mymap.insert(p1);
	mymap.insert(p2);
	auto iter3 = mymap.find("A"); ///< Find letter with iter
	std::cout<<(*iter3).first << ": "<<(*iter3).second<<std::endl; ///< print to iter something
	for (auto p : mymap)
	{
	   std::cout<<p.first<< ": "<<p.second<<std::endl;
	}
	
	
*/	
	
	//STore the playfair cipher key map

	
}

std::string PlayfairCipher::applyCipher( const std::string& inputText, const CipherMode cipherMode ) const
{
  std::cout << "Cipher coming soon" << std::endl;

	if (cipherMode == CipherMode::Encrypt) {
	std::cout << "Encrypting" <<std::endl;
	}
	
	std::string inputText_ {inputText};
	// Change J -> I
	auto jtoi = [] (char d) {
	if (d == 'J')
	{d = 'I';
	return d;
	}
	else
		return d;
	};
	std::transform(inputText_.begin(), inputText_.end(), inputText_.begin(), jtoi);
	std::cout << inputText_ << std::endl; 


	//If repeated chars in a diagraph add an X or Q if XX
	
	std::vector<char> inputTextvec(inputText_.begin(), inputText_.end());
	for (auto iter = std::begin(inputTextvec); iter != inputTextvec.end(); iter++){
	std::cout << *iter << std::endl;
	}
/*	for ( char h : inputText_ ) {
	if (h == h){
	h+= 'X' + h;
	}
	}
*/
	//If the size of input is odd, add a trailing Z

	//Loop over the input Digraphs

	// 	- Find the coords in the grid for each digraph

	//	- Apply the rules of these coords to get 'new' coords

	// 	- Find the letter associated with the new coords

	// Return the text
	return inputText;
}
