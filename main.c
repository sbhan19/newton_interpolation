/*Newton's Forward Interpolation*/
#include<stdio.h>

int main()
{
    float ax[100],ay[100],diff[100][100],nr=1.0,dr=1.0,x,p,h,yp;
    int n,i,j,k;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    printf("Enter the values in form of (x,y) \n");
    for(i=0;i<n;i++)
        scanf("%f %f",&ax[i],&ay[i]);
    printf("Enter the values of x for which the value of y is wanted \n");
    scanf("%f",&x);
    h=ax[1]-ax[0];
    /*Making the difference table*/
    /*Calculating the first order difference*/
    for(i=0;i<=n;i++)
        diff[i][1]=ay[i+1]-ay[i];
    /*Calculating the second and higher order differences*/
    for(j=2;j<=ORDER;j++)
    {
        for(i=0;i<=n;i++)
            diff[i][j]=diff[i+1][j-1]-diff[i][j-1];
    }
    /*Now finding x0*/
    i=0;
    while(!(ax[i]>x)) i++;
    /*Now ax[i] is x0 and ay[i] is y0*/
    i--;
    p=(x-ax[i])/h; yp=ay[i];
    /*Now carrying out interpolation*/
    for(k=1;k<=ORDER;k++)
    {
        nr *=p-k+1; dr *=k;
        yp+=(nr/dr)*diff[i][k];
    }
    printf("When x=%f, y=%f \n",x,yp);
    return 0;
}
