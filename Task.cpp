#include <bits/stdc++.h>
using namespace std;

// TrieNode structure for Trie implementation
struct TrieNode {
    vector<TrieNode*> node;
    bool endOfWord;

    // Constructor to initialize the TrieNode
    TrieNode() {
        for(int i=0; i<26; i++)
            node.push_back(NULL);
        endOfWord = false;
    }
};

// Comparator function to sort strings by size in descending order
bool comp(const string &a, const string &b) {
    return a.size() > b.size();
}

// Trie class for implementing Trie data structure
class Trie {
public:
    TrieNode* head;

    // Constructor to initialize the Trie
    Trie() {
        head = new TrieNode();
    }
    
    // Function to insert a word into the Trie
    void insert(string word) {
        TrieNode* root = head;
        for(char ch : word) {
            if(root->node[ch-'a'] == NULL) {
                root->node[ch-'a'] = new TrieNode();
            }
            root = root->node[ch-'a'];
        }
        root->endOfWord = true;
    }
    
    // Function to search for a word in the Trie
    bool search(string word) {
        TrieNode* root = head;
        for(char ch : word) {
            if(root->node[ch-'a'] == NULL)
                return false;
            root = root->node[ch-'a'];
        }
        return root->endOfWord;
    }

    // Function to check if a word is a compound word
    bool compoundWord(string word) {
        int n = word.size();
        for(int i=1; i<n; i++) {
            string prefix = word.substr(0, i);
            string suffix = word.substr(i);
            if(search(prefix) && (search(suffix) || compoundWord(suffix)))
                return true;
        }
        return false;
    }
};

int main() {
    time_t start, end;
    time(&start);

    // Create a Trie object
    Trie trie;

    // Specify the file path
    string file_path = "E:/Impledge Technologies/Input_02.txt"; // Type Input_01.txt or Input_02.txt //

    // Open the file
    ifstream fin;
    fin.open(file_path);

    // Vector to store words from the file
    vector<string> words;
    string word;

    // Read words from the file and insert them into the Trie
    while(getline(fin, word)) {
        words.push_back(word);
        trie.insert(word);
    }

    // Sort words by size in descending order
    sort(words.begin(), words.end(), comp);

    // Strings to store the longest and second longest compound words
    string longestCompoundWord = "";
    string secondLongestCompoundWord = "";

    // Iterate through the sorted words to find the longest and second longest compound words
    for (string word : words) {
        if (trie.compoundWord(word)) {    
            if (longestCompoundWord.empty()) {     
                longestCompoundWord = word;            
            } 
            else if (secondLongestCompoundWord.empty()) {    
                secondLongestCompoundWord = word;
                break;
            }
        }
    }

    // Record the end time
    time(&end);

    // Calculate the time taken in milliseconds
    double time_taken = double(end - start) * 1000; 

    // Get the filename from the path
    filesystem::path p(file_path);

    // Display the results and time taken
    cout << "Longest Compound Word: " << longestCompoundWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestCompoundWord << endl;
    cout << "Time taken to process file " << p.filename() << ": " << time_taken << " miliseconds" << endl;

    return 0;
}
