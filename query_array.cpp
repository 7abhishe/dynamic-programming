#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    // Step 1 for the firsrt query and their values stored in it.
    int num_fools;
    cin >> num_fools;
    unordered_map<string, int> counts;
    string fool;
    for (int i = 0; i < num_fools; i++) {
        cin >> fool;
        if (counts.find(fool) == counts.end()) {
            counts[fool] = 0;
        }
        counts[fool]++;
    }

    // Step 2 for the 2nd query stored in the system
    int num_queries;
    cin >> num_queries;
    string query_fool;
    for (int i = 0; i < num_queries; i++) {
        cin >> query_fool;
        if (counts.find(query_fool) != counts.end()) {
            cout << counts[query_fool] << endl;
        } else {
            cout << 0 << endl;
        }
    }

    return 0;
}
