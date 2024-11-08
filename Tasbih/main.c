#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void tasbih(int tasbih, int pearl)
{
    char A[100];
    for (int i = 0; i < tasbih; i++)
    {
        for (int j = 0; j < pearl; j++)
        {
            scanf("%[^\n]", A);
            getchar();
            system("cls");
            printf("Tasbih:%d & Count:%d", i + 1, j );
            puts("");
        }
        Beep(750, 1000);
        Sleep(900);
    }
}
void storeDT(const char *filename, int a, int b)
{
    // Get current date and time
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);

    // Create a buffer to hold the formatted date and time
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", tm_info);

    // Open the file in append mode
    FILE *file = fopen(filename, "a");
    if (file == NULL)
    {
        perror("Error opening file");
        return;
    }

    // Write the date and time to the file
    fprintf(file, "%s %dx%d\n", buffer, a, b);

    // Close the file
    fclose(file);
}

int menu(void)
{
    int choice;
    puts("----------Daily Dhikr----------");
    puts("1. 1x100");
    puts("2. 3x100");
    puts("3. 4x100");
    puts("4. 3x33");
    puts("5. Custom");
    puts("6. Show history");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int main(void)
{
    const char *filename = "History.txt";
    int tsbh, pearl;
    switch (menu())
    {
    case 1:
        tasbih(1, 100);
        storeDT(filename, 1, 100);
        break;
    case 2:
        tasbih(3, 100);
        storeDT(filename, 3, 100);
        break;
    case 3:
        tasbih(4, 100);
        storeDT(filename, 4, 100);
        break;
    case 4:
        tasbih(3, 33);
        storeDT(filename, 3, 33);
        break;
    case 5:
        printf("Enter Tasbih: ");
        scanf("%d", &tsbh);
        printf("Enter pearl amount: ");
        scanf("%d", &pearl);
        tasbih(tsbh, pearl);
        storeDT(filename, tsbh, pearl);
        break;
    case 6:
        FILE *file = fopen(filename, "r"); // Open the file in read mode
        if (file == NULL)
        {
            perror("Error opening file");
            return 1;
        }

        char line[256]; // Buffer to hold each line
        while (fscanf(file, "%[^\n]\n", line) == 1)
        {
            printf("%s\n", line);
        }

        fclose(file);
        break;
    default:
        puts("Wrong Input");
        return 1;
    }
}