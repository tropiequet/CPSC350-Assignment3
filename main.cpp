/*
Taylor Ropiequet
2349522
ropiequet@chapman.edu
CPSC 350-02
Assignment 3

This is my main file that implements my GenStack template class. It is a Syntax Checker that finds errors
within the given file.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "GenStack.h"

using namespace std;


int main(int argc, char** argv){


  string fileName = argv[1];

  string line;
  char c;
  char checkStack;
  char answer;

  typedef GenStack<char> Stack;

  Stack myStack(128);




  while (true){
    int lineNum = 0;
    bool errorFound = false;
    ifstream infile(fileName);

  //adds open delimeters to stack
    while (infile.good()){
      getline(infile, line);
      lineNum += 1;
      for (int i = 0; i < line.size(); ++i){
        c = line[i];

        if (c == '('){
          myStack.push(c);
        }else if (c == '{'){
          myStack.push(c);
        }else if (c == '['){
          myStack.push(c);
        }else if (c == ')'){
          checkStack = myStack.pop();
          if (checkStack != '('){
            if (checkStack == '{'){
              cout << "Line " << lineNum << ": expected }" << " and found " << c << endl;
            }else if (checkStack == '['){
              cout << "Line " << lineNum << ": expected ]" << " and found " << c << endl;
            }
            errorFound = true;
            break;
          }
        }else if (c == '}'){
          checkStack = myStack.pop();
          if (checkStack != '{'){
            if (checkStack == '('){
              cout << "Line " << lineNum << ": expected )" << " and found " << c << endl;
            }else if (checkStack == '['){
              cout << "Line " << lineNum << ": expected ]" << " and found " << c << endl;
            }
            errorFound = true;
            break;
          }
        }else if (c == ']'){
          checkStack = myStack.pop();
          if (checkStack != '['){
            if (checkStack == '{'){
              cout << "Line " << lineNum << ": expected }" <<" and found " << c << endl;
            }else if (checkStack == '('){
              cout << "Line " << lineNum << ": expected )" << " and found " << c << endl;
            }
            errorFound = true;
            break;
          }
        }
      }
      if (errorFound){
        break;
      }
    }


    if (!errorFound){
      cout << "No errors found! Would you like to process another file? (Y/N)" << endl;
      cin >> answer;

      if (answer == 'Y' || answer == 'y'){
        cout << "What is the name of the file?" << endl;
        cin >> fileName;
      }else if (answer == 'N' || answer == 'n'){
        break;
      }
    }else{
      break;
    }
  }
}
