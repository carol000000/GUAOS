void print(const char *text);

void kernel_main(void)
{
    print("HOLLE GUAOS");

    while (1)
    {
    }
}
void print(const char *text)
{
    volatile char *video = (volatile char *)0xB8000;

    int pos = 0;

    while (*text != '\0')
    {
        video[pos] = *text;
        video[pos + 1] = 0x02;   // 綠色

        pos += 2;
        text++;
    }
}