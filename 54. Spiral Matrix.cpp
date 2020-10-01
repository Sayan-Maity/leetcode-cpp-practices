//Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
//Memory Usage: 7.2 MB, less than 11.22% of C++ online submissions for Spiral Matrix.
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        if(n == 0) return {};
        
        /*
        right: {0, 1}
        down : {1, 0}
        left : {0,-1}
        up   : {-1,0}
        */
        vector<int> dirs = {0, 1, 0, -1, 0};
        /*
        right, down, left, top
        */
        vector<int> limits = {n-1, m-1, 0, 0};
        int dir = 0;
        vector<int> ans;
        int r = 0, c = 0;
        int k = m*n;
        
        while(k-- > 0){
            // cout << r << ", " << c << endl;
            
            ans.push_back(matrix[r][c]);
            
            if(r + dirs[dir] < limits[3] || 
               r + dirs[dir] > limits[1] || 
               c + dirs[dir+1] < limits[2] || 
               c + dirs[dir+1] > limits[0]){
                //need to change direction
                limits[(dir+4-1)%4] += ((dir+4-1)%4 < 2) ? -1 : 1;
                // cout << "limits[" << (dir+4-1)%4 << "]: " << limits[(dir+4-1)%4] << endl;
                dir = (dir+1)%4;
                // cout << "dir: " << dir << endl;
            }
            
            r += dirs[dir];
            c += dirs[dir+1];
        }
                          
        return ans;
    }
};
