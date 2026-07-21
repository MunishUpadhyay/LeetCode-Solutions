class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        long long result = 0;
        int sign = 1;
        stack<int> st;
        
        for(int i = 0; i < n; i++) {
            if(s[i] == ' ')
                continue;

            if(s[i] == '+')
                sign = 1;

            if(s[i] == '-')
                sign = -1;
            
            if(isdigit(s[i])) {
                long long num = 0;

                while(i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }

                result += sign * num;
                
                i--;
            }

            if(s[i] == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            if(s[i] == ')') {
                int prevSign = st.top();
                st.pop();
                long long prevResult = st.top();
                st.pop();

                result = prevResult + prevSign * result; 
            }
        }

        return result;
    }
};