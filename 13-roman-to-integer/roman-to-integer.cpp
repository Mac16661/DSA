class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        int i = 0;

        while (i < s.length()) {
            switch (s[i]) {
                case 'I':
                    if (i + 1 < s.length() && s[i + 1] == 'V') {
                        sum += 4;
                        i += 2;
                    } else if (i + 1 < s.length() && s[i + 1] == 'X') {
                        sum += 9;
                        i += 2;
                    } else {
                        sum += 1;
                        i++;
                    }
                    break;

                case 'V':
                    sum += 5;
                    i++;
                    break;

                case 'X':
                    if (i + 1 < s.length() && s[i + 1] == 'L') {
                        sum += 40;
                        i += 2;
                    } else if (i + 1 < s.length() && s[i + 1] == 'C') {
                        sum += 90;
                        i += 2;
                    } else {
                        sum += 10;
                        i++;
                    }
                    break;

                case 'L':
                    sum += 50;
                    i++;
                    break;

                case 'C':
                    if (i + 1 < s.length() && s[i + 1] == 'D') {
                        sum += 400;
                        i += 2;
                    } else if (i + 1 < s.length() && s[i + 1] == 'M') {
                        sum += 900;
                        i += 2;
                    } else {
                        sum += 100;
                        i++;
                    }
                    break;

                case 'D':
                    sum += 500;
                    i++;
                    break;

                case 'M':
                    sum += 1000;
                    i++;
                    break;

                default:
                    i++; // Handle invalid characters gracefully
            }
        }
        return sum;
    }
};
