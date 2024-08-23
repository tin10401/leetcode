class Solution {
public:
    string fractionAddition(string s) {
        int n = s.size(), i = 0;
        int a = 0, b = 1;
        char last = '+';
        while(i < n) 
        {
            bool negative = false;
            if(s[i] == '-') negative = true, i++;
            else if(i) i++;
            int numerator = 0;
            while(s[i] != '/') numerator = numerator * 10 + s[i++] - '0';
            i++;
            int denominator = 0;
            while(i < n && isdigit(s[i])) denominator = denominator * 10 + s[i++] - '0';
            if(negative) numerator = -numerator;
            a = a * denominator + b * numerator;
            b *= denominator;
            int c = gcd(a, b);
            a /= c, b /= c;
        }
        return to_string(a) + '/' + to_string(b);
    }
};