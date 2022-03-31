class Solution {
    double calcPow(double x, long long n) {
        if(n == 1) return x;
        double tmp = this->calcPow(x, n / 2);
        if(n % 2 == 0) return tmp * tmp;
        else return x * tmp * tmp;
    }
    
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        else if(x == 1) return 1;
        else if(x == -1) return ((n % 2 == 0) ? 1 : -1);
        
        if(n == 0) return 1.0;
        else if(n > 0) return this->calcPow(x, n);
        else return 1 / this->calcPow(x, (long long)(-1 * (long long)n));
    }
};