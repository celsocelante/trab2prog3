#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <iterator>


int main()
{
    using namespace std;
    
    ifstream inf("artigos.csv");
 
    if (!inf) {
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }
    
    
    //vector <string> x = split("one:two::three", ':');
    
    /*for(int i = 0; i < x.size(); i++)
      cout << x[i] << endl;*/
    
    string linha;
    string cell;
    vector <string> x;
    getline(inf, linha);
    
    while (inf) {
	x.clear();
        getline(inf, linha);
        //cout << strInput << endl;
	stringstream lineStream(linha);

      while(std::getline(lineStream,cell,';')) {
	x.push_back(cell);
	cout << cell << endl;
      }
      cout << "------" << endl;
    }
 
    return 0;
}