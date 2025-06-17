#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {

    int n = s.size();
    string hourStr = s.substr(0,2);
    int hour = std::stoi( hourStr);
    if (s[n-2]=='P' && hour<12) {
        hour+=12 ;
        hourStr = to_string(hour);
    }
    if (s[n-2]=='A' && hour==12) {
        hourStr = "00";
    }
    s = hourStr.append(s.substr(2,n-4));
    
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
