 * On error, -1 is returned, and errno is set appropriately.
 */
int write_to_buffer(char c, char action)
{
	static int i;
	static int chars_count;
	static char buffer[1024];
	static char out;

	if (i < 1024 && action == 0)
	{
		out = chars_count < 1 ? 1 : out;
		buffer[i] = c;
		i++;
		chars_count++;
	}
	if (i >= 1024 || action == 1)
	{
		out = write(1, buffer, i);
		i = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -1)
	{
		i = 0;
		chars_count = 0;
		mem_set(buffer, 1024, 0);
	}
	if (action == -2)
	{
		return (chars_count);
	}
	return (out);
}
