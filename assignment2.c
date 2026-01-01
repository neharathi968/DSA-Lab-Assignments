#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN 50

int main() {
    FILE *fin, *fout;
    char words[MAX_WORDS][MAX_LEN];
    char temp[MAX_LEN];
    int count = 0;

    
    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("error cannot open file\n");
        return 1;
    }

    
    while (fscanf(fin, "%49s", words[count]) == 1) { 
        count++;
        if (count >= MAX_WORDS) break;
    }
    fclose(fin);

    
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(words[i], words[j]) > 0) {
                strcpy(temp, words[i]);
                strcpy(words[i], words[j]);
                strcpy(words[j], temp);
            }
        }
    }

    
    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("error cannot open output file.\n");
        return 1;
    }

    
    for (int i = 0; i < count; i++) {
        fprintf(fout, "%s\n", words[i]);
    }
    fclose(fout);

    printf("completed sorting and writing the sorted words to the txt file\n");
    return 0;
}
