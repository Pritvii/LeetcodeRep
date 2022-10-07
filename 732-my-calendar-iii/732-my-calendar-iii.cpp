class MyCalendarThree {
    map<int, int> interval;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int curr = 0, ans = 0;
        interval[start]++;
        interval[end]--;
        for (auto& [_, delta] : interval) {
            curr += delta;
            ans = max(ans, curr);
        }
        return ans;
    }
};