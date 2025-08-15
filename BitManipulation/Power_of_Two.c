bool isPowerOfTwo(int n) {
    /*
    2次方只有最高位是1，減去1會使01相反
    n         = 100
    n - 1     = 011
    n & n - 1 = 0 
    */
    return n > 0 && (n & n-1) == 0;
}