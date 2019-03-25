cmake_minimum_required(VERSION 3.13)
project(Duomenu_Apdorojimas)

set(CMAKE_CXX_STANDARD 14)

add_executable(Duomenu_Apdorojimas main.cpp MENU.cpp functions.cpp AdditionalFunctions.cpp ValidatesInputs.cpp Globals.h functions.h libraries.h)
