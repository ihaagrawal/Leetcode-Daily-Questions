// 731. My Calendar II (MEDIUM)
// https://leetcode.com/problems/my-calendar-ii/description/?envType=daily-question&envId=2024-09-27


class MyCalendarTwo {
public:
    vector<pair<int,int>> bookings;
    MyCalendarTwo() {}

    bool book(int start, int end) {
        for(auto &event : bookings) {
            int existingStart = event.first, existingEnd = event.second;

            if((start < existingEnd) and (end > existingStart)) {
                int overlapStart = max(existingStart, start);
                int overlapEnd = min(existingEnd, end);

                if(isTripleBooked(overlapStart, overlapEnd)) {
                    return false;
                }
            }
        }

        bookings.push_back({start, end});
        return true;
    }

    bool isTripleBooked(int start, int end) {
        int overlapCount = 0;

        for(int i = 0; i < bookings.size(); i++) {
            int existingStart = bookings[i].first, existingEnd = bookings[i].second;

            if((start < existingEnd) and (end > existingStart)) {
                overlapCount++;
                if(overlapCount == 2) {
                    return true;
                }
            }
        }

        return false;
    }
};
