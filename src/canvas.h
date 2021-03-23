#ifndef canvas_H_
#define canvas_H_
#include <string>
#include <vector>
#include "ppm_image.h"
namespace agl
{
   enum PrimitiveType {UNDEFINED, LINES, TRIANGLES, CIRCLES,RECTANGLES, STARS, POINT, CURVES};
   enum Mode {ADD, DIFFERENCE, MULTIPLY, ALPHABLEND};
   struct point
   {
      int x;
      int y;
      ppm_pixel colorPoint;
   };
   class canvas
   {
   public:
      canvas(int w, int h);
      virtual ~canvas();
      // Save to file
      void save(const std::string& filename);
      // Draw primitives with a given type (either LINES or TRIANGLES)
      // For example, the following draws a red line followed by a green line
      // begin(LINES);
      //    color(255,0,0);
      //    vertex(0,0);
      //    vertex(100,0);
      //    color(0,255,0);
      //    vertex(0, 0);
      //    vertex(0,100);
      // end();
      void begin(PrimitiveType type);
      void end();
      int getWidthCanvas();
      int getHeightCanvas();
      // Specifiy a vertex at raster position (x,y)
      // x corresponds to the column; y to the row
      void vertex(int x, int y);
      //r is the radius of a circle
      void radius(int r);
      //set width and height of rectangle
      void recHW(int w, int h);
      //setting width of a line
      void width(int r);
      //set fill type
      void fillType(int fill);
      //set Mode enum Type
      void setMode(Mode modeType);
      //set the k for curves
      void setK(float value);
      //set angle for curves
      void setTheta(float value);
      // Specify a color. Color components are in range [0,255]
      void color(unsigned char r, unsigned char g, unsigned char b);
      // Fill the canvas with the given background color
      void background(unsigned char r, unsigned char g, unsigned char b);
      //draw line
      void drawLine(int x1, int y1, int x2, int y2, ppm_pixel& colorbegin, ppm_pixel& colorend);
      //interpolation color calculator
      ppm_pixel interpolationColor(ppm_pixel& color1, ppm_pixel& color2, float t);
      //filling triangle
      void barycentricFill(point& a, point& b,  point& c);
      //unfilled triangles
      void barycentricUnFill(point& a, point& b,  point& c);
      //draw circle
      void drawCircle(point& center, int radius, ppm_pixel& colorEdge);
      //draw unfilled circles
      void drawUnfilledCircle(point& center, int radius, ppm_pixel& colorEdge);
      //draw rose and other curves
      void drawCurves(point& curcenter, int curradius, int k,  float angle,  ppm_pixel& colorEdge);
      //unfilled curves
      void drawUnfilledCurves(point& curcenter, int curradius, int k,  float angle,  ppm_pixel& colorEdge);
      //draw start method
      void drawStar(point& center, int radius);
      //draw unfilled star
      void drawUnfilledStar(point& center, int radius);
      //point primitive
      void drawPoint(point& verPoint);
      //draw rectangle method
      void drawRectangle(point& reccenter, int width, int height, ppm_pixel& coloredges);
      //unfilled rec
      void drawUnFilledRectangle(point& reccenter, int width, int height, ppm_pixel& coloredges);
      //method for clamping point 
      point clampPoint(int x, int y);
   private:
      ppm_image _canvas;
      PrimitiveType shapeType;
      Mode mode;
      std::vector<point> points;
      int circleRadius; // this is for circles
      int recWidth; //rectangle width 
      int recHeight; //rectangle height 
      float curvetheta; //pi value for curves
      int k = 0; //setting k for curves 
      int widthLine = 0; 
      int filled = 0; //this will allow user to draw filled or outlined shapes
      ppm_pixel backGroundPixel; //this will hold the background color
      ppm_pixel fillColor; //this is the color user set to be used to fill the pixels. It changes when user change color.
   };
}
#endif