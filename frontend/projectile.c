

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define g 9.81
#define PI 3.14159

int main() {
    float velocity, angle, range;
    int target;
    char choice;
    int score = 0;
    int level = 1;

    srand(time(0));

    do {
        int attempts = 3;

        // Increase difficulty with level
        target = rand() % (200 + level * 50) + 50;

        printf("\n==============================");
        printf("\nLEVEL: %d", level);
        printf("\nTARGET DISTANCE: %d meters", target);
        printf("\nYou have 3 attempts!");
        printf("\n==============================\n");

        while (attempts > 0) {

            printf("\n1. Launch Projectile");
            printf("\n2. Auto Solve (45° best range)");
            printf("\nChoose option (1 or 2): ");

            int option;
            scanf("%d", &option);

            if (option == 2) {
                velocity = sqrt(target * g);
                angle = 45;
                printf("\n[Auto Solution Loaded]");
                printf("\nVelocity = %.2f m/s", velocity);
                printf("\nAngle = %.2f degrees\n", angle);
            } else {
                printf("\nEnter launch velocity (m/s): ");
                scanf("%f", &velocity);

                printf("Enter launch angle (degrees): ");
                scanf("%f", &angle);
            }

            float angleRad = angle * PI / 180;
            range = (velocity * velocity * sin(2 * angleRad)) / g;

            printf("\nProjectile landed at: %.2f meters\n", range);

            if (fabs(range - target) <= 5) {
                printf("HIT! Target Destroyed!\n");
                score += 10 * level;
                level++;
                break;
            } 
            else if (range < target) {
                printf("Too Short!\n");
            } 
            else {
                printf("Overshot!\n");
            }

            attempts--;
            printf("Attempts left: %d\n", attempts);
        }

        if (attempts == 0) {
            printf("\nYou failed this level!\n");
            break;
        }

        printf("\nCurrent Score: %d\n", score);
        printf("\nContinue to next level? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nFinal Score: %d", score);
    printf("\nThanks for playing!\n");

    return 0;
}