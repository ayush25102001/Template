//Below Data Structure has a getMeadin() function that can be used to find Rolling median of subarray of particular length in an array by appropriatly sliding the array and inserting required elements
class DS {
    public:
        multiset<int> s1;
        multiset<int> s2;
        void insert(int num) {
            if(s1.size() == 0) {
                s1.insert(num);
                return;
            }
            if(num < *(--s1.end())) {
                s1.insert(num);
            }
            else {
                s2.insert(num);
            }
            while(s1.size() > s2.size()) {
                s2.insert(*(--s1.end()));
                s1.erase(*(--s1.end()));
            }
            while(s2.size() > s1.size()) {
                s1.insert(*(s2.begin()));
                s2.erase(*(s2.begin()));
            }
        }
        int getMedian() {
            return *(--s1.end());
        }
};
