#include<bits/stdc++.h>
using namespace std;

//                    1
//                  2   3
//               4    5    6
//             7    8    9   10
// You can put water to the only top glass.
// If you put more than 1-litre water to 1st glass,
// water overflows and fills equally in both
// 2nd and 3rd glasses. Glass 5 will get water
// from both 2nd glass and 3rd glass and so on. 


// if you have 2 ltr of water

// 1st – 1 litre 
// 2nd – 1/2 litre 
// 3rd – 1/2 litre

// Program to find the amount of water in j-th glass
// of i-th row


float findWater(int row, int glass, float poured){
    if(glass > row){
        cout<<"Incorrect Input";
        return 0.0f;
    }

    // Initialize a vector to store the amount of water in each glass
    vector<float> glasses(row * (row + 1) / 2 , 0.0f);

    glasses[0] = poured;

    int index = 0;
    // Simulate the flow of water row by row
    for(int r = 1; r<=row; r++){// Loop through rows up to the target row
        for(int c = 1; c<=r; c++){// Loop through each glass in the current row

        // Calculate the overflow (amount of water exceeding 1.0 in the current glass)
            float overflow = max(0.0f, glasses[index] - 1.0f);
        // Cap the amount of water in the current glass to 1.0
            glasses[index] = min(1.0f, glasses[index]);

        // If not the last row, distribute the overflow equally to the two glasses below
            if(r<row){
                glasses[index + r] += overflow / 2.0f;// Glass directly below
                glasses[index + r + 1] = overflow / 2.0f;// Glass diagonally below to the right
            }
            // Move to the next glass (next index)
            index++;
        }
    }

    return glasses[row * (row - 1) / 2 + glass - 1];
    
}

int main(){
    int i,j;
    cin>>i>>j;

    float water;
    cin>>water;

    float ans = findWater(i,j,water);

    cout<<ans;
}