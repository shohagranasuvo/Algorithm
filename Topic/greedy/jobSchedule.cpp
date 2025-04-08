#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  
    static bool cmp(tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<1>(a) < get<1>(b);  
    }

    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        vector<tuple<int, int, int>> meetings;

        
        for (int i = 0; i < N; i++) {
            meetings.push_back(make_tuple(S[i], F[i], i + 1)); 
        }

      
        sort(meetings.begin(), meetings.end(), cmp);

        vector<int> ans;
        int lastFinishTime = get<1>(meetings[0]);
        ans.push_back(get<2>(meetings[0])); 

       
        for (int i = 1; i < N; i++) {
            if (get<0>(meetings[i]) > lastFinishTime) { 
                ans.push_back(get<2>(meetings[i]));
                lastFinishTime = get<1>(meetings[i]);
            }
        }

    
        sort(ans.begin(), ans.end());

        return ans;
    }
};


int main() {
    int N;
    cin >> N;

    vector<int> S(N), F(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    for (int i = 0; i < N; i++) cin >> F[i];

    Solution obj;
    vector<int> result = obj.maxMeetings(N, S, F);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
