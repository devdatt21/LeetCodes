class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int,int>> bookings;
    
    bool book(int start, int end) {
        
        for(auto i : bookings)
        {
            if(start < i.second && end > i.first)
            {
                return false;
            }
        }

        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */