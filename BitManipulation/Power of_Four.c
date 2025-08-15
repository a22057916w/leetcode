bool isPowerOfFour(int n) {
    /*
    4  = 100
    16 = 10000
    64 = 1000000
    The 1 bit of a power of four lies in odd positions,
    we use mask 0x55555555 to ensure that.
    */
    return n > 0 && (n & n - 1) == 0 && (n & 0x55555555) != 0; 
}