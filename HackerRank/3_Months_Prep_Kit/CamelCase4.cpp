#include <bits/stdc++.h>
using namespace std;

string caseProblem(string s) {
    char op = s[0];
    char type = s[2];
    s = s.substr(4);
    if (op == 'S' && type == 'M') s.substr(0, s.size() - 2);
    
    int i = 0;
    string out;
    char c;
    while (i < s.size()) {
        c = s[i];
        if (op == 'S') {
            if (i > 0 && isupper(c)) {
                out += ' ';
            }
            if (isupper(c)) c = tolower(c);
            out += c;
        }
        else
        if (op == 'C') {
            if (c == ' ') {
                out += toupper(s[i + 1]);
                i++;
            } else out += c;
        }
        i++;
    }
    
    if (op == 'S') {
        if (isupper(out[0])) out[0] = tolower(out[0]);
        if (type == 'M') out = out.substr(0, out.size() - 2);
    }
    if (op == 'C') {
        if (type == 'C' && islower(out[0])) out[0] = toupper(out[0]);
        if (type == 'M') out += "()";
    }
    
    return out;
}

int main() {
    string data;
    vector<string> vec;
    while(getline(cin, data)) {
        data.erase(remove(data.begin(), data.end(), '\r'), data.end() );
        data.erase(remove(data.begin(), data.end(), '\t'), data.end() );
        data.erase(remove(data.begin(), data.end(), '\n'), data.end() );
        vec.push_back(data);
    }
    for (const auto & e : vec) cout << caseProblem(e) << "\r\n";
    return 0;
}