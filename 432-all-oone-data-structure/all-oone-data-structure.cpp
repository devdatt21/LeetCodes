class AllOne {
public:

    unordered_map<string, int> keyCnt;
    set<pair<int, string>> keyCntCnt;

    AllOne() {
        keyCnt.clear();
    }
    
    void inc(string key) {
        int cnt = keyCnt[key];
        keyCnt[key]++;
        keyCntCnt.erase({cnt, key});
        keyCntCnt.insert({cnt+1, key});

    }
    
    void dec(string key) {
        int cnt = keyCnt[key];
        keyCnt[key]--;

        keyCntCnt.erase({cnt,key});
        if(keyCnt[key]==0) 
        {
            keyCnt.erase(key);
        }
        else
        {
            keyCntCnt.insert({cnt-1,key});
        }
    }
    
    string getMaxKey() {
        if(!keyCntCnt.empty()) return keyCntCnt.rbegin()->second;
        else return "";
    }
    
    string getMinKey() {
        if(!keyCntCnt.empty()) return keyCntCnt.begin()->second;
        else return "";
        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */