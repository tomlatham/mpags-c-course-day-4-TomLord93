#ifndef MPAGSCIPHER_PLAYFAIRCIPHER_HPP
#define MPAGSCIPHER_PLAYFAIRCIPHER_HPP

// Standard library includes
#include <string>
#include <vector>

// Our project headers
#include "CipherMode.hpp"

/**
 * \file PlayfairCipher.hpp
 * \brief Contains the declaration of the PlayfairCipher class
 */

/**
 * \class PlayfairCipher
 * \brief Encrypt or decrypt text using the Playfair cipher with the given key
 */
class PlayfairCipher {
  public:
    /**
     * Create a new PlayfairCipher with the given key
     *
     * \param key the key to use in the cipher
     */
    PlayfairCipher( const std::string& key );

    /**
     * Apply the cipher to the provided text
     *
     * \param inputText the text to encrypt or decrypt
     * \param cipherMode whether to encrypt or decrypt the input text
     * \return the result of applying the cipher to the input text
     */
    std::string applyCipher( const std::string& inputText, const CipherMode cipherMode ) const;
    void setKey(const std::string& key); 

  private:
    /// The alphabet - used to determine the cipher character given the plain character and the key
    const std::string alphabet_ = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};

    /// The size of the alphabet
    const std::vector<char>::size_type alphabetSize_ = alphabet_.size();

    /// The cipher key, essentially a constant shift to be applied
    std::string key_ = "";
};

#endif
