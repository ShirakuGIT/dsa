# include <stdio.h>
# include <string.h>

void sort(int no, char *array[]) {
    char *temp;
    for (int i = 0; i < no - 1; i++) {
        for (int j = i + 1; j < no; j++) {
            if (strcmp(array[i], array[j]) > 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
