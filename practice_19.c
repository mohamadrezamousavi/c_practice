#include <stdio.h>
#include <math.h>

#define PI 3.141592653589793

int main()
{
    FILE *fp = fopen("sine.csv", "w");

    double f = 10e6;          // 50 MHz
    double Ts = 10e-9;        // Sampling period (10 ns)

    fprintf(fp, "time,sample\n");

    for (int i = 0; i < 10; i++)
    {
        double t = i * Ts;
        double sample = sin(2 * PI * f * t);

        fprintf(fp, "%.2e,%f\n", t, sample);
    }

    fclose(fp);

    printf("Data saved to sine.csv\n");

    return 0;
}