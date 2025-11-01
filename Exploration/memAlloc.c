#include <stdio.h>
#include <assert.h>
#include <string.h>

typedef double temperatura;

typedef struct player
{
    char name[50];
    int xp;
    double mana;
    double health;
    double stamina;
} player_t;

player_t create_player(char * name)
{
    player_t newPlayer;

    strcpy(newPlayer.name, name);
    newPlayer.xp = 0;
    newPlayer.mana = 100;
    newPlayer.health = 100;
    newPlayer.stamina = 100;

    return newPlayer;
}


double * squarePointer(double * p)
{
    *p = (*p)*(*p);
    return p;
}

int main(int argc, char const *argv[])
{
    double x;
    x = 4;
    double * xp = &x;

    printf("x: %lf\n", *xp);

    xp = squarePointer(xp);

    printf("x: %lf\n", *xp);

    temperatura y = 32.0;

    printf("%lf\n", y);

    player_t mrAlbineMan = create_player("Mr Albine Man");

    printf("Name: %s\nXp: %d\nHeath: %lf\nStamina: %lf\nMana: %lf\n", mrAlbineMan.name, mrAlbineMan.health, mrAlbineMan.stamina, mrAlbineMan.mana);

    return 0;
}
