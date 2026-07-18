#include "io.h"
#include "keyboard.h"

#define COLOR_BLUE   0x0B
#define COLOR_GREEN  0x02
#define COLOR_RED    0x04
#define COLOR_WHITE  0x0F
volatile char *video = (volatile char *)0xB8000;
unsigned char current_color = COLOR_GREEN;
int cursor = 0;
void print(const char *text);
void clear_screen(void);
void scroll(void);
void set_color(unsigned char color);
void backspace(void);
void kernel_main(void){
    keyboard_init();
    clear_screen();
    print("HELLO ");
    print("GUAOS!\n");

    set_color(COLOR_RED);
    print("ERROR\n");

    set_color(COLOR_BLUE);
    print("gua\n");

    set_color(COLOR_WHITE);
    print("Welcome!");
    print("HELLO");
backspace();
backspace();
    while (1){}
}

void set_color(unsigned char color){
    current_color = color;
}
void print_char(char c){
    video[cursor] = c;
    video[cursor + 1] = current_color;

    cursor += 2;
    if (cursor >= 80 * 25 * 2){
        scroll();
    }
}
void print(const char *text){
    while (*text != '\0')
    {
        if (*text == '\n'){
            cursor += 160 - (cursor % 160);

        if (cursor >= 80 * 25 * 2){
            scroll();
    }
    text++;
    continue;
}

        print_char(*text);

        text++;
    }
}
void clear_screen(){
    int i = 0;

    while (i < 80 * 25){
        
        video[i * 2] = ' ';
        video[i * 2 + 1] = current_color;

        i++;
    }
    cursor = 0;
}
    void scroll(){
        int i = 0;
        while (i < 24 * 160){
        video[i] = video[i + 160];
        i++;
    }
    i = 24 * 160;
    while (i < 25 * 160){
        video[i] = ' ';
        video[i + 1] = current_color;
        i += 2;
    }
    cursor = 24 * 160;
}
void backspace(){
    if (cursor == 0){
        return;
    }
    cursor -= 2;
    video[cursor] = ' ';
    video[cursor + 1] = current_color;
}