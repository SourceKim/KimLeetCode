#include <iostream>
#include <string>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    string reverver(string input) {
        int len = input.size();

        string output = "";

        stack<char> st;

        for (int i=0; i<len; i++) {

            if (input[i] == ' ' || input[i] == '\0') {
                while (!st.empty()) {
                    char c = st.top();
                    output += c;
                    st.pop();
                }

                output += ' ';
            } else {
                st.push(input[i]);
            }
        }
       output += '\0'; 
        // while (!st.empty()) {
        //     char c = st.top();
        //     output += c;
        //     st.pop();
        // }

        return output;
   };
};


using namespace std;
int main() {
    //int a;
    //cin >> a;
    Solution *sol = new Solution();
    string out = sol->reverver("i am a student");
    cout << out << endl;
}