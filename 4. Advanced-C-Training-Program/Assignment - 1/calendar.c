#include <stdio.h>
#include <string.h>

struct calendar {
    char dayName[10];
    char tasks[3][100];
    int noTasks;
};


int main() {
    struct calendar days[7] = {
        {"Monday", {}, 0},
        {"Tuesday", {}, 0},
        {"Wednesday", {}, 0},
        {"Thursday", {}, 0},
        {"Friday", {}, 0},
        {"Saturday", {}, 0},
        {"Sunday", {}, 0}
    };

    int n = 0;
    int day = 0;

    do {
        printf("\nEnter:\n");
        printf("0 to close\n");
        printf("1 to add task\n");
        printf("2 to display all tasks\n");
        printf("Enter your choice: ");
        scanf("%d", &n);
        getchar();  

        switch(n) {
            case 0:
                printf("Thank You.\n");
                break;

            case 1:
                printf("Enter value 0-6 for Monday-Sunday: ");
                scanf("%d", &day);
                getchar();
                if (day < 0 || day > 6) {
                    printf("Invalid day number. Try again.\n");
                    break;
                }

                printf("Enter number of tasks to be added (max 3): ");
                scanf("%d", &days[day].noTasks);
                getchar(); 
                if (days[day].noTasks < 1 || days[day].noTasks > 3) {
                    printf("Invalid task count. Max allowed is 3.\n");
                    days[day].noTasks = 0;
                    break;
                }

                for (int i = 0; i < days[day].noTasks; i++) {
                    printf("Enter task %d: ", i + 1);
                    fgets(days[day].tasks[i], 100, stdin);
                    days[day].tasks[i][strcspn(days[day].tasks[i], "\n")] = '\0';
                }

                printf("Successfully added %d tasks to be done on %s\n",
                       days[day].noTasks, days[day].dayName);
                break;

            case 2:
                printf("\nDisplaying tasks:\n");
                for (int i = 0; i < 7; i++) {
                    printf("Day: %s\n", days[i].dayName);
                    if (days[i].noTasks == 0) {
                        printf("\tNo tasks\n");
                    } else {
                        for (int j = 0; j < days[i].noTasks; j++) {
                            printf("\tTask %d: %s\n", j + 1, days[i].tasks[j]);
                        }
                    }
                }
                break;

            default:
                printf("Wrong choice... Try Again\n");
                break;
        }

    } while (n != 0);

    return 0;
}
