#pragma once

#include <iostream>
#include <map>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>
#include <algorithm>

void FileWrite(std::string, const std::vector<int> &, std::string, std::ios_base::openmode);

bool IsTooth(const std::vector<int> &, int);

int SumTeeth(const std::vector<int> &);

int Height(const std::vector<int> &);

unsigned int IndexOfKThItemNotTooth(const std::vector<int> &, int);

unsigned int IndexTheLastKThItemNotTooth(const std::vector<int> &);

std::vector<int> FileRead(std::string);