#include <stdint.h>
extern int mostra(int x);
extern int soma(int x, int y);

int main(int argc, char const *argv[])
{
    int32_t x;
    x = soma(15,3);
    mostra(x);
    return 0;
}
