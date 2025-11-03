struct Pair
{
    int value;
    char flag;
};

struct Row
{
    char cols[6];
    struct Pair meta;
};

main()
{
    struct Row rows[3];
    int numbers[4];
    int *pi;
    char *pc;
    int i;
    int sum;

    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    rows[1].cols[0] = 'h';
    rows[1].cols[1] = 'i';
    rows[1].cols[2] = '\0';
    rows[1].meta.value = 10;
    rows[1].meta.flag = 'X';

    rows[2].cols[0] = 'b';
    rows[2].cols[1] = 'y';
    rows[2].cols[2] = 'e';
    rows[2].cols[3] = '\0';
    rows[2].meta.value = 20;
    rows[2].meta.flag = 'Y';

    pi = &numbers[0];
    sum = 0;
    i = 0;
    while(i < 4)
    {
        sum = sum + *pi;
        pi = pi + 1;
        i = i + 1;
    }

    pc = &rows[2].cols[0];
    *pc = 'B';
    pc = pc + 1;
    *pc = 'Y';
    pc = pc + 1;
    *pc = 'E';

    rows[1].meta.value = rows[1].meta.value + rows[2].meta.value;
    rows[1].meta.flag = rows[2].meta.flag;

    output sum;
    output "\n";
    output rows[2].cols[0];
    output rows[2].cols[1];
    output rows[2].cols[2];
    output "\n";
    output rows[1].meta.value;
    output "\n";
    output rows[1].meta.flag;
    output "\n";
}