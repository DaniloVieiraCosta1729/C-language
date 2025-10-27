#include <stdio.h>
#include <sqlite3.h>

// Exercise 1-4: Write a program to print the corresponding Celsius to Fahrenheit table.

// É um exercício muito parecido, praticamente a mesma coisa, então vamos usar a abordagem da recursão novamente.
sqlite3 * initDB(); 

int CtoF(float lowest, float highest, float step, sqlite3 * db)
{
    if (lowest > highest)
    {
        return 0;
    }

    float F = (9.0/5)*lowest + 32; // parece uma péssima ideia. Eu imagino que o compilador vai criar uma stack para guardar o estado de cada chamada recursiva e vai gerar um valor para F em cada uma das chamadas.

    printf("\t %6.1f C\t\t %6.1f\n", lowest, F);
    char sql[256];
    sprintf(sql, "insert into temperatura (c, f) values (%6.1f, %6.1f)", lowest, F);
    sqlite3_exec(db, sql, NULL, 0, NULL);

    return CtoF(lowest + step, highest, step, db);
}

int main()
{
    printf("\t Celsius \t\t Fahrenheit\n");

    sqlite3 * db = initDB();

    sqlite3_exec(db, "create table if not exists temperatura(id integer primary key autoincrement, c real not null, f real not null);", NULL, 0, NULL);

    CtoF(0, 300, 20, db);

    return 0;
}

sqlite3 * initDB()
{
    sqlite3 * db;
    int r = sqlite3_open("db1_4.db", &db);

    if (r != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao abrir o banco: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    
    printf("\t\t>>> Banco aberto com sucesso <<<");

    return db;
}