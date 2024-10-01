class CustomStack {
public:

    vector<int> vec;
    int i=-1;
    int maxSizee=0;

    CustomStack(int maxSize) {
        vec = vector<int> (maxSize,-1);
        maxSizee=maxSize;
    }
    
    void push(int x) {

        if((i+1)<maxSizee) vec[++i]=x;
        
    }
    
    int pop() {
        int num=-1;
        if(i>-1 && i<maxSizee)
        {
            num = vec[i];
            vec[i]=-1;
            i--;
        }

        return num;
    }
    
    void increment(int k, int val) {
        
        int j=0;

        if(i>-1)
        {
            while(k--)
            {
                if(j==maxSizee) break; 
                vec[j]+=val;
                j++;
            }
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */