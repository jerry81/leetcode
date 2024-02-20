class Solution {
public:
    int widthOfBinaryTree(TreeNode* a) {
        vector<int>v;

        if(!a) // null check, much easier
        return 0;

        int ans = 1;
        queue<pair<TreeNode*,long long int>>q; // pair is the way to go
        q.push({a,0});

        while(!q.empty())
        {
            int sz = q.size();
            int a1 = 0, b1 = 0;
            int l = 0;
            int mn = q.front().second; // parent's position
            for(int i = 0; i < sz; i++) // instead of 2 queues, single queue and use a for loop
            {
                auto p = q.front();
                TreeNode* b = p.first;
                // shrinks it down to relative position to first parents' position
                // this saves us from the overflow
                long long int k = p.second-mn;
                q.pop();
                // leftmost node
                if(i == 0)
                a1 = k;
                // rightmost node
                if(i == sz-1)
                b1 = k; // he doesn't explode it here

                if(b->left)
                q.push({b->left,2*k+1}); // same explosiveness

                if(b->right)
                q.push({b->right,2*k+2});
            }
            // To store maximum difference.
            ans = max(ans,b1-a1+1);
        }

        return ans;

    }
};