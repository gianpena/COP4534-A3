#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector<vector<int>> resources;
vector<pair<int,int>> tasks;
int n, k;

bool backtracking(int task) {
  if(task >= n) return true;
  auto &[start, end] = tasks[task];

  for(int i=0;i<k;++i) {
    auto &resource = resources[i];
    if(resource.empty() || start >= tasks[resource.back()].second) {
      resource.push_back(task);
      bool result = backtracking(task + 1);
      if(result) return true;
      resource.pop_back();
    }
  }
  return false;
}

int main() {
  cout<<"Enter the number of resources at your disposal: ";
  cin>>k;
  cout<<"Enter the number of tasks needing to be completed: ";
  cin>>n;
  for(int i=0; i<n; ++i) {
    int start, end;
    cout<<"Enter the start and end time for this task: ";
    cin>>start>>end;
    tasks.push_back({start, end});
  }

  sort(tasks.begin(), tasks.end(), [](const pair<int,int> &a, const pair<int,int> &b){
    return a.second < b.second;
  });
  resources.resize(k, vector<int>());

  cout<<"Attempting to find arrangement of tasks...\n";
  bool result = backtracking(0);

  if(!result) {
    cout<<"Not possible to organize the given tasks into the given resources.\n";
    return 1;
  }

  cout<<"Arrangement found!\n";
  for(int i=0;i<k;++i) {
    auto &resource = resources[i];
    if(resource.empty()) {
      cout<<"No tasks in resource "<<(i+1)<<".\n";
      continue;
    }

    cout<<"Tasks in resource "<<(i+1)<<":\n";
    for(int task = 0; task < resource.size(); ++task) {
      auto &p = tasks[resource[task]];
      cout<<"("<<p.first<<", "<<p.second<<")"<<(task == resource.size() - 1 ? "\n" : ", ");
    }
  }
  
}