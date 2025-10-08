#include <sqlite3.h>
#include <stdio.h>

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

    return 0;
}
