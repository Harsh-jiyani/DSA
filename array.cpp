// note:Iterate C++ Program to print alternate elements
 
#include <iostream>
#include <vector>
using namespace std;

vector<int> getAlternates(vector<int> &arr) {
    vector<int> res;
  
    
    for(int i = 0; i < arr.size(); i += 2) {
    	res.push_back(arr[i]);
    }
    return res;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    vector<int> res = getAlternates(arr); 
    for(int x: res)
        cout << x << " ";
}
