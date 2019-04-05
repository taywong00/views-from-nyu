#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void watchContentDetails(ifstream& inputStream, ofstream& outputStream) {
    
    
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
    
    outputStream << "<style> a { color: white; } </style>" << endl;
    
    outputStream << "<input class=\"spoilerbutton\" id=\"watch-details\" type=\"button\" value=\"Show Details\" "
    << "onclick=\"this.value=this.value=='Show Details'?'Hide Details':'Show Details';\">" << endl;
    
    outputStream << endl;
    
    outputStream << "<div class=\"spoiler\"><div>" << endl;
    outputStream << "<br> \n" << endl;
    
    
    string line;
    while (getline(inputStream, line)) {
        int linkInd = static_cast<int>(line.find("http"));
        if (0 <= linkInd && linkInd < line.length()) {
            cout << line << endl;
            string socialName = line.substr(0, linkInd);
            string link = line.substr(linkInd);
            
            outputStream << socialName
            << "<a href=\"" << link << "\"> " << link << " </a> <br>" << endl;
        }
        else {
            outputStream << line << "<br>" << endl;
        }
    }
    
    outputStream << "\n</div></div>" << endl;
    
}

int main() {
    
    ifstream inputStream("input.txt"); // open the input file
    ofstream outputStream("output.txt");
    
    watchContentDetails(inputStream, outputStream);
    
    // close the file stream
    inputStream.close();
    outputStream.close();
    
}
