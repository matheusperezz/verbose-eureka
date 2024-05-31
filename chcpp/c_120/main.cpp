#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){

  string line;
  vector<string> lines;
  
  getline(cin, line);
  istringstream stream(line);
  string word;
  while (stream >> word){
    lines.push_back(word);
  }

  for (const string& w: lines){
    cout << w << " ";
  }
  cout << endl;

  cout << "Testing the print" << endl;
  cout << "Windows printing fine" << endl;
  return 0;
}
