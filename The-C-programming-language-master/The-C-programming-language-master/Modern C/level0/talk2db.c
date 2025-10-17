#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define pulalinha printf("\n");
// sql injection está valendo. Pode hackear. (Vou fazer uma versão segura depois)

int listcallback(void * data, int argc, char ** argv, char ** azColName)
{
    char * border = "------------------------------------------------------------------------------\n";
    
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s",border);
        printf("%s -> %s\n", azColName[i], i[argv] ? argv[i] : "NULL");

        if ((i+1) % 3 == 0)
        {
            printf("%s",border);
            pulalinha
            pulalinha            
        }
        
    }
    
    return 0;
}

int updatecallback(void * data, int argc, char ** argv, char ** azColName)
{
    char * nome_update = (char *)data;
    strcpy(nome_update, argv[1]);
    return 0;
}

sqlite3 * modifica_banco();
int menu(sqlite3 * db);
int add(sqlite3 * db);
int list(sqlite3 * db);
int delete(sqlite3 * db);
int update(sqlite3 * db);

int main(int argc, char const *argv[])
{
    sqlite3 * db = modifica_banco();

    sqlite3_exec(db, "CREATE Table IF NOT EXISTS clientes("
            "id integer primary key,"
            "nomeatual text not null,"
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
        printf("Selecione...\n\t\t\t [A]dd  [L]ist  [D]elete  [U]pdate  [Q]uite\n>>>");
        if ((choice = getchar()) != '\n' && choice != EOF)
        {
            switch (choice)
            {
            case 'a':
            case 'A':
                system("clear");
                add(db);
                break;

            case 'q':
            case 'Q':
                return 0;

            case 'l':
            case 'L':
                list(db);
                break;
            
            case 'd':
            case 'D':
                system("clear");
                delete(db);
                break;

            case 'u':
            case 'U':
                system("clear");
                update(db);
            
            default:
                break;
            }
        }
        
    }
    

    return 0;
}

int add(sqlite3 * db)
{
    char nomeatual[50];
    char cpf[11];
    char sql[256];
    int c;

    printf("Digite o nomeatual do cliente\n>>> ");

    // limpar o buffer do stdin
    if ((c = getchar()) != 'n' && c != EOF);


    fgets(nomeatual,sizeof(nomeatual), stdin);
    nomeatual[strcspn(nomeatual, "\n")] = '\0';
    pulalinha

    printf("Digite o cpf do cliente\n>>> ");

    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    snprintf(sql, sizeof(sql), "insert into clientes (id, nome, cpf) values (null, '%s', '%s');", nomeatual, cpf);

    sqlite3_exec(db, sql, NULL, 0, NULL);

    while((c = getchar()) != '\n' && c != EOF);

    return 0;
}

int list(sqlite3 * db)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF);
    sqlite3_exec(db, "select * from clientes;", listcallback, 0, NULL);
    

    return 0;
}
int delete(sqlite3 * db)
{
    int c;
    printf("Digite o cpf do cliente que seja excluir\n>>> ");
   
    char cpf[11];
    char sql[256];

    while((c = getchar()) != '\n' && c != EOF);

    fgets(cpf, sizeof(cpf), stdin);
    (strcspn(cpf, "\n"))[cpf] = '\0';

    snprintf(sql, sizeof(sql), "delete from clientes where cpf = '%s';", cpf);

    printf("Você digitou: %s\n", cpf);
    

    sqlite3_exec(db, sql, NULL, 0, NULL);

    if (sqlite3_changes(db) == 0)
    {
        printf("Nenhuma operacao foi excutada. Verifique se o cpf digitado esta correto.\n");
    }

    printf("Deletado com SUCESSO.\n");

    while((c = getchar()) != '\n' && c != EOF);
    
    return 0;
}

int update(sqlite3 * db)
{
    char nomeatual[100];
    char nomenovo[100];
    char cpfnovo[11];

    char cpf[11];
    char sql[256];
    char sqlAux[256];

    char c;
    printf("Digite o cpf do cliente que deseja modificar.\n\n>>>");

    while((c = getchar()) != '\n' && c != EOF);
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0';

    snprintf(sqlAux, sizeof(sqlAux),"select * from clientes where cpf='%s';",cpf);

    sqlite3_exec(db, sqlAux, updatecallback, &nomeatual, NULL);

    printf("Qual campo você deseja modificar?\n[1] Nome\t[2] CPF\t [3] Cancelar\n\n>>> ");

    while((c = getchar()) != '\n' && c != EOF);
    while ((c = getchar()) != '\n' && c != EOF)
    {
        switch (c)
        {
        case '2':
            printf("Digite o novo cpf para [%s].\n>>> ", nomeatual);
            while((c = getchar()) != '\n' && c != EOF);
            fgets(cpfnovo,sizeof(cpfnovo), stdin);
            cpfnovo[strcspn(cpfnovo, "\n")] = '\0';
            snprintf(sql, sizeof(sql), "update clientes set cpf='%s' where cpf='%s';", cpfnovo, cpf);
            sqlite3_exec(db, sql, NULL, 0, NULL);

            if (sqlite3_changes(db) == 0)
            {
                printf("Nenhuma operacao foi excutada. Verifique se o cpf digitado esta correto.\n");
                break;
            }

            printf("CPF alterado com sucesso.");

            break;
        case '1':
            printf("Digite o novo nome para [%s].\n>>> ", nomeatual);
            while((c = getchar()) != '\n' && c != EOF);
            fgets(nomenovo, sizeof(nomenovo), stdin);
            nomenovo[strcspn(nomenovo, "\n")] = '\0';
            snprintf(sql, sizeof(sql), "update clientes set nome='%s' where cpf='%s';", nomenovo, cpf);
            sqlite3_exec(db, sql, NULL, 0, NULL);

            if (sqlite3_changes(db) == 0)
            {
                printf("Nenhuma operacao foi excutada. Verifique se o cpf digitado esta correto.\n");
                break;
            }

            printf("Nome alterado com sucesso.");
            break;

        default:
            break;
        }
    }    

    return 0;
}
