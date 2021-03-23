#include <iostream>
#include "canvas.h"
using namespace std;
using namespace agl;

void randomCircle(canvas& drawer, int rx, int ry , int radius, const std::string& savename)
{  int count = 1;
      drawer.begin(CIRCLES);
      drawer.color(86,54,167);
      drawer.vertex(rx, ry); 
      drawer.color(250, 200, 255);
      drawer.radius((radius - 5));
      drawer.fillType(1);
      drawer.end();
      drawer.begin(STARS);
      drawer.color(0, 255, 255);
      drawer.vertex(rx, ry); 
      drawer.color(250, 0, 255);
      drawer.radius((radius-5));
      drawer.fillType(0);
      drawer.end();
   
   while(count < 10)
   {
      drawer.begin(RECTANGLES);
      drawer.color(55,31,84); //this is the center color
      drawer.vertex(rx , ry);
      drawer.recHW(radius + 50 + count, radius + 50 + count);
      drawer.width(count);
      drawer.fillType(0);
      drawer.end();
      radius = radius + 10;
      count++;
      
   }
      drawer.save(savename);
}

void drawVerticalLines(canvas& drawer, const std::string& savename)
{
   for (int i = 0 ; i < drawer.getWidthCanvas(); i+=5)
   {
   drawer.begin(LINES);
   drawer.color(255, 0, 255); 
   drawer.vertex(i, 0);
   drawer.color(0, 255, 255);
   drawer.vertex(i, drawer.getHeightCanvas());
   drawer.width(3);
   drawer.end();
   }
   drawer.save(savename);

}

void drawConnectedTriangles(canvas& drawer, int centerx, int centery, int xdistance, int ydistance, const std::string& savename)
{
   drawer.begin(TRIANGLES);
   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx, centery - ydistance);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx + 20, centery - ydistance);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx, centery - ydistance);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx - 20, centery - ydistance);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx - xdistance, centery);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx - xdistance, centery - 20);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx - xdistance, centery);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx - xdistance, centery + 20);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx, centery + ydistance);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx + 20, centery + ydistance);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx, centery + ydistance);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx - 20, centery + ydistance);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx + xdistance, centery);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx + xdistance, centery - 20);

   drawer.color(255, 0, 255);
   drawer.vertex(centerx, centery);
   drawer.color(0, 255, 255);
   drawer.vertex(centerx + xdistance, centery);
   drawer.color(255, 255, 0);
   drawer.vertex(centerx + xdistance, centery + 20);

   drawer.fillType(1);
   drawer.end();
   drawer.save(savename);

}

void runningSpiralFunction(canvas& drawer)
{
   drawer.background(15,65,103);
   drawConnectedTriangles(drawer,100, 100, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,150, 150, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,200, 50, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,250, 250, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,135, 300, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,600, 190, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,540, 290, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,320, 190, 50, 50, "spiral-using-triangles.png");

   drawConnectedTriangles(drawer,0, 0, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,630, 0, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,630, 350, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,0, 350, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,400, 350, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,300, 290, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,270, 290, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,10, 190, 50, 50, "spiral-using-triangles.png");
   
   drawConnectedTriangles(drawer,550, 30, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,400, 20, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,450, 60, 50, 50, "spiral-using-triangles.png");

   drawConnectedTriangles(drawer,500, 150, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,500, 200, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,500, 100, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,390, 50, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,300, 50, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,400, 50, 50, 50, "spiral-using-triangles.png");
   drawConnectedTriangles(drawer,370, 620, 50, 50, "spiral-using-triangles.png");

}

void curveInsideRec(canvas& drawer, int ceterx, int centery)
{
   drawer.begin(RECTANGLES);
   drawer.color(0, 255, 255); //this is the center color
   drawer.vertex(ceterx, centery);
   drawer.color(179,172,100); // this acts as edge color which can then be used for interpolation
   drawer.recHW(30, 30);
   drawer.width(0);
   drawer.fillType(1);
   drawer.end();
   drawer.save("mixFilters.png");

   drawer.begin(CURVES);
   drawer.color(0, 255, 255); //this is the center color
   drawer.vertex(ceterx, centery);
   drawer.color(178,0,0); // this acts as edge color which can then be used for interpolation
   drawer.radius(15);
   drawer.fillType(1);
   drawer.setK(4);
   drawer.setTheta(2*3.14);
   drawer.end();
   drawer.save("mixFilters.png");

}

void runningCurveFunction(canvas& drawer)
{
   curveInsideRec(drawer, 100 , 50);
   curveInsideRec(drawer, 100 , 100);
   curveInsideRec(drawer, 150 , 50);
   curveInsideRec(drawer, 150 , 100);
   curveInsideRec(drawer, 150 , 50);
   curveInsideRec(drawer, 200 , 50);
   curveInsideRec(drawer, 200 , 100);
   curveInsideRec(drawer, 250 , 150);
   curveInsideRec(drawer, 250 , 200);
   curveInsideRec(drawer, 300 , 50);
   curveInsideRec(drawer, 350 , 100);
   curveInsideRec(drawer, 350 , 150);

   curveInsideRec(drawer, 100 , 250);
   curveInsideRec(drawer, 100 , 300);
   curveInsideRec(drawer, 100 , 350);
   curveInsideRec(drawer, 150 , 250);
   curveInsideRec(drawer, 150 , 300);
   curveInsideRec(drawer, 150 , 350);
   curveInsideRec(drawer, 200 , 250);
   curveInsideRec(drawer, 200 , 300);
   curveInsideRec(drawer, 250 , 350);
   curveInsideRec(drawer, 600 , 250);
   curveInsideRec(drawer, 600 , 300);
   curveInsideRec(drawer, 600 , 350);

}

void drawHorizontalLines(canvas& drawer, const std::string& savename)
{
   for (int i = 0 ; i < drawer.getHeightCanvas(); i+=5)
   {
   drawer.begin(LINES);
   drawer.color(69,112,69); 
   drawer.vertex(0, i);
   drawer.color(67,7,43);
   drawer.vertex(drawer.getWidthCanvas(), i);
   drawer.width(3);
   drawer.end();
   }
   drawer.save(savename);

}
int main(int argc, char** argv)
{
   canvas drawer(640, 380);
   drawer.background(251,251,244);
   drawVerticalLines(drawer,  "drawing-rectangles-circles.png");
   randomCircle(drawer, 320, 190, 60, "drawing-rectangles-circles.png");
   runningSpiralFunction(drawer);
   drawer.background(251,251,244);
   drawer.background(0,0,0);
   drawHorizontalLines(drawer, "mixFilters.png");
   drawVerticalLines(drawer,  "mixFilters.png");
   runningCurveFunction(drawer);
   

   


   

   // drawer.background(200, 100, 50);

}

