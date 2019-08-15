class Trie{
public:
    unordered_map<char,Trie*> m;
    bool isTerminal;
    Trie(){
        m.clear();
        isTerminal=false;
    }
};

void insert(Trie *node,string s){
    Trie *t=node;
    for(int i=0;s[i];i++){
        char c=s[i];
        if(t->m.count(c)){
            t=t->m[c];
        }
        else{
            t->m[c]=new Trie();
            t=t->m[c];
        }
    }
    t->isTerminal=true;
}

class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        Trie * root=new Trie();
        int mi=1000000;
        for(int i=0;i<a.size();i++){
            insert(root,a[i]);
            mi=min(mi,(int)a[i].length());
        }
        string s;
        while(s.length()<mi && root && root->m.size()==1){
            char c;
            for(auto i:root->m){
                s.push_back(i.first);
                c=i.first;
            }
            root=root->m[c];
        }
        return s;
    }
};
