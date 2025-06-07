#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TIME_LIMIT 10
#define TOTAL_STATES 28

typedef struct {
    char state[50];
    char capital[50];
} StateCapital;

int main() {
    StateCapital data[TOTAL_STATES] = {
        {"Andhra Pradesh", "Amaravati"},
        {"Arunachal Pradesh", "Itanagar"},
        {"Assam", "Dispur"},
        {"Bihar", "Patna"},
        {"Chhattisgarh", "Raipur"},
        {"Goa", "Panaji"},
        {"Gujarat", "Gandhinagar"},
        {"Haryana", "Chandigarh"},
        {"Himachal Pradesh", "Shimla"},
        {"Jharkhand", "Ranchi"},
        {"Karnataka", "Bengaluru"},
        {"Kerala", "Thiruvananthapuram"},
        {"Madhya Pradesh", "Bhopal"},
        {"Maharashtra", "Mumbai"},
        {"Manipur", "Imphal"},
        {"Meghalaya", "Shillong"},
        {"Mizoram", "Aizawl"},
        {"Nagaland", "Kohima"},
        {"Odisha", "Bhubaneswar"},
        {"Punjab", "Chandigarh"},
        {"Rajasthan", "Jaipur"},
        {"Sikkim", "Gangtok"},
        {"Tamil Nadu", "Chennai"},
        {"Telangana", "Hyderabad"},
        {"Tripura", "Agartala"},
        {"Uttar Pradesh", "Lucknow"},
        {"Uttarakhand", "Dehradun"},
        {"West Bengal", "Kolkata"}
    };

    int used[TOTAL_STATES] = {0};
    int score = 0, questionCount = 0;
    time_t start, end;
    srand(time(NULL));

    while (questionCount < TOTAL_STATES) {
        int qIndex;
        do {
            qIndex = rand() % TOTAL_STATES;
        } while (used[qIndex]);

        used[qIndex] = 1;
        int correctIndex = rand() % 4;
        char options[4][50];
        int filled[4] = {-1, -1, -1, -1};
        filled[correctIndex] = qIndex;
        strcpy(options[correctIndex], data[qIndex].capital);

        for (int i = 0; i < 4; i++) {
            if (i == correctIndex) continue;
            int wrong;
            do {
                wrong = rand() % TOTAL_STATES;
            } while (wrong == qIndex || (filled[0] == wrong || filled[1] == wrong || filled[2] == wrong || filled[3] == wrong));
            filled[i] = wrong;
            strcpy(options[i], data[wrong].capital);
        }

        printf("\nQ%d: What is the capital of %s?\n", questionCount + 1, data[qIndex].state);
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, options[i]);
        }

        int answer;
        time(&start);
        printf("Your answer (1-4): ");
        scanf("%d", &answer);
        time(&end);

        if (difftime(end, start) > TIME_LIMIT) {
            printf("Time's up! You took too long.\n");
            break;
        }

        if (answer - 1 == correctIndex) {
            printf("Correct!\n");
            score++;
        } else {
            printf("Wrong! Correct answer: %s\n", data[qIndex].capital);
        }

        questionCount++;
    }

    printf("\nYour final score: %d out of %d\n", score, TOTAL_STATES);
    return 0;
}
