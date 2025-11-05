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
#include "config.h"

namespace cipher {
void destroy_quick(std::string& data_entry, char key) {
    for (auto& c : data_entry) {
        c ^= key;
    }
}
}
