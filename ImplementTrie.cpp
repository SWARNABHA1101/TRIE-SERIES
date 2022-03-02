/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */
  struct Node{
      Node * links[26];
      bool flag=false;
      
      bool conatainsKey(char ch){
          return (links[ch-'a']!=NULL);
      }
      void put(char ch, Node * node){
          links[ch-'a']=node;
      }
      Node * get(char ch){
          return links[ch-'a'];
      }
      bool setEnd(){
          flag=true;
      }
      bool isEnd(){
          return flag;
      }
  };

class Trie {
private:
    Node * root;
public:

    /** Initialize your data structure here. */
    //TC-> O(len(words))
    Trie() {
         root=new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string words) {
   Node * node=root;
        for(int i = 0;i<words.size();i++) {
            if(!node->conatainsKey(words[i])) {
                node->put(words[i],new Node());
            }
            //moves to reference trie
            node=node->get(words[i]);
        }
        node->setEnd();
    }

    /** Returns if the word is in the trie. */
    //O(len)
    bool search(string words) {
     Node * node=root;
        for(int i=0;i<words.length();++i){
            if(!node->conatainsKey(words[i])){
                return false;
            }
            node=node->get(words[i]);
        }
        if(node->isEnd()){
            return true;
        }
        return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    //O(len)
    bool startsWith(string prefix) {
        Node * node=root;
        for(int i=0;i<prefix.length();++i){
             if(!node->conatainsKey(prefix[i])){
                return false;
            }
            node=node->get(prefix[i]);
        }
        return true;
    }
};
