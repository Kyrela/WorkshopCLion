/*
** EPITECH PROJECT, 2023
** WorkshopCLion
** File description:
** utils.h
*/

#ifndef WORKSHOPCLION_UTILS_H
#define WORKSHOPCLION_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NB_CLUSTERS 3
#define NB_ITERATIONS 100
#define NB_POINTS 100

float euclideanDistance(float x1, float y1, float x2, float y2);

float *compute(float precision, const int *list);

#endif //WORKSHOPCLION_UTILS_H
