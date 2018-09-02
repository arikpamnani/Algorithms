#ifndef TRIE_H
#define TRIE_H

#include <string>
#include <unordered_map>

class Node {
    private:
        int prefixes;
        int words;
        std::unordered_map <char, Node*> edges;

    public:
        Node();
        void addWord(std::string word);
        int getPrefixes(std::string word);
        int getWords(std::string prefix);
};

#endif
