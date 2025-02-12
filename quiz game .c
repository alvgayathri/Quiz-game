#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUESTIONS 5

// Structure for a quiz question
typedef struct {
    char question[256];
    char options[4][100];
    char correct_option;
} Question;

// Function to display a question and get user input
int ask_question(Question q) {
    char user_answer;
    int i;
    printf("%s\n", q.question);
    for (i = 0; i < 4; i++) {
        printf("%c) %s\n", 'A' + i, q.options[i]);
    }
    printf("Enter your answer (A/B/C/D): ");
    scanf(" %c", &user_answer);
    return (user_answer == q.correct_option) ? 1 : 0;
}

int main() {
    Question quiz[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Berlin", "Madrid", "Paris", "Rome"}, 'C'},
        {"Which programming language is known as the 'mother of all languages'?", {"Python", "C", "Java", "JavaScript"}, 'B'},
        {"Who wrote 'Harry Potter'?", {"J.K. Rowling", "J.R.R. Tolkien", "George R.R. Martin", "Agatha Christie"}, 'A'},
        {"What is 15 + 30?", {"40", "45", "50", "55"}, 'B'},
        {"Which planet is known as the Red Planet?", {"Earth", "Mars", "Jupiter", "Venus"}, 'B'}
    };
    
    int score = 0;
    int i;
    printf("Welcome to the Quiz Game!\n\n");
    
    for (i = 0; i < MAX_QUESTIONS; i++) {
        printf("Question %d:\n", i + 1);
        if (ask_question(quiz[i])) {
            printf("Correct!\n\n");
            score++;
        } else {
            printf("Wrong answer!\n\n");
        }
    }
    
    printf("Quiz Over! Your final score: %d/%d\n", score, MAX_QUESTIONS);
    
    // Store the score in a file
    FILE *file = fopen("quiz_scores.txt", "a");
    if (file != NULL) {
        fprintf(file, "Player Score: %d/%d\n", score, MAX_QUESTIONS);
        fclose(file);
    }
    
    return 0;
}

