// Phubordin Poolnai 66070501040

#include <stdio.h>
#include <math.h>

struct studentData
{
    char name[100];
    float score;
};

int main()
{
    int n;
    scanf("%d", &n);

    struct studentData students[n];

    float maxScore = -1.0, minScore = 101.0;
    int maxIndex = -1, minIndex = -1;

    for (int i = 0; i < n; i++)
    {
        scanf("%s %f", students[i].name, &students[i].score);

        if (students[i].score > maxScore)
        {
            maxScore = students[i].score;
            maxIndex = i;
        }

        if (students[i].score < minScore)
        {
            minScore = students[i].score;
            minIndex = i;
        }
    }

    float sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += students[i].score;
    }
    float mean = sum / n;

    float sumSquaredDiff = 0.0;
    for (int i = 0; i < n; i++)
    {
        float diff = students[i].score - mean;
        sumSquaredDiff += diff * diff;
    }
    float sd = sqrt(sumSquaredDiff / n);

    printf("%.2f %.2f %s %s", mean, sd, students[maxIndex].name, students[minIndex].name);

    return 0;
}
