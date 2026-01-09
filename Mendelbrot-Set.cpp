#include <iostream>
#include "CImg.h"

using namespace std;
using namespace cimg_library;

class complex {
public: complex(double a = 0, double b = 0) {}

		complex operator* (const complex& c) {
		complex product; 
		product.a = this->a * c.a - this->b * c.b;
		product.b = this->a * c.b + this->b * c.a;
		return product;
		}
		complex operator+ (const complex& c) {
			complex sum;
			sum.a = this->a + c.a;
			sum.b = this->b + c.b;
			return sum;
		}

	double a;
	double b;
};

unsigned char color[] = {0,0,0};
unsigned char white[] = {255,255,255};

CImg<unsigned char>image(800, 800, 1, 3);
CImgDisplay display(image, "Mendelbrot set?");

int function(complex, complex, int);
void loop(int, int);

double pixel[800][800];
double x[800]; 
double y[800]; 
complex c, z;

int main() {

image.draw_rectangle(0, 0, 800, 800, white);
display.render(image);
display.paint();

for (int i = 0; i < 800; i++) { for (int j = 0; j < 800; j++) pixel[i][j] = 0; }
for (int i = 0; i < 800; i++) x[i] = (i-400)/2*0.01;
for (int j = 0; j < 800; j++) y[j] = (j-400)/2*0.01;

loop(0,0);

display.render(image);
display.paint();

system("PAUSE");
return 0;
}

void loop (int i, int j) {
	while (i < 800) { 
		while (j < 800) {
		c.a = x[i]; c.b = y[j];
		z.a = 0; z.b = 0;
		pixel[i][j] = function(c, z, 0);
		color[0] = pixel[i][j]; color[1] = pixel[i][j]; color[2] = pixel[i][j];
		image.draw_rectangle(i,j,i+1,j+1,color); 
		display.render(image);
		display.paint();
		j++; }
	i++; j = 0; }
}

int function (complex c, complex z, int counter) {
	z = (z*z) + c;
	counter++;
	if (z.a + z.b > 800 || z.a + z.b < -800) { cout<<""; return counter; }
	if (counter >= 255) { cout<<""; return counter; }
	function(c, z, counter);
}

