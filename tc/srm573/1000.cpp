#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;



const int MAXN = 51;

int dir[4][2] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
long long int dp[MAXN][MAXN][MAXN];

const int MOD = 1000000007;
class WolfPackDivTwo {
    public:
        int calc(vector <int> x, vector <int> y, int m) {
            memset(dp,0,sizeof(dp));
            int sz = x.size();
            int M = 0;
            for(int i=0; i<sz; i++){
                dp[1][x[i]][y[i]] = 1;
                M = max(M, max(x[i],y[i]));
            }

            for(int step=0; step<=m; step++){
                for(int i=0; i<M; i++){
                    for(int j=0; j<M; j++){
                        for(int k=0; k<4; k++){
                            int nx = i+dir[k][0];
                            int ny = j+dir[k][1];
                            dp[step+1][nx][ny] += dp[step][i][j];
                            dp[step+1][nx][ny]%=MOD;
                        }
                    }
                }
            }

            for(int i=0; i<M; i++){
                for(int j=0; j<M; j++){
                    
                }
            }


        }
};
// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, bool hasAnswer, int p3) {
    cout << "Test " << testNum << ": [" << "{";
    for (int i = 0; int(p0.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p0[i];
    }
    cout << "}" << "," << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
        if (i > 0) {
            cout << ",";
        }
        cout << p1[i];
    }
    cout << "}" << "," << p2;
    cout << "]" << endl;
    WolfPackDivTwo *obj;
    int answer;
    obj = new WolfPackDivTwo();
    clock_t startTime = clock();
    answer = obj->calc(p0, p1, p2);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p3 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = answer == p3;
    }
    if (!res) {
        cout << "DOESN'T MATCH!!!!" << endl;
    } else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
        cout << "FAIL the timeout" << endl;
        res = false;
    } else if (hasAnswer) {
        cout << "Match :-)" << endl;
    } else {
        cout << "OK, but is it right?" << endl;
    }
    cout << "" << endl;
    return res;
}
int main() {
    bool all_right;
    all_right = true;

    vector <int> p0;
    vector <int> p1;
    int p2;
    int p3;

    {
        // ----- test 0 -----
        int t0[] = {3,5};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
        p3 = 1;
        all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        int t0[] = {0,1};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
        p3 = 0;
        all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        int t0[] = {0,2,4};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,0,0};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 2;
        p3 = 4;
        all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        int t0[] = {7,8};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {8,7};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 1;
        p3 = 2;
        all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        int t0[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 12;
        p3 = 0;
        all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        int t0[] = {0,0,0,0,0,0,0,0,0,0,2,2,2,2,2,2,2,2,2,2,4,4,4,4,4,4,4,4,4,4,6,6,6,6,6,6,6,6,6,6,8,8,8,8,8,8,8,8,8,8};
        p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
        int t1[] = {0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18,0,2,4,6,8,10,12,14,16,18};
        p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
        p2 = 31;
        p3 = 573748580;
        all_right = KawigiEdit_RunTest(5, p0, p1, p2, true, p3) && all_right;
        // ------------------
    }

    if (all_right) {
        cout << "You're a stud (at least on the example cases)!" << endl;
    } else {
        cout << "Some of the test cases had errors." << endl;
    }
    return 0;
}
// END KAWIGIEDIT TESTING
