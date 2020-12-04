#include "pbPlots.h"
#include "supportLib.h"
#include<stdio.h>
int main()
{

	double x[]={2,4,5,7,8,10,11,13,14,15,16,17};
	double y[]={1,2,3,4,5,6,7,5,3,2,1,0};
	
	RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
	
	DrawScatterPlot(imageRef,1000,800,x,12,y,12);
	
	size_t length;
	double *pngData = ConvertToPNG(&length,imageRef->image);
	WriteToFile(pngData,length,"plot4546.png");
	double a[20][20];
	int i,j;
	for(i=0;i<12;i++)
	{
		for(j=0;j<12;j++)
		{
			if(y[j]>0.5)
				{
				  a[i][j]=x,y;
				}

		}
	}
	for(i=0;i<12;i++)
	{
	for(j=0;j<12;j++)
	{
	printf("%lf\t",a[i][j]);
	}
	printf("\n");
	}
	return 0;
}