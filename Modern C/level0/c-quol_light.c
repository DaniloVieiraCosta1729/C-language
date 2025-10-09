#include <sqlite3.h>
#include <stdio.h>
#include <unistd.h>

#define PULA printf("\n");

sqlite3 * preparar(){
    sqlite3 * db;

    int r = sqlite3_open("tarefas.db", &db);

    if (r != SQLITE_OK)
    {
        fprintf(stderr, "Something ins't right: %s\n", sqlite3_errmsg(db));
        return NULL;
    }

    return db;
    
}

int menu()
{
    printf("================ T E R M I N A L  -- T O D O ================\n\n");

    char c;
    while (1)
    {
        printf("Select a option: \n");
        printf("[A]dd, [L]ist, [C]omplete, [U]pdate, [R]emove, [Q]uit\n>");

        while ((c = getchar()) != '\n')
        {
            printf(" Loading . . .\n");
            sleep(1);
        
        
            PULA

            switch (c)
            {
            case 'A':
            case 'a':
                printf("New item added.\n");
                break;
            
            case 'L':
            case 'l':
                printf("Tasks listed.\n");
                break;

            case 'C':
            case 'c':
                printf("ToDo Completed.\n");
                break;

            case 'U':
            case 'u':
                printf("Database Updated.\n");
                break;
            
            case 'R':
            case 'r':
                printf("Item removed.\n");
                break;

            case 'Q':
            case 'q':
                printf("Thank you for using the ToDo-Teminal.\n");
                return 0;

            default:
                printf("Invalid input.");
                break;
            }
        }
    }
    
}

int main(int argc, char const *argv[])
{
    sqlite3 * db = preparar();

    if (!db)
    {
        printf("Error...");
        return -1;
    }
    
    printf("Db opened and ready.\n");

    sqlite3_close(db);

    menu();

    return 0;
}
