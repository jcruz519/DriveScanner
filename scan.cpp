#include <string>
#include <iostream>
#include "algorithm.hpp"

static const string THIS_DEV = "./scanDebug";
static const string THIS_PROD = "./scan";

int main()
{
   // scan for file paths
   FILE * pathStream = popen("tree -if .", "r");
   
   // record file names
   char * filePtr = 0;
   size_t len;

   // string of read characters to process an algorithm on
   string read = "";
   
   // algorithm to use (only 2 for the purpose of this assignment)
   vector<regex> expressions;
   expressions.push_back(SS_NUMBER);
   expressions.push_back(CC_NUMBER);

   // open each file to read
   while(getline(&filePtr, &len, pathStream) != -1)
   {
      string fileName = regex_replace(filePtr, regex("\\n"), "");
      
      // skip the drive scanner itself
      if(fileName == THIS_DEV || fileName == THIS_PROD) { continue; }

      ifstream file(fileName);

      if(file.is_open())
      {
         string line;

         // exptract file contents
         while(getline(file, line)) { read += line; }
         file.close();
      }
   }

   ofstream report("ScanReport.txt");

   // find regex based on algorithm being used
   for(regex expression : expressions)
   {
      vector<string> results = searchAlgorithm(read, expression);

      for(string result : results) 
      {
         if(report.is_open()) { report << result << endl; }
         cout << result << endl;
      }

      cout << endl;
   }

   report.close();
   
   return 0;
}
