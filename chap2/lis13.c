#include <stdio.h>

#define VMAX 21

typedef struct {
  char    name[20];
  int     height;
  double  vision;
} PyhsCheck;

double ave_height(const PyhsCheck dat[], int n)
{
  double sum = 0;
  for (int i = 0; i < n; i++)
    sum += dat[i].height;
  return sum / n;
}

void dist_vision(const PyhsCheck dat[], int n, int dist[])
{
  for (int i = 0; i < VMAX; i++)
    dist[i] = 0;
  for (int i = 0; i < n; i++)
    if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX / 10.0)
      dist[(int)(dat[i].vision * 10)]++;
}