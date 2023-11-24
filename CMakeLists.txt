cmake_minimum_required(VERSION 3.5)

project(Signature_scanner LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Signature_scanner main.cpp
	Signature_scanner.h
	scanner.cpp
	help_functions.h)

include(GNUInstallDirs)
install(TARGETS Signature_scanner
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
