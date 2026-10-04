class Solution {
public:
    string decodeString(string s) {

        stack<int> numStack;
        stack<string> stringStack;

        string current = "";
        int num = 0;

        for(char c : s) {

            // 1. Number
            if(isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            // 2. Opening bracket
            else if(c == '[') {
                numStack.push(num);
                stringStack.push(current);

                num = 0;
                current = "";
            }

            // 3. Closing bracket
            else if(c == ']') {

                int repeat = numStack.top();
                numStack.pop();

                string previous = stringStack.top();
                stringStack.pop();

                string temp = "";

                for(int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = previous + temp;
            }

            // 4. Normal character
            else {
                current += c;
            }
        }

        return current;
    }
};