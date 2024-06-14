uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t individual;
    for (int i = 0; i < 32; i++) {
        individual = (n >> i) & 1;
        res = res | (individual << 31 - i);
    }

    return res;
}