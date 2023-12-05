#include "algorithm.hpp"

vector<string> searchAlgorithm(string line, regex expression)
{
   vector<string> result;
   sregex_iterator expressionIterator(line.begin(), line.end(), expression);
   sregex_iterator end;

   // search input string for input regex
   while(expressionIterator != end)
   {
      for(unsigned int i = 0; i < expressionIterator->size(); ++i)
         { result.push_back((*expressionIterator)[i]); }

      ++expressionIterator;
   }

   return result;
}
