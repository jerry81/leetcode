class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
       vector<vector<int>> ret;
       set<int> anss1;
       set<int> anss2;
        
        unordered_map<int,bool> cont1;
        unordered_map<int,bool> cont2;
        for (int i:nums1){
            cont1[i] = true;
        }
        for (int i:nums2){
            cont2[i] =true;
            if (!cont1[i]) anss2.insert(i);
        }
        for (int i:nums1){
            if (!cont2[i]) anss1.insert(i);
        }
        
        vector<int> ans1(anss1.begin(), anss1.end());
        
        vector<int> ans2(anss2.begin(), anss2.end());
        
        ret.push_back(ans1);
        ret.push_back(ans2);
        
        return ret;
    }
    
};
