#include <bits/stdc++.h>
using namespace std;
vector<tuple<string, int, int>> items;
vector<vector<string>> possiblePurchaseArrangements;
vector<string> currentArrangement;

void backtrack(int budget, int i) {
  if(budget <= 0 || i >= items.size()) {
    possiblePurchaseArrangements.emplace_back(currentArrangement.begin(), currentArrangement.end());
    return;
  }

  auto &[name, price, limit] = items[i];
  if(budget >= price && (limit < 0 || limit > 0)) {
    currentArrangement.push_back(name);
    --limit;
    backtrack(budget - price, i);
    ++limit;
    currentArrangement.pop_back();
  }

  backtrack(budget, i+1);
}

int budget;
int main() {
  cout<<"Enter the budget for your party: ";
  cin>>budget;
  cout<<"Enter the number of distinct items available for purchase: ";
  int n;
  cin>>n;
  for(int i=1;i<=n;++i){
    cout<<"Enter item "<<i<<"'s name, price, and limit, each separated by a single space. If there is no limit, use -1.\n";
    string name;
    int price, limit;
    cin>>name>>price>>limit;
    items.push_back({name, price, limit});
  }

  backtrack(20, 0);

  if(possiblePurchaseArrangements.empty()) {
    cout<<"No possible purchase arrangements.\n";
    return 0;
  }
  
  cout<<"Number of possible purchase arrangements: "<<(possiblePurchaseArrangements.size())<<'\n';
  cout<<"Purchase arrangements are as follows:\n";
  for(auto &arrangement: possiblePurchaseArrangements) {
    if(arrangement.empty()) continue;
    for(int i=0;i<arrangement.size();++i) {
      cout<<arrangement[i]<<(i==arrangement.size()-1 ? "\n" : ", ");
    }
  }
}