#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][101];
    int count[n];
    int unique = 0;

    char temp[101];

    for (int i = 0; i < n; i++) {
        scanf("%s", temp);

        int found = -1;
        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                found = j;
                break;
            }
        }

        if (found != -1) {
            count[found]++;
        } else {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char winner[101] = "";

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        } else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d", winner, maxVotes);

    return 0;
}