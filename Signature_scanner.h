#ifndef SIGNATURE_SCANNER_H
#define SIGNATURE_SCANNER_H

#include <string>
#include <vector>
#include "help_functions.h"

class Signature_scanner
{
public:
    Signature_scanner(std::vector<char> SIGNATURE = {},
                        std::string filePATH = "")
                    : _SIGNATURE(SIGNATURE),
                      _filePATH(filePATH)
    {}

    auto set_SIGNATURE(std::string sign) -> std::vector<char>;

    auto get_SIGNATURE() -> std::string;

    auto get_SIGNATURE_as_vector() -> std::vector<char>;

    auto set_filePATH(std::string PATH) -> bool;

    auto get_filePATH() -> std::string;

    auto open_file() -> std::vector<char>;

private:
    std::vector<char> _SIGNATURE;
    std::string _filePATH;

};


#endif // SIGNATURE_SCANNER_H
