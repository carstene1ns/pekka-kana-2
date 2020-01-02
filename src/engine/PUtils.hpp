//#########################
//Pekka Kana 2
//by Janne Kivilahti from Piste Gamez (2003)
//#########################
#pragma once

#include "engine/platform.hpp"

#include <vector>
#include <string>

namespace PUtils {

int Setcwd();
void Lower(char* string);
void RemoveSpace(char* string);
bool Find(char *filename);

int  CreateDir(const char *directory);
void Show_Error(const char* txt);

//type:
// ""  - all files and directories
// "/" - directory
// ".exe" - *.exe
std::vector<string> Scandir(const char* type, const char* dir, int max);

void Force_Mobile();
bool Is_Mobile();
int Alphabetical_Compare(const char *a, const char *b);

}