struct BB{
    char q[2];
};
struct A{
    int id;
    char a[4][5];
    struct BB b[2];
};
main(){
    struct A a1[2];
    int i,j,k;
    char *p;

    a1[0].a[2][3]='z';
    output a1[0].a[2][3];

    i=0;j=2;k=3;
    p=&a1[0].a[j][k];
    *p = 'q';
    output a1[0].a[2][3];
    output *p;
    output a1[0].a[j][k];
}