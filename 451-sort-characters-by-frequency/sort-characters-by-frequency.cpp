class Solution {
public:
    string frequencySort(string s) {
        vector<int> freqArr(128, 0); // creating a frequency array

        for(auto ch :s) freqArr[ch]++; // populating freq array

        // Using a custom comparator function to sort
        auto cmp = [&] (char a, char b) { //[&] -> member of function can access everything outside function score
            if(freqArr[a] == freqArr[b]) return a < b;
            return freqArr[a] > freqArr[b];
        };   

        sort(s.begin(), s.end(), cmp);

        return s;
    }
};