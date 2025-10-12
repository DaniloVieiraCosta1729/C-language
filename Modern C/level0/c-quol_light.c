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

// this enum will be used in our implementation of the actions of our todo app.
enum ERR {OK, ERROR}; // incrivelmente, essa é a primeira vez que uso enum.

// let's declare first and then define later the functions of this app.
enum ERR add(sqlite3 *db);
enum ERR list(sqlite3 *db);
enum ERR complete(sqlite3 *db);
enum ERR update(sqlite3 *db);
enum ERR remove(sqlite3 *db);
enum ERR quit(sqlite3 *db);

int menu(sqlite3 db)
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
                add(&db);
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

enum ERR add(sqlite3 *db)
{
    char todo[128];
    char sql[256];

    printf("----- Add task -----\n\t>>> ");

    if (fgets(todo, sizeof(todo), stdin))
    {
        *(todo + strcspn(todo, "\n")) = '\0';
        snprintf(sql, sizeof(sql), "INSERT INTO To_do (Id, Titulo, Desenho, Impressao, Completo) VALUES (NULL, '%s', 0, 0, 0);", todo);


        char * errMsg = 0;
        int r = sqlite3_exec(db, sql, &errMsg);

        if (r != SQLITE_OK)
        {
            fprintf(stderr, "error: %s", sqlite3_errmsg(errMsg));

            return ERROR;
        }

        return OK;
        
    }
    


}
enum ERR list(sqlite3 *db)
{
    return OK;
}
enum ERR complete(sqlite3 *db)
{
    return OK;
}
enum ERR update(sqlite3 *db)
{
    return OK;
}
enum ERR remove(sqlite3 *db)
{
    return OK;
}
enum ERR quit(sqlite3 *db)
{
    return OK;
}
