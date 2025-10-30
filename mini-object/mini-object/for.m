main()
{
	int i,sum;
	sum = 0;
	for(i = 0; i < 10; i = i + 1)
	{
		if(i == 7)
		{
			break;
		}
		if(i < 3)
		{
			continue;
		}
		sum = sum + i;
	}
	output sum;
	output "\n";
}
