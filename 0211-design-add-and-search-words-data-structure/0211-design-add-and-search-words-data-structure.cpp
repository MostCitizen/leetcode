class TrieNode{
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children.find(c) == cur->children.end()){
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int start, TrieNode* node){
        TrieNode* cur = node;
        for(int i=start; i<word.size();i++){
            if(word[i] == '.'){
                for(auto [c, childNode] : cur->children){
                    if(childNode && dfs(word, i+1, childNode)){
                        return true;
                    }
                }
                return false;
            }else {
                if(cur->children.find(word[i]) == cur->children.end()){
                    return false;
                }
                cur = cur->children[word[i]];
            }
        }
        return cur->isEnd;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */