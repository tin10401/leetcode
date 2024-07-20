class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
       auto getAngle = [&](vector<int>& p)
       {
            double dx = p[0] - location[0], dy = p[1] - location[1];
            double a = atan2(dy, dx);
            double angleDegree = a * 180.0 / M_PI;
            return angleDegree;
       };
       vector<double> list;
       int curr = 0;
       for(auto& p : points)
       {
        if(p == location) curr++;
        else list.push_back(getAngle(p));
       } 
       int n = list.size();
       sort(begin(list), end(list));
       for(int i = 0; i < n; i++) list.push_back(list[i] + 360.0);
       int res = curr;
       for(int left = 0, right = 0; right < list.size(); right++)
       {
            while(abs(list[right] - list[left]) > angle) left++; 
            res = max(res, curr + right - left + 1);
       }
       return res;
    }
};