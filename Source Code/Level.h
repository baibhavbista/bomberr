#pragma once
#include <fstream>
#include <vector>
#include <string>

//creates the level
//reads file_name CSV and stores the values in a vector of (vector of ints) Level
void createLevel(std::string file_name, std::vector< std::vector<int> >& Level);
