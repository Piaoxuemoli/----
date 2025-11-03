main() {
    int arr[5][5];
    int i, j;
    int sum;
    for (i = 0; i < 5; i=i+1) {
        for (j = 0; j < 5; j=j+1) {
            arr[i][j] = i * 10 + j;
        }
    }

    sum = 0;
    for (i = 0; i < 5; i=i+1) {
        for (j = 0; j < 5; j=j+1) {
            sum = sum + arr[i][j];
        }
    }

    output sum;
}