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

namespace cryptor {
    
namespace fs = std::filesystem;

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
    
    
    /* Encrypt the file using MSH cipher */
    
    
    /* Open the same file for writing */
    
    
    /* Write the encrypted data back into the file */
}

// Function to recursively recurse through the defined directory


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
    
};

#endif
