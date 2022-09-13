using namespace std;

class Solution {
public:
    int numSquares(int n) {
        int t[n+1];

        t[0]=0;
        t[1]=1;

        for(int i=2; i<n+1; i++){
             int temp=INT_MAX;
             for(int j=1; j*j<=i ;j++){
                 int k= i-(j*j);
                 temp=min(temp, t[k]);
             }
            t[i]=1+temp;
        }

        return t[n];
    }
};