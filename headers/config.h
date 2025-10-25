#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <vector>

/* Define system path spearators - (System Definitions) */
#if defined(_WIN32) || defined(_WIN64)
    std::string path_sep = "\\";

#else
    std::string path_sep = "/";

#endif

/* Program configuration */
std::vector<std::string> validExtensions = {".pdf", ".doc", ".docx"};
std::vector<std::string> directories     = {path_sep + "Documents", path_sep + "Desktop"};
std::string separator                    = "/";
char key                                 = 0xA2;

#endif
