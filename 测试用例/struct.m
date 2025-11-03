struct Pair{
    int first;
    char second;
};

main()
{
    struct Pair p;
    struct Pair q;
    int total;

    p.first = 7;
    p.second = 'X';
    q.first = 3;
    q.second = 'Y';

    total = p.first + q.first;
    q.second = p.second;

    output total;
    output "\n";
    output q.second;
    output "\n";
}
