#include "trie.h"
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

Node::Node() {
    prefixes = 0;
    words = 0;
}

void Node::addWord(string word) {
    if(word.size() == 0) {
        this->prefixes ++;
        this->words ++;
        return;
    }
    else {
        this->prefixes ++;
    }
    char first = word[0];
    if(this->edges.find(first)==this->edges.end())
        this->edges[first] = new Node();
    word.erase(0, 1);
    this->edges[first]->addWord(word);
}

int Node::getWords(string word) {
    if(word.size() == 0) {
        return this->words;
    }
    char first = word[0];
    unordered_map<char, Node*>::iterator it = this->edges.find(first);
    if(it == this->edges.end()) {
        return 0;
    }
    word.erase(0, 1);
    return it->second->getWords(word);
}

int Node::getPrefixes(string prefix) {
    if(prefix.size() == 0) {
        return this->prefixes;
    }
    char first = prefix[0];
    unordered_map<char, Node*>::iterator it = this->edges.find(first);
    if(it == this->edges.end()) {
        return 0;
    }
    prefix.erase(0, 1);
    return it->second->getPrefixes(prefix);
}

int main() {
    Node* root=new Node();
    int n;
    cin>>n;
    for(int i=0; i<n; i++) {
        string query, str;
        cin>>query>>str;
        if(query == "add")
            root->addWord(str);
        else
            cout<<root->getPrefixes(str)<<"\n";
    }
    return 0;
}
