#include <stdio.h>

// TODO: Can this be done in reverse_words itself
void reverse_word(char *s, char*e) 
{
    char c;
    while(s < e) {
        c = *s;
        *s = *e;
        *e = c;
        s++;
        e--;
    }
}

void reverse_words(char *left, char *right)
{
    char c;
    char *left_word_start=left, *right_word_end=right;
    while(left <= right) {
        c = *left;
        *left = *right;
        *right = c;
        if(*left == ' ') {
            reverse_word(left_word_start, left-1);
            left_word_start = left+1;
        }
        if(*right == ' ') {
            reverse_word(right+1, right_word_end);
            right_word_end = right-1;
        }
        left++;
        right--;
    }
    reverse_word(left_word_start,right_word_end);
}


int main(int argc, char **argv)
{
    char *str = NULL;
    size_t str_size, n;
    FILE *f;
    if(argc == 1 || strcmp(argv[1],"-") == 0) {
        f = stdin;
    } else {
        f = fopen(argv[1], "r");
        if(!f) {
            perror("Error opening file: ");
            return 2;
        }
    }
    while((n = getline(&str, &str_size, f)) != -1) {
        if(str[n-1] == '\n') str[n-1] = '\0';
        reverse_words(str, str+n-2);
        printf("%s\n", str);
    }
    fclose(f);
}
