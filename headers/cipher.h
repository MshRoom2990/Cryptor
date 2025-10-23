//
//  cipher.h
//  Cryptor
//
//  Created by MshRoom2290 on 10/23/25.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace cipher {
void msh_cipher(const std::string& data_entry, char key) {
    std::stringstream ss;
    
    for (char c : data_entry) {
        /* First, convert each character to its unicode form */
        int c_point = static_cast<unsigned char>(c);
        
        /* Seprate the numbers with a "/" */
        ss << c_point << "/";
    }
    
    /* Now, throw that into a XOR encoder */
    for (auto& byte : ss.str()) {
        // XOR each byte with the key
        byte ^= key;
    }
}
}
