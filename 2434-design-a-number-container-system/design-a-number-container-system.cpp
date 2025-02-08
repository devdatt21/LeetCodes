class NumberContainers {
public:

    map<int, set<int>> mpset;
    map<int,int> mp;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {

        if(mp[index])
        {   
            cout << "hello" << endl;
            int to_del = mp[index];
            mpset[to_del].erase(index);
            if(mpset[to_del].size()==0)
            {
                mpset.erase(to_del);
            }
        }       
        mpset[number].insert(index);
        mp[index]=number;
    }
    
    int find(int number) {

        if(!mpset[number].empty())
        {
            return *mpset[number].begin();
        }

        

        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */