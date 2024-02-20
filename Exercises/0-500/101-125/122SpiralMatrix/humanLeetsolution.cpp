class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int sr = 0, sc = 0, er = mat.size()-1,ec = mat[0].size()-1,i;
        vector<int> v;
        while(sr<=er && sc <= ec){
            for(i = sc; i <= ec && sr<=er; i++){
                v.push_back(mat[sr][i]);
            }
            sr++;
            for(i = sr; i <= er &&  sc<=ec; i++){
                v.push_back(mat[i][ec]);
            }
            ec--;
            for(i = ec; i >= sc &&  sr<=er; i--){
                v.push_back(mat[er][i]);
            }
            er--;
            for(i = er; i >= sr && sc<=ec; i--){
                v.push_back(mat[i][sc]);
            }
            sc++;
        }
        return v;
    }
};