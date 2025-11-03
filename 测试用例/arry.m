main()
{
	int nums[4];
	char letters[3];
	int i,total;

	total = 0;
	i = 0;
	while(i < 4)
	{
		nums[i] = i * 2;
		total = total + nums[i];
		i = i + 1;
	}

	letters[0] = 'H';
	letters[1] = 'i';
	letters[2] = '!';
	letters[1] = letters[0];

	output total;
	output "\n";
	output nums[3];
	output "\n";
	output letters[1];
	output "\n";
}
