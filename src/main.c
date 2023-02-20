/*
** EPITECH PROJECT, 2023
** WorkshopCLion
** File description:
** main.c
*/

#include <stdio.h>

#include "utils.h"

int main(int argc, char **argv)
{
    int list[] = {5, 1, 42, 9, 5, 32, 49, 32, 22, 67};
    float *res = compute(0.0001f, list);
    printf("%f", *res);
    return 0;
}
