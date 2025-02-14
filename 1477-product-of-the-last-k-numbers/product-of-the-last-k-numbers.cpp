class ProductOfNumbers {
public:
    vector<int> vec;
    int sum = 0;

    ProductOfNumbers() {}

    void add(int num) {
        if (vec.size() == 0) {
            vec.push_back(num);
        } 
        else {
            for (int i = 0; i < vec.size(); i++) {
                vec[i] = vec[i] * num;
            }
            vec.push_back(num);
        }
    }

    int getProduct(int k) {
        return vec[vec.size()-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
