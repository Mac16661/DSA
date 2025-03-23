#include<iostream>
#include<cmath>
using namespace std;

int calcualteNodes(int level) {
    // return pow(2, level-1); // log n time 
    return (1<<(level-1)); // using bitwise operator O(1) time
} 

int main() {
    cout<<calcualteNodes(5)<<endl;
    return 0;
}