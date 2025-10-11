#include <sqlite3.h>
#include <stdio.h>
#include <string.h>

#define pulalinha printf("\n");

sqlite3 * modifica_banco();
int menu(sqlite3 * db);
int add(sqlite3 * db);
int list(sqlite3 * db);
int delete(sqlite3 * db);

int main(int argc, char const *argv[])
{
    sqlite3 * db = modifica_banco();

    sqlite3_exec(db, "CREATE Table IF NOT EXISTS clientes("
            "id integer primary key,"
            "nome text not null,"
            "cpf text not null);", NULL, 0, NULL);

    menu(db);











    if (db != NULL)
    {
        const char * nomedb = sqlite3_db_filename(db, "main");

        sqlite3_close(db);

        printf("A conexão com o banco %s foi encerrada com sucesso.\n", nomedb);
    }
    
    return 0;
}

sqlite3 * modifica_banco()
{
    sqlite3 * db;

    int r = sqlite3_open("tarefas.db", &db);

    if (r != SQLITE_OK)
    {
        fprintf(stderr, "Erro ao abrir o banco: %s\n", sqlite3_errmsg(db));

        return NULL;
    }

    const char * nomeBanco = sqlite3_db_filename(db, "main");
    
    printf("A conexao com o banco %s foi bem sucedida.\n", nomeBanco);

    return db;
}

int menu(sqlite3 * db)
{
    printf("\t\t\t\t===== MENU =====\n");
    
    char choice;
    
    while (1)
    {
        printf("Selecione...\n\t\t\t [A]dd  [L]ist  [D]elete  [Q]uite\n>>> \n\n");
        if ((choice = getchar()) != '\n' && choice != EOF)
        {
            switch (choice)
            {
            case 'a':
            case 'A':
                add(db);
                break;

            case 'q':
            case 'Q':
                return 0;

            case 'l':
            case 'L':
                list(db);
                
            
            default:
                break;
            }
        }
        
    }
    

    return 0;
}

int add(sqlite3 * db)
{
    char nome[50];
    char cpf[11];
    char sql[256];
    int c;

    printf("Digite o nome do cliente\n>>> ");

    // limpar o buffer do stdin
    if ((c = getchar()) != 'n' && c != EOF);


    fgets(nome,sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';
    pulalinha

    printf("Digite o cpf do cliente\n>>> ");

    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    snprintf(sql, sizeof(sql), "insert into clientes (id, nome, cpf) values (null, '%s', '%s');", nome, cpf);

    sqlite3_exec(db, sql, NULL, 0, NULL);

    if ((c = getchar()) != '\n' && c != EOF);
    if ((c = getchar()) != '\n' && c != EOF);

    return 0;
}

int list(sqlite3 * db)
{
    sqlite3_exec(db, "select * from clientes;", NULL, 0, NULL);
    return 0;
}
int delete(sqlite3 * db)
{
    char c;

    printf("Digite o cpf do cliente que seja excluir\n>>> ");
    if ((c = getchar()) != )
    {
        /* code */
    }
    
    return 0;
}
