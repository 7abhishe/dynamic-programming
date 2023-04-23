#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> getFactors(int n) {
    vector<int> factors;
    for(int i=1;i<=n;i++){
        if(n % i == 0){
            factors.push_back(i);
        }
    }
    return factors;
}

int getNumCommonFactors(int a, int b) {
    unordered_map<int, int> factorCounts;
    vector<int> factorsA = getFactors(a);
    vector<int> factorsB = getFactors(b);
    for(int i=0;i<factorsA.size();i++){
        factorCounts[factorsA[i]]++;
    }
    int numCommonFactors = 0;
    for(int i=0;i<factorsB.size();i++){
        if(factorCounts.find(factorsB[i]) != factorCounts.end()){
            numCommonFactors++;
        }
    }
    return numCommonFactors;
}

int main() {
    int a = 12;
    int b = 18;
    int numCommonFactors = getNumCommonFactors(a, b);
    cout << "Number of common factors between " << a << " and " << b << ": " << numCommonFactors << endl;
    return 0;
}
