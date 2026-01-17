#include<bits/stdc++.h>
using namespace std;

int main(){
  //lower bound
  vector<int> v = {1,3,3,5,7,9};

  auto it = lower_bound(v.begin(), v.end(), 3);
  cout << "Lower bound of 3 is at index: " << it - v.begin() << endl;

  auto it2 = upper_bound(v.begin(), v.end(), 4);
  cout << "Upper bound of 4 is at index: " << it2 - v.begin() << endl;

  //deque
  deque<int> d;

  d.push_back(10);
  d.push_front(20);
  cout << "Deque front: " << d.front() << ", back: " << d.back() << endl; //20, 10
  //d.push_front(30);
  d.push_back(30);
  
  d.pop_front();
  d.pop_back();
  cout << "Deque size after pops: " << d.size() << endl; //1
  cout<< "Deque front after pops: " << d.front() << endl; //10
  return 0;
}