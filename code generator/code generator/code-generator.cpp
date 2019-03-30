#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    
    ifstream inputStream("input.txt"); // open the input file
    ofstream outputStream("output.txt");
    
    // check to see if the input worked
    if (!inputStream) { // returns true if something wrong with stream
        cerr << "Could not open input file." << endl;
        exit(1);
    }
    // check to see if the input worked
    if (!outputStream) { // returns true if something wrong with stream
        cerr << "Could not open input file." << endl;
        exit(1);
    }
    
    outputStream << "<input class=\"spoilerbutton\" id=\"watch-details\" type=\"button\" value=\"Show Details\" " << endl;
    outputStream << "onclick=\"this.value=this.value=='Show Details'?'Hide Details':'Show Details';\">" << endl;
    
    outputStream << "<div class=\"spoiler\"><div>" << endl;
    outputStream << "<br> \n" << endl;
    
    
    string line;
    while (getline(inputStream, line)) {
        outputStream << line << "<br>" << endl;
    }
    
    outputStream << "\n</div></div>" << endl;
    
    // close the file stream
    inputStream.close();
    outputStream.close();
    
    
}
