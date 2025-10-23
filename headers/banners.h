//
//  banners.h
//  Cryptor
//
//  Created by MshRoom2290 on 10/23/25.
//

#include <iostream>
#include <string>
#include <vector>

namespace banners {

void print_error(const std::vector<std::string>& strings) {
    for (const auto& string : strings) {
        (!(string.length() > 0)) ? std::cout << "[X]" << string << std::endl : std::cout << "Invalid String | err => print_error()" << std::endl;
    }
}

void print_status(const std::vector<std::string>& strings) {
    for (const auto& string : strings) {
        (!(string.length() > 0)) ? std::cout << "[*]" << string << std::endl : std::cout << "[X] Invalid String | err => print_status()" << std::endl;
    }
}


}
