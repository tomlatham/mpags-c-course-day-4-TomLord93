#ifndef MPAGSCIPHER_CIPHERTYPE_HPP
#define MPAGSCIPHER_CIPHERTYPE_HPP

/**
 * \file CipherType.hpp
 * \brief Contains the declaration of the CipherType enumeration
 */

/**
 * \enum CipherType
 * \brief Enumeration to define the modes in which the cipher can operate
 */
enum class CipherType {
  Caesar, ///< Apply Caesar cipher
  Playfair ///< Apply Playfair cipher
};

#endif // MPAGSCIPHER_CIPHERTYPE_HPP 
