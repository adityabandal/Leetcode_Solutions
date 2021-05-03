class Solution {
public:
    static bool comp(const vector<int>& a, const vector<int>& b){
        // if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), comp);
        int t = 0;
        int ans = 0;
        for(int i=0;i<courses.size();i++){
            auto c = courses[i];
            if(t+c[0]<=c[1]){
                courses[ans++] = c;
                t+=c[0];
            }
            else{
                int maxi = i;
                for(int j=0;j<ans;j++){
                    if(courses[j][0]>courses[maxi][0]){
                        maxi=j;
                    }
                }
                t+=courses[i][0]-courses[maxi][0];
                courses[maxi]=c;
            }
        }
        return ans;
    }
};