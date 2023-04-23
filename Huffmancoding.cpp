#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
public:
    char data;
    int freq;
    Node* left;
    Node* right;
    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

struct CompareNodes {
    bool operator()(Node* n1, Node* n2) {
        return n1->freq > n2->freq;
    }
};

void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == NULL) {
        return;
    }
    if (!root->left && !root->right) {
        huffmanCode[root->data] = str;
    }
    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void decode(Node* root, int& index, string str) {
    if (root == NULL) {
        return;
    }
    if (!root->left && !root->right) {
        cout << root->data;
        return;
    }
    index++;
    if (str[index] == '0') {
        decode(root->left, index, str);
    } else {
        decode(root->right, index, str);
    }
}

void buildHuffmanTree(string text) {
    unordered_map<char, int> freq;
    for (char c : text) {
        freq[c]++;
    }
    priority_queue<Node*, vector<Node*>, CompareNodes> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }
    while (pq.size() > 1) {
        Node* n1 = pq.top();
        pq.pop();
        Node* n2 = pq.top();
        pq.pop();
        Node* n3 = new Node('$', n1->freq + n2->freq);
        n3->left = n1;
        n3->right = n2;
        pq.push(n3);
    }
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);
    cout << "Huffman codes are: " << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << " : " << pair.second << endl;
    }
    cout << "Encoded string is: ";
    string encoded = "";
    for (char c : text) {
        encoded += huffmanCode[c];
    }
    cout << encoded << endl;
    cout << "Decoded string is: ";
    int index = -1;
    while (index < (int)encoded.size() - 2) {
        decode(root, index, encoded);
    }
    cout << endl;
}

int main() {
    string text = "hello world";
    buildHuffmanTree(text);
    return 0;
}
