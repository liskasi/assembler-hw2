#include <stdio.h>
#include <stdlib.h>
#include "matmul.h"

int main()
{
    int h1, w1, h2, w2;

    FILE *inputFile = fopen("input.txt", "r");

//    if (inputFile == NULL)
//    {
//        fprintf(stderr, "Could not open the file.\n");
//        return 1;
//    }

    fscanf(inputFile, "%d", &h1);
    fscanf(inputFile, "%d", &w1);

    int *m1 = (int *)malloc(h1 * w1 * sizeof(int));

    for (int i = 0; i < h1 * w1; i++)
    {
        fscanf(inputFile, "%d", &m1[i]);
    }

    fscanf(inputFile, "%d", &h2);
    fscanf(inputFile, "%d", &w2);

    int *m2 = (int *)malloc(h2 * w2 * sizeof(int));

    for (int i = 0; i < h2 * w2; i++)
    {
        fscanf(inputFile, "%d", &m2[i]);
    }

    fclose(inputFile);

    if (w1 != h2)
    {
        printf("1\n");
        return 1;
    }

    int *m3 = (int *)malloc(h1 * w2 * sizeof(int));
    for (int i = 0; i < h1 * w1; i++)
    {
        printf("%d ", m1[i]);
    }
    printf("\n");

    for (int i = 0; i < h2 * w2; i++)
    {
        printf("%d ", m2[i]);
    }
    printf("\n");
//    printf("%d\n", h1); //2
//    printf("%d\n", w1); //3
//    printf("%d\n", h2); //3
//    printf("%d\n", w2); //4


    int result = matmul(h1, w1, m1, h2, w2, m2, m3);
    printf("%d\n", result);

//
//    if (result == 1)
//    {
//        fprintf(stderr, "Error opening output file\n");
//        return 1;
//    }
//
//    FILE *outfile = fopen("output.txt", "w");
//    if (outfile == NULL)
//    {
//        fprintf(stderr, "Error opening output file\n");
//        return 1;
//    }
//
//    fprintf(outfile, "%d %d\n", h1, w2);
//    for (int i = 0; i < h1; i++)
//    {
//        for (int j = 0; j < w2; j++)
//        {
//            fprintf(outfile, "%d ", m3[i * w2 + j]);
//        }
//        fprintf(outfile, "\n");
//    }
//
//    fclose(outfile);

    free(m1);
    free(m2);
    free(m3);

    return 0;
}
