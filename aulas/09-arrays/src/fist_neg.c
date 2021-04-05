int first_neg(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        if (vec[i] < 0) {
            return i;
        }
    }
}