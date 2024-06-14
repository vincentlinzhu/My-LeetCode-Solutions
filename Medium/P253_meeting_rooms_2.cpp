/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

int minMeetingRooms(vector<Interval> &intervals) {
    // Write your code here
    sort(intervals.begin(), intervals.end());
    priority_queue <int, vector<int>, greater<int>> pq;

    pq.push(intervals[0].end);
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].start >= pq.top()) {
            pq.pop();
            pq.push(intervals[i].end);
        } else {
            pq.push(intervals[i].end);
        }
    }

    return pq.size();
}