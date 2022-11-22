#include <bits/stdc++.h>
using namespace std;

class Team{
    string name;
    int points;
    int matches[5];
    
    public:
    
    void takeInput(string s , int arr[])
    {
        name = s;
        points = 0;
        for(int i=0;i<5;i++)
        {
            matches [i] = arr[i];
            if (matches[i]) points ++;
        }
    }
    
    int ConsecutiveLosses()
    {
        int i = -1,j= 0;
        bool ans = false ;
        while(j<5)
        {
            if(!matches [j] )
            {
                j++;
            }
            else 
            {
                i = j ;
                j ++;
            }
            
            if(j-i == 3)
            {
                ans = true;
                break;
            }
        }
        if(!ans)
        return -1 ;
        
        cout << name << endl;
        return points; 
  }  
};

int main(){ 
    int num = 10;
    Team teams[num];
    
    // We can take input from user also but as given in ques i took it directly
    string names[num] = {"GT","LSG","RR","DC","RCB","KKR","PBKS","SRH","CSK","MI"};
    int record[num][5] = {
        {1,1,0,0,1},
        {1,0,0,1,1},
        {1,0,1,0,0},
        {1,1,0,1,0},
        {0,1,1,0,0},
        {0,1,1,0,1},
        {0,1,0,1,0},
        {1,0,0,0,0},
        {0,0,1,0,1},
        {0,1,0,1,1},
    };

    for(int i=0;i<num;i++)
    {
        teams [i].takeInput (names[i],record[i]);
    }
    
    float totalPoints = 0;
    int totalTeamsN = 0;
    cout << "Name of teams are " << endl;
    for(int i=0;i<num;i++)
    {
        int curr = teams[i].ConsecutiveLosses();
        if(curr==-1) continue;

        totalPoints += curr;
        totalTeamsN++;
    }
    if(totalTeamsN==0)
    {
        cout << "No Team have 2 consecutive losses"<<endl;
    }else
    {
        float ans = totalPoints/totalTeamsN;
        cout << "Average calculated points of filtered teams : " << fixed<< setprecision(6) <<ans  << endl;
    }

    return 0;
}