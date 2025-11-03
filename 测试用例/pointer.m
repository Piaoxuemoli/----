main()
{
	int value,result;
	int *p;
	char ch,copy;
	char *pc;

	value = 5;
	p = &value;
	result = *p;
	*p = result + 1;

	ch = 'A';
	pc = &ch;
	copy = *pc;

	output result;
	output "\n";
	output value;
	output "\n";
	output copy;
	output "\n";
}
