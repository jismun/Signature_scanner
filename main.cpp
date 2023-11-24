#include <iostream>
#include <fstream>
#include "Signature_scanner.h"

#define filePATH "/home/jismun/myDir/EDU/Fe/bios.bin"

int main()
{


    Signature_scanner scan;
    scan.set_filePATH(filePATH);
    std::cout << scan.get_filePATH() << std::endl;
    std::vector<char> filePlot = scan.open_file();


    std::string sign;
    std::cout << "SIGNATURE: " << std::endl;
    std::cin >> sign;
    scan.set_SIGNATURE(sign);
    std::cout << "SIGNATURE IS " << scan.get_SIGNATURE() << std::endl;


    if ( ( filePlot.size() - sign.size() ) < 0 ) {
        std::cout << "There's no SIGNATURES" << std::endl;
        return 0;
    }

    std::vector<int> addresses ;

//    std::cout << std::hex << filePlot.at(0x28) << std::endl;
//    std::cout << sign.size() << std::endl;
//    std::cout << scan.get_SIGNATURE_as_vector().at(1) << std::endl;


    int count;
    for (size_t i = 0; i < filePlot.size()-sign.size()+1; ++i) {
        count = 0;
        for (size_t j = 0; j < sign.size(); ++j) {
            if (filePlot.at(i+j) == scan.get_SIGNATURE_as_vector().at(j)) {
                ++count;
            } else break;
        }
        if (count == sign.size()) {
            addresses.push_back(i);
        }
    }

    for (size_t i = 0; i < addresses.size(); ++i) {
        std::cout << std::hex << addresses.at(i) << std::endl;
    }

    return 0;
}
