struct Row
{
    char cols[10];
};

main()
{
    struct Row a[5];
    char *p;
    p=&a[2].cols[3];
    *p='n';
    p=p+1;
    *p='h';
    output a[2].cols[3];
    output a[2].cols[4];
}