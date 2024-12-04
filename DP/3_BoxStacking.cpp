#include<bits/stdc++.h>
using namespace std;


int maxHeightRec(int i, vector<vector<int>>&boxes, vector<int>&dp){
    if(dp[i] != -1) return dp[i];

    int ans = boxes[i][2];

    for(int j=i+1; j<boxes.size(); j++){
        if(boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1]) {
            ans = max(ans, boxes[i][2] + maxHeightRec(j, boxes, dp));
        }
    }

    return dp[i] = ans;
}

int maxHeight(vector<int>&height, vector<int>&width, vector<int>&length){
    int n = height.size();

    // create a 2-D array to store all the orientationsof boxes in (l,b,h)

    vector<vector<int>>boxes;

    for(int i=0; i<n; i++){
        int a = height[i], b = width[i], c = length[i];

        boxes.push_back({a, b, c});
        boxes.push_back({a, c, b});
        boxes.push_back({b, a, c});
        boxes.push_back({b, c, a});
        boxes.push_back({c, a, b});
        boxes.push_back({c, b, a});
    }

    // sort the boxes in descending order of length

    sort(boxes.begin(), boxes.end(), greater<vector<int>>());

    int ans = 0;

    // check for all boxes starting as base
    vector<int>dp(boxes.size(), -1);

    for(int i=0; i<boxes.size(); i++){
        ans = max(ans, maxHeightRec(i,boxes,dp));
    }

    return ans;
}

int main(){
    int boxes;
    cin>>boxes;

    vector<int>height(boxes);
    vector<int>width(boxes);
    vector<int>length(boxes);

    for(int i=0; i<boxes; i++){
        cin>>height[i];
    }
    for(int i=0; i<boxes; i++){
        cin>>width[i];
    }
    for(int i=0; i<boxes; i++){
        cin>>length[i];
    }

    int ans = maxHeight(height, width, length);

    cout<<ans;
}