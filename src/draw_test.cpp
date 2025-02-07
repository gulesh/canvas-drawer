#include <iostream>
#include "canvas.h"

using namespace agl;
using namespace std;

void test_line(canvas& drawer, int ax, int ay, int bx, int by, const std::string& savename)
{
   drawer.background(0, 0, 0);
   drawer.begin(LINES);
   drawer.vertex(ax, ay);
   drawer.vertex(bx, by);
   // drawer.width(4);
   drawer.end();
   drawer.save(savename);
}

int main(int argc, char** argv)
{
   canvas drawer(100, 100);


   drawer.color(255, 255, 255); 
   // test_line(drawer, 0, 50, 100, 50, "horizontal-line.png");
   // test_line(drawer, 50, 0, 50, 100, "vertical-line.png");
   // test_line(drawer, 0, 0, 100, 100, "diagonal-line-1.png"); // slope = 1 (no error but not increasing the width)
   // test_line(drawer, 25, 10, 75, 25,  "h-lessthan-w-line-1.png"); // slope H < W
   // test_line(drawer, 25, 25, 75, 75,  "w-lessthan-h-line-1.png"); // slope W < H (no error but not increasing the width)
   // test_line(drawer, 0, 100, 100, 0, "diagonal-line-2.png"); // slope H < W
   // test_line(drawer, 25, 90, 75, 75,  "h-lessthan-w-line-2.png"); // slope H < W
   // test_line(drawer, 25, 90, 75, 25,  "w-lessthan-h-line-2.png"); // slope W < H 55545464
   

   //  // testing Point
   // drawer.background(0, 0, 0);
   // drawer.begin(POINT);
   // drawer.vertex(50, 50); 
   // drawer.color(255, 0, 255); 
   // drawer.vertex(50, 75); 
   // drawer.color(255, 0, 255); 
   // drawer.vertex(50, 85); 
   // drawer.color(255, 0, 255); 
   // drawer.vertex(50, 95); 
   // drawer.color(255, 0, 255); 
   // drawer.vertex(50, 65); 
   // drawer.color(255, 0, 255); 
   // drawer.end();
   // drawer.save("points-draw.png");

   // // testing star
   // drawer.background(0, 0, 0);
   // drawer.begin(STARS);
   // drawer.vertex(50, 50); // center vertex of circle which is used to draw star
   // drawer.color(255, 0, 255); // this acts as edge color which can then be used for interpolation
   // drawer.radius(15);
   // drawer.fillType(0);
   // drawer.end();
   // drawer.save("unfilled-star-draw.png");

   // testing curves
   drawer.background(0, 0, 0);
   drawer.begin(CURVES);
   drawer.color(0, 255, 255); //this is the center color
   drawer.vertex(50, 50);
   drawer.color(255, 0, 255); // this acts as edge color which can then be used for interpolation
   drawer.radius(15);
   drawer.setK(4);
   drawer.setTheta(2*3.14);
   drawer.fillType(0);
   drawer.end();
   drawer.save("curves-unfilled-interpolation.png");

   // drawer.background(0, 0, 0);
   // drawer.begin(CIRCLES);
   // drawer.color(0, 255, 255); //this is the center color
   // drawer.vertex(50, 50);
   // drawer.color(0, 255, 255); // this acts as edge color which can then be used for interpolation
   // drawer.radius(15);
   // drawer.fillType(0);
   // // drawer.setK(2.7);
   // // drawer.setTheta(20*3.14);
   // drawer.end();
   // drawer.save("circle-unfilled.png");

   // // testing unfilledrectangle
   // drawer.background(0, 0, 0);
   // drawer.begin(RECTANGLES);
   // drawer.color(0, 255, 255); //this is the center color
   // drawer.vertex(50, 50);
   // drawer.color(255, 0, 255); // this acts as edge color which can then be used for interpolation
   // drawer.recHW(30, 30);
   // drawer.fillType(0);
   // drawer.end();
   // drawer.save("rectangle-unfilled-interpolation.png");

   // // test line interpolation
   // drawer.background(0, 0, 0);
   // drawer.begin(LINES);
   // drawer.color(255, 0, 255); 
   // drawer.vertex(0, 0);
   // drawer.color(0, 255, 255);
   // drawer.vertex(100, 100);
   // drawer.end();
   // drawer.save("line-color-interpolation.png");

   // // test triangle with unfilled
   // drawer.background(0, 0, 0);
   // drawer.begin(TRIANGLES);
   // drawer.color(255, 0, 255);
   // drawer.vertex(10, 0);
   // drawer.color(0, 255, 255);
   // drawer.vertex(90, 50);
   // drawer.color(255, 255, 0);
   // drawer.vertex(10, 90);
   // drawer.fillType(1);
   // drawer.end();
   // drawer.save("unfilled-triangle.png");

   // // test triangle with interpolation
   // drawer.background(0, 0, 0);
   // drawer.begin(TRIANGLES);
   // drawer.color(255, 0, 255);
   // drawer.vertex(10, 10);
   // drawer.vertex(10, 90);
   // drawer.vertex(90, 90);

   // drawer.color(255, 255, 0);
   // drawer.vertex(90, 90);
   // drawer.vertex(90, 10);
   // drawer.vertex(10, 10);
   // drawer.end();
   // drawer.save("quad.png");
   

   return 0;
}
