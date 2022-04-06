/**
* @file image_copy.c
* @brief This programs opens a BMP image, reads the header, colortable, and image data
	and stores it in a new file. Makes a copy of the image.
* @author Abhijit Nathwani
* @version v0.1
* @date 2017-12-19
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void render_ascii(unsigned char *c, int w, int h)
{
	int i;
	int j;
	float eq;

	i = 0;
	j = 0;

	while (j < h)
	{
		while (i < w)
		{
			eq = c[i, j];// / 256;
			//printf("%d/%d;", i, j);
			printf("%1.f/;", eq);
			i++;
		}
		i = 0;
		printf("#\n");
		j++;
	}

}

int main(int argc,char *argv[])
{
	clock_t start, stop; 

	start=clock(); // Note the start time for profiling purposes.

	FILE *fo = fopen("/root/42/courses/git-priv/visuascii/imgout/udu.bmp","wb"); // Output File name

	int i;

	FILE *streamIn; 
	streamIn = fopen("s43rgb.bmp", "r"); // Input file name
	//streamIn = fopen("udu_80-76.bmp", "r"); // Input file name
	////streamIn = fopen("www.bmp", "r"); // Input file name
	printf("\np*: %p\n", streamIn);
        if (streamIn == NULL) // check if the input file has not been opened succesfully.
	{
		perror("Error");
            printf("File opening error ocurred. Exiting program.\n");
            exit(0);
 	}

 	unsigned char header[54]; // to store the image header
	unsigned char colorTable[1024]; // to store the colorTable, if it exists.


 	int count = 0;
 	for(i=0;i<54;i++) 
 	{
 		header[i] = getc(streamIn);  // strip out BMP header
		printf("%c ", header[i]);
 	}
 	int width = *(int*)&header[18]; // read the width from the image header
 	int height = *(int*)&header[22]; // read the height from the image header
	int bitDepth = *(int*)&header[28]; // read the bitDepth from the image header
printf("width/height: %d/%d | \n", width, height);
//exit(0);	
	//int pixels[10][5][3];
	int pixels[width][height][3];
	int pi, pj;

	for(pj=0; pj<height; pj++)
	{
		for(pi=0; pi<width; pi++)
		{
			pixels[pi][pj][0] = getc(streamIn);
			pixels[pi][pj][1] = getc(streamIn);
			pixels[pi][pj][2] = getc(streamIn);
printf(":%d/%d/%d;", pixels[pi][pj][2], pixels[pi][pj][1], pixels[pi][pj][0]);
		}
printf("\n");
		pi=0;
	}

	fwrite(header, sizeof(unsigned char), 54, fo); // write the image header to output file
  	
 	unsigned char buf[height * width]; // to store the image data

	fread(buf, sizeof(unsigned char), (height * width), streamIn);
	fwrite(buf, sizeof(unsigned char), (height * width), fo);
//printf("=%0X/%d", buf[0,0], buf[0,0]);
//printf("=%0X/%d", buf[40,35], buf[40,35]);
//printf("=%0X/%d", buf[41,35], buf[41,35]);
 
	render_ascii(buf, width, height);

	fclose(fo);
 	fclose(streamIn);

	stop = clock(); 
	
	printf("Time: %lf ms\n",((double)(stop - start) * 1000.0 )/ CLOCKS_PER_SEC);

}
