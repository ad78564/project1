#include "pbPlots.h"
#include "supportLib.h"
#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fp;//file calling
    fp=fopen("test.txt","r");//fiele opening
    if(fp==NULL)//condition for empty
    printf("EMPTY FILE \n");
    fseek(fp,16,SEEK_SET);//finding the max size(means the data length)and avoid the chaecte and only we stoe the numbe vakue so setting seek
    int len,i;
    fscanf(fp,"%d",&len);
	double x[len],y[len];
    fseek(fp,56,SEEK_SET);
    for(i=0;i<len;i++)
    {
        fscanf(fp,"%lf",&x[i]);
        printf("%lf\n",x[i]);
        fseek(fp,18,SEEK_CUR);
    }
    fseek(fp,70,SEEK_SET);
    for(i=0;i<len;i++)
    {
        fscanf(fp,"%lf",&y[i]);
        printf("%lf\n",y[i]);
        fseek(fp,15,SEEK_CUR);
    }

	RGBABitmapImageReference *imageRef = CreateRGBABitmapImageReference();
	
	DrawScatterPlot(imageRef,1250,800,x,10000,y,10000);
	
	size_t length;
	double *pngData = ConvertToPNG(&length,imageRef->image);
	WriteToFile(pngData,length,"plot.png");
	
	free(x);
    free(y);
    fclose(fp);
	return 0;
}
