void kernel_main(void){
    char *video = (char *)0xB8000;
    video[0] = 'H';
    video[1] = 0x02;
    video[2] = 'E';
    video[3] = 0x02;
    video[4] = 'L';
    video[5] = 0x02;
    video[6] = 'L';
    video[7] = 0x02;
    video[8] = 'O';
    video[9] = 0x02;

    video[12] = 'G';
    video[13] = 0x02;
    video[14] = 'U';
    video[15] = 0x02;
    video[16] = 'A';
    video[17] = 0x02;
    video[18] = 'O';
    video[19] = 0x02;
    video[20] = 'S';
    video[21] = 0x02;
    video[22] = '!';
    video[23] = 0x02;

    while(1){
        
    }
}
