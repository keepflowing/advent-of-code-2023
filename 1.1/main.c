#include <stdio.h>

int main () {
    FILE *calDoc;
    calDoc = fopen("./input", "r");
    fclose(calDoc);
    return 0;
}
