class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>> ret;
       vector<int> ans1;
       vector<int> ans2;
        
        unordered_map<int,bool> cont1;
        unordered_map<int,bool> cont2;
        for (int i:nums1){
            cont1[i] = true;
        }
        for (int i:nums2){
            cont2[i] =true;
            if (cont1[i]) ans2.push_back(i);
        }
        for (int i:nums1){
            if (cont2[i]) ans1.push_back(i);
        }
        
        ret.push_back(ans1);
        ret.push_back(ans2);
        
        return ret;
    }
    
};
