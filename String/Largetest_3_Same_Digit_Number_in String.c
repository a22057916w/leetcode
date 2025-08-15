char* largestGoodInteger(char* num) {
    char* good_int = (char*)malloc(4);
    good_int[0] = '\0';
    while(num[2] != '\0') {
        if(num[0] == num[1] && num[0] == num[2])
            if(num[0] > good_int[0]) {
                good_int[0] = good_int[1] = good_int[2] = num[0];
                good_int[3] = '\0';
            }
        num++;
    }
    return good_int;
}