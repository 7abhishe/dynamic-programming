#include <iostream>
#include <fstream>
using namespace std;

int countAsterisks(string filename){
    int count = 0;
    ifstream file(filename);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            for(char c : line){
                if(c == '*'){
                    count++;
                }
            }
        }
        file.close();
    }
    return count;
}

int main(){
    string filename = "test.cpp";
    int count = countAsterisks(filename);
    cout << "Number of asterisks: " << count << endl;
    return 0;
}
