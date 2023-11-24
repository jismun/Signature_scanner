#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include "Signature_scanner.h"
#include "help_functions.h"


auto char_to_hex(char c) -> std::string
{

    std::stringstream ss;
    ss << std::hex << static_cast<int>(c);

    return (ss.str());

}

auto vector_to_string(const std::vector<char> vec) -> std::string
{
    std::stringstream ss;
    if (!vec.empty()) {
        for (size_t i = 0; i < vec.size(); ++i) {
            ss << vec.at(i);
        }
        return ss.str();
    }
    return "";
}



auto Signature_scanner::set_SIGNATURE(std::string sign) -> std::vector<char> {
    _SIGNATURE = {};
    for (size_t i = 0; i < sign.size(); ++i) {
        _SIGNATURE.push_back(static_cast<char>(sign[i]));
    }

    return _SIGNATURE;
}

auto Signature_scanner::get_SIGNATURE() -> std::string
{
    if (!_SIGNATURE.empty()) {
        return vector_to_string(_SIGNATURE);
    } else {
        return "SIGNATURE IS NOT DECLARED" ;
    }
}

auto Signature_scanner::get_SIGNATURE_as_vector() -> std::vector<char>
{
    if (!_SIGNATURE.empty()) {
        return _SIGNATURE;
    } else {
        return std::vector<char> {'1'} ;
    }

}

auto Signature_scanner::set_filePATH(std::string PATH) -> bool
{
    if (PATH != "") {
        _filePATH = PATH;
        return true;
    }
    return false;
}

auto Signature_scanner::get_filePATH() -> std::string
{
    return _filePATH;
}

auto Signature_scanner::open_file() -> std::vector<char>
{
    std::ifstream file;
    file.open(_filePATH, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "ERROR" << std::endl;
        file.close();
        return std::vector<char> {1};
    }
    std::vector<char> BUFF(std::istreambuf_iterator<char> (file), {});
    file.close();

    return BUFF;
}


