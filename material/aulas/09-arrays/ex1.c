int soma(int *vec, int n) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += vec[i];
    }
    return s;
}
