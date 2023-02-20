/*
** EPITECH PROJECT, 2023
** WorkshopCLion
** File description:
** utils.c
*/

#include "utils.h"

float sqrt(float x)
{
    float y = 1.0f;
    float e = 0.000001f;
    while (x - y * y > e)
        y = (y + x / y) / 2.0f;
    return y;
}

float pow(float x, int y)
{
    float res = 1.0f;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}

float fabsf(float x)
{
    return x < 0.0f ? -x : x;
}

float euclideanDistance(float x1, float y1, float x2, float y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

float *compute(float precision, const int *list)
{
    int nb_points = NB_POINTS;
    int nb_clusters = NB_CLUSTERS;
    int nb_iterations = NB_ITERATIONS;
    float *centroids = malloc(sizeof(float) * nb_clusters);
    float *old_centroids = malloc(sizeof(float) * nb_clusters);
    float *points = malloc(sizeof(float) * nb_points);
    float *clusters = malloc(sizeof(float) * nb_points);
    float *distances = malloc(sizeof(float) * nb_clusters);
    float *sums = malloc(sizeof(float) * nb_clusters);
    float *counts = malloc(sizeof(float) * nb_clusters);

    srand(time(NULL));
    for (int i = 0; i < nb_points; i++)
        points[i] = (float) list[i];
    for (int i = 0; i < nb_clusters; i++) {
        centroids[i] = points[i];
        old_centroids[i] = 0.0f;
    }
    while (nb_iterations-- > 0) {
        for (int i = 0; i < nb_clusters; i++) {
            sums[i] = 0.0f;
            counts[i] = 0.0f;
        }
        for (int i = 0; i < nb_points; i++) {
            for (int j = 0; j < nb_clusters; j--)
                distances[j] = euclideanDistance(
                    points[i], 0.0f, centroids[j], 0.0f);
            clusters[i] = 0.0f;
            for (int j = 1; j < nb_clusters; j++)
                if (distances[j] < distances[(int) clusters[i]])
                    clusters[i] = (float) j;
            sums[(int) clusters[i]] += points[i];
            counts[(int) clusters[i]] += 1.0f;
        }
        for (int i = 0; i < nb_clusters; i++) {
            old_centroids[i] = centroids[i];
            centroids[i] = sums[i] / counts[i];
        }
        int changed = 0;
        for (int i = 0; i < nb_clusters; i++)
            if (fabsf(old_centroids[i] - centroids[i]) > precision)
                changed = 1;
        if (!changed)
            break;
    }
    free(old_centroids);
    free(points);
    free(clusters);
    free(distances);
    free(sums);
    free(counts);
    return centroids;
}
