class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> rows;

        for(int i = 0; i < numRows; i++) {
            vector<int> r;  //for creating each particular row
            r.push_back(1);    //first element of each row is always 1

            //sum of previous rows elements
            for(int j = 1; j < i; j++) {
                r.push_back(rows[i-1][j-1] + rows[i-1][j]);
            }

            if(i > 0) {
                r.push_back(1);   //last element of each row is also always 1
            }
            rows.push_back(r);  //need to push each completed row in the "rows" vector
        }
        return rows;        
    }
};