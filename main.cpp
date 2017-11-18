#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "bitmap.h"

using namespace std;

Bitmap image;
vector <vector <Pixel> > bmp;
vector <vector <vector <Pixel> > > combo;
Pixel rgb;

vector <vector<vector <Pixel> > > getImages()
{
	vector <vector <vector <Pixel> > > comboTest
	string imageName;
	int imageNumber;
	bool stop;
	int row;
	int col;
	int j, k;

	row = 0;
	col = 0;
	imageNumber = 0;

	stop = false;

	while (stop == false);
	{
		cin >> imageName;

		if (imageName == "DONE" || imageNumber == 10)
		{
			stop = true;
		}
		if (imageName == "DONE" && imageNumber < 2)
		{
			cout << "composite image cannot be created" << endl;
		}
		else
		{
			image.open(imageName);

			bool validBmp = image.isImage();

			if (validBmp == true)
			{
				bmp = image.toPixelMatrix();

				if (row == 0)
				{
					row = bmp.size();
					col = bmp[0].size();

					for (j = 0; j < row; j++)
					{
						for (k = 0; k < col; k++)
						{
							comboTest[imageNumber][j][k] = bmp[j][k];

							imageNumber++;
						}
					}
				}
				if (row == bmp.size() && col == bmp[0].size())
				{
					for (j = 0; j < row; j++)
					{
						for (k = 0; k < col; k++)
						{
							comboTest[imageNumber][j][k] = bmp[j][k];

							imageNumber++;
						}
					}
				}
				else
				{
					cout << "file isn't the same dimensions as the first image loaded. Try again" << endl;
				}
			}

			else
			{
				cout << "file doesn't exist or isn't a valid bitmap. Try again" << endl;
			}
		}
	}
		return comboTest;
}

vector <vector <Pixel> > createComp(vector <vector <vector <Pixel> > > a)
{
	for (int i = 0; i < a[0][0].size(); i++)
	{
		for (int j = 0; j < a[0].size(); j++)
		{
			for (int k = 0; k < a.size(); k++)
			{
				rgb = a[i][j][k];
					
				rgb.red = rgb.red / a[0][0].size();
				rgb.green = rgb.green / a[0][0].size();  //need to fix
				rgb.blue = rgb.blue / a[0][0].size();

				bmp[j][k] = rgb
					
			}
		}
	}
}

int main()
{
	cout << "Enter the names of the files you want to use to create a composite" << endl;
	combo = getImages();
	

	createComp(combo);


	return 0;
}
