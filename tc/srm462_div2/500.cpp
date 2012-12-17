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


bool eq(double a, double b){
    if( fabs(a-b)<1e-10){
        return true;
    }
    return false;
}


bool check(string candlesLine){
    for(int i=0; i<candlesLine.size()-1; i++){
        if(candlesLine[i]=='1')return false;
    }
    return true;
}


class AgeEncoding {
    public:
        double getRadix(int age, string candlesLine) {
            double low = 0.0, high = double(age);
            if(age == candlesLine[candlesLine.size()-1]-'0' && check(candlesLine)){
                return -2;
            }
            if(age==1 && candlesLine[candlesLine.size()-1]=='1'){
                return -1;
            }

            double ans = -1;
            while(low<high){
                double tmp = 0;
                double mid = low + (high-low)/2.0;
                cout<<"cur mid "<<mid<<endl;
                int n = candlesLine.size() - 1;
                for(int i=0; i<candlesLine.size(); i++, n--){
                    tmp = tmp + (candlesLine[i]-'0')*pow(mid,n); 
                }
                cout<<"tmp is "<< tmp<<endl;
                if( eq(tmp, double (age) )){
                    ans = mid;
                    break;
                }else if(tmp>age){
                    high = mid;
                }else{
                    low = mid;
                }
            }
            if(ans==-1 || eq(ans, 0.0)){
                return -1;
            }
            return ans;
        }

};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, string p1, bool hasAnswer, double p2) {
    cout << "Test " << testNum << ": [" << p0 << "," << "\"" << p1 << "\"";
    cout << "]" << endl;
    AgeEncoding *obj;
    double answer;
    obj = new AgeEncoding();
    clock_t startTime = clock();
    answer = obj->getRadix(p0, p1);
    clock_t endTime = clock();
    delete obj;
    bool res;
    res = true;
    cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
    if (hasAnswer) {
        cout << "Desired answer:" << endl;
        cout << "\t" << p2 << endl;
    }
    cout << "Your answer:" << endl;
    cout << "\t" << answer << endl;
    if (hasAnswer) {
        res = fabs(p2 - answer) <= 1e-9 * max(1.0, fabs(p2));
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

    int p0;
    string p1;
    double p2;

    {
        // ----- test 0 -----
        p0 = 1;
        p1 = "0000000001";
        p2 = -2.0;
        all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 1 -----
        p0 = 1;
        p1 = "11";
        p2 = -1.0;
        all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 2 -----
        p0 = 1;
        p1 = "1000000000000000001";
        p2 = -1.0;
        all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 3 -----
        p0 = 21;
        p1 = "10111111110111101111111100111111110111111111111100";
        p2 = 0.9685012944510603;
        all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 4 -----
        p0 = 16;
        p1 = "1";
        p2 = -1.0;
        all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 5 -----
        p0 = 1;
        p1 = "1";
        p2 = -2.0;
        all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
        // ------------------
    }

    {
        // ----- test 6 -----
        p0 = 1;
        p1 = "001000";
        p2 = 1.0;
        all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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