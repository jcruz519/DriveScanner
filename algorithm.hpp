#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include <regex>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

// Regular expressions for algorithms to determine what to look for
static const regex CC_NUMBER(R"(\d{4}-\d{4}-\d{4})");
static const regex SS_NUMBER(R"(\d{3}-\d{2}-\d{4})");

// Algorithm prototypes
vector<string> searchAlgorithm(string, regex);

#endif
