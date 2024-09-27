

class MyCalendarTwo {

public:

    vector<pair<int,int>> overLap;
    vector<pair<int,int>> nonOverLap;

    MyCalendarTwo() {

    }
    
    
    bool book(int start, int end) {
        
        for(auto i : overLap)
        {
            if(start < i.second && end > i.first)
            {
                return false;
            }
        }

        for(auto i : nonOverLap)
        {
            if(start < i.second && end > i.first)
            {
                overLap.push_back({max(start,i.first),min(end,i.second)});
            }
        }

        
        nonOverLap.push_back({start, end});
        return true;

    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */