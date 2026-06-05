class Solution {
public:
    double myPow(double x, int n) {

        //base case - any no. raised to power 0 will give answer 1 
        if (n == 0) return 1;
        long long s = n; //to avoid integer overflow

        if (n < 0) {
            x = 1/x;
            s = -s;
        }

        double res = 1;
        while (s > 0) {
            if (s % 2 == 1) {
                res = res * x;  
            }
            x = x * x;
            s = s/2;
        }
        return res;   
    }
};