#include <stdio.h>
#define INF 1e9+5
int main()
{
    int n;
    printf("ENTER SIZE OF ARRAY\n");
    scanf("%d",&n);

    if(n<2)
        printf("INVALID INPUTS");
    else
    {
    printf("ENTER ELEMENTS IN ARRAY\n");
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int small1=INF,small2=INF;
    for(i=0;i<n;i++)
    {
        if(arr[i]<small1)
        {
            small1=arr[i];
        }
        if(small1!=INF&&arr[i]!=small1&&small2>arr[i])
            small2=arr[i];
    }

    printf("SMALLEST ELEMENT IS %d AND ",small1);
    if(small2!=INF)
        printf("SECOND SMALLEST ELEMENT IS %d",small2);
    else
        printf("SECOND SMALLEST ELEMENT DOES NOT EXISTS");
    }
    return 0;
}
