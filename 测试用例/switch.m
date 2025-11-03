main()
{
	int value,result;
	value = 2;
	result = 0;
	switch(value)
	{
		case 1:
			result = 1;
			break;
		case 2:
			result = 2;
		case 3:
			result = result + 3;
			break;
		default:
			result = -1;
			break;
	}
	output result;
	output "\n";
}
