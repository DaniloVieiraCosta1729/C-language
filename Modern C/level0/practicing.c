#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#define sr(x,n) (x >> n) 
#define LOG2_OF_E 1.4426950408889634
#define REMOVE_SIGN 0b011111111111
#define BIAS 1023
#define log_2(x) ( (((sr(x,52)) & (REMOVE_SIGN)) - BIAS) / LOG2_OF_E)
#define sum_squares(x, y) (x*x + y*y)

int main(int argc, char const *argv[])
{
    // using a struct without labeling it.

    struct 
    {
        double x;
        double y;

        double norm;
    } v1, v2;

    v1.x = 45.2;
    v1.y = 62.1;
    double n = sum_squares(v1.x,v1.y);

    v1.norm = exp( 0.5 * log_2(*(int64_t *)&n)/LOG2_OF_E );

    printf("%lf vs %lf\n", v1.norm, sqrt(sum_squares(v1.x, v1.y)));

















    // tests
    printf("%d\n",sr(32,2));

    union
    {
        double x;
        int64_t y;
    } mascara;
    
    mascara.x = -49.0;

    //int64_t y = mascara.y;

    /*

    int64_t y = *(int64_t *)&mascara.x;

    int shift;

    printf("%lld\n", y);

    if (argv[1] == NULL)
    {
        shift = 0;
    } else
    {
        shift = atoi(argv[1]);
    }
    printf("%d\n", shift);
    printf("%lld\n", y >> shift);

    int64_t m = 0b011111111111;

    printf("%lld\n", ((m)&(sr(y,shift))-1023));

    */

    return 0;
}
