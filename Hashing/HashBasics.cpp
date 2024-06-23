#include<bits/stdc++.h>
using namespace std;

int main() {
    // Initlization of map
    map<string, int> mp;

    // Declaring map
    mp = {
        {"alph", 0},{"beta", 0},{"gamma", 0}
        };

    // Assiging key values pairs to the map
    mp["one"] = 1;
    mp["two"] = 2;

    // Creating iterators 
    map<string, int> :: iterator it = mp.begin();

    // Iteraring through map
    while(it != mp.end()) {
        cout<< "Key: "<< it->first<< " Value: "<< it->second<<endl;

        ++it;
    }

    // Finding size of map
    cout<<mp.size()<<endl;

    // Findind elements in the map
    it = mp.find("one");
    if(it != mp.end()) {
        cout<<it->second<<endl;
    }

    cout<<mp.find("one")->first<<endl;

    // If the elemet is present in the map or not
    cout<<mp.count("one") << endl;

    // Check if it is empty or not
    cout<< mp.empty()<<endl;
    return 0;
}