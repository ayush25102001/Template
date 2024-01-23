//Below Data Structure has a getMeadin() function that can be used to find Rolling median of subarray of particular length in an array by appropriatly sliding the array and inserting required elements
class DS {
    public:
        //Use unordered set in case of duplicates
        set<int> s1;
        set<int> s2;
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
            if( (s1.size() == s2.size()) || (s1.size() == (s2.size() + 1)) ) {
                return;
            }
            if(s1.size() > s2.size()) {
                if((s1.size() + s2.size())%2 == 0) {
                    while(s1.size() != s2.size()) {
                        s2.insert(*(--s1.end()));
                        s1.erase(*(--s1.end()));
                    }
                    return;
                }
                if((s1.size() + s2.size())%2 == 1) {
                    while(s1.size() != s2.size()+1) {
                        s2.insert(*(--s1.end()));
                        s1.erase(*(--s1.end()));
                    }
                    return;
                }
            }
            else {
                if((s1.size() + s2.size())%2 == 0) {
                    while(s1.size() != s2.size()) {
                        s1.insert(*(s2.begin()));
                        s2.erase(*(s2.begin()));
                    }
                    return;
                }
                if((s1.size() + s2.size())%2 == 1) {
                    while(s1.size() != s2.size()+1) {
                        s1.insert(*(s2.begin()));
                        s2.erase(*(s2.begin()));
                    }
                    return;
                }
            }
            
        }
        int getMedian() {
            return *(--s1.end());
        }
};
