#include "canvas.h"
#include <cassert>
#include <vector>
using namespace std;
using namespace agl;

canvas::canvas(int w, int h) : _canvas(w, h)
{
}

canvas::~canvas()
{
}

void canvas::save(const std::string& filename)
{
   _canvas.save(filename);
}

void canvas::begin(PrimitiveType type)
{
   shapeType = type;
}

void canvas::end()
{
   int size = int (points.size());
   while(size > 0)
   {
     if (shapeType == LINES)
      {
         cout << "inside lines" <<endl;
         point p1 = points.back();
         int x1 = p1.x;
         int y1 = p1.y;
         ppm_pixel colorP1 = p1.colorPoint;
         points.pop_back();
         point p2 = points.back();
         int x2 = p2.x;
         int y2 = p2.y;
         ppm_pixel colorP2 = p2.colorPoint;
         points.pop_back();
         cout << "inside lines-2" <<endl;
         drawLine(x2, y2, x1, y1, colorP2, colorP1);
         size = size - 2;
      }
      else if(shapeType == TRIANGLES)
      {
         if(filled == 1)
         {
            point p1 = points.back();
            int x1 = p1.x;
            int y1 = p1.y;
            ppm_pixel colorP1 = p1.colorPoint;
            points.pop_back();
        
            point p2 = points.back();
            int x2 = p2.x;
            int y2 = p2.y;
            ppm_pixel colorP2 = p2.colorPoint;
            points.pop_back();
         
            point p3 = points.back();
            int x3 = p3.x;
            int y3 = p3.y;
            ppm_pixel colorP3 = p3.colorPoint;
            points.pop_back();

            barycentricFill(p1, p2, p3);
            size = size - 3;
         }
         else
         {
            point p1 = points.back();
            int x1 = p1.x;
            int y1 = p1.y;
            ppm_pixel colorP1 = p1.colorPoint;
            points.pop_back();
        
            point p2 = points.back();
            int x2 = p2.x;
            int y2 = p2.y;
            ppm_pixel colorP2 = p2.colorPoint;
            points.pop_back();
         
            point p3 = points.back();
            int x3 = p3.x;
            int y3 = p3.y;
            ppm_pixel colorP3 = p3.colorPoint;
            points.pop_back();
            barycentricUnFill(p1, p2, p3);
            size = size - 3;

         }
         
      }
      else if(shapeType == CIRCLES)
      {
         if (filled == 1)
         {
            point p1 = points.back();
            points.pop_back();
            int radiusC = circleRadius;
            drawCircle(p1, radiusC, fillColor);
            size = size - 1;
         }
         else
         {
            point p1 = points.back();
            points.pop_back();
            int radiusC = circleRadius;
            drawUnfilledCircle(p1, radiusC, fillColor);
            size = size - 1;
         }
         
      }
      else if(shapeType == RECTANGLES)
      {
         if(filled == 1)
         {
            point center = points.back();
            points.pop_back(); 
            int wRec = recWidth;
            int hRec = recHeight; 
            drawRectangle(center, wRec, hRec, fillColor);
            size = size - 1;

         }
         else
         {
            point center = points.back();
            points.pop_back(); 
            int wRec = recWidth;
            int hRec = recHeight; 
            drawUnFilledRectangle(center, wRec, hRec, fillColor);
            size = size - 1;  
         }

         
         
      }
      else if(shapeType == STARS)
      {
         if (filled == 1)
         {
            point center = points.back();
            points.pop_back(); 
            int radiusC = circleRadius;
            drawStar(center, radiusC);
            size = size - 1;
         }
         else
         {
            point center = points.back();
            points.pop_back(); 
            int radiusC = circleRadius;
            drawUnfilledStar(center, radiusC);
            size = size - 1;


         }
         
      }
      else if(shapeType == POINT)
      {
         point center = points.back();
         points.pop_back(); 
         drawPoint(center);
         size = size - 1;
      }
      else if(shapeType == CURVES)
      {
         if (filled == 1)
         {
            point p1 = points.back();
            points.pop_back();
            int radiusC = circleRadius;
            drawCurves(p1, radiusC, k, curvetheta, fillColor);
            size = size - 1;
         }
         else
         {
            point p1 = points.back();
            points.pop_back();
            int radiusC = circleRadius;
            drawUnfilledCurves(p1, radiusC, k, curvetheta, fillColor);
            size = size - 1;
         }
         
      }
   }
}

int canvas::getWidthCanvas()
{
   return _canvas.width();
}
int canvas::getHeightCanvas()
{
   return _canvas.height();
}
void canvas::radius(int r)
{
   circleRadius = r;
}

void canvas::fillType(int fill)
{
   filled = fill;
}

void canvas::setTheta(float theta)
{
   curvetheta = theta;
}
void canvas::setK(float value)
{
   k = value;
}
void canvas::width(int r)
{
   widthLine = r;
}

void canvas::drawPoint(point& pointPlane)
{
   _canvas.set(pointPlane.x, pointPlane.y, pointPlane.colorPoint);
}

void canvas::recHW(int w, int h)
{
   recWidth = w;
   recHeight = h;
}

void canvas::vertex(int x, int y)
{
   point temp = clampPoint( x,  y);
   points.push_back(temp);
}

point canvas::clampPoint(int xCor, int yCor)
{
   int x = xCor;
   int y = yCor;
   //clamping width
   if (x >= _canvas.width())
   {
      x= _canvas.width() - 1;
   }
   else
   {
      if( x < 0)
      {
         x = 0;
      }
   }
   //clamping height
   if (y >= _canvas.height())
   {
      y = _canvas.height() - 1;
   }
   else
   {
      if( y< 0)
      {
         y = 0;
      }
   }

   point result{x, y, fillColor};
   return result;

}

void canvas::color(unsigned char r, unsigned char g, unsigned char b)
{
   fillColor.r = r;
   fillColor.g = g;
   fillColor.b = b;
}

void canvas::background(unsigned char r, unsigned char g, unsigned char b)
{
   int height = _canvas.height();
   int width = _canvas.width();
   for (int i = 0; i < height; i++){
      for (int j = 0; j < width ; j++){
         ppm_pixel backGroundPixel {r, g, b};
          _canvas.set(i, j, backGroundPixel);
      }
   }
}

void canvas::drawLine(int x1, int y1, int x2, int y2, ppm_pixel& colorfill1, ppm_pixel& colorfill2)
{
   cout << "inside drawn line"  <<endl;
   if ( (colorfill1.r == colorfill2.r) && (colorfill1.g == colorfill2.g) && (colorfill1.b == colorfill2.b))
   {
      cout << "same color" << endl;
      if (x2 > x1)
      {
         cout << "in x2 > x1" << endl;
         if (y2 > y1)
         {
            cout << "in y2 > y1" << endl;
            int y = y1;
            int W = x2 - x1;
            int H = y2 - y1;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               _canvas.set(y, i, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(y - bottom >= 0 && i - bottom >= 0)
                     {
                        _canvas.set(y - bottom, i - bottom , colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(y + top < _canvas.height() && i + top < _canvas.width())
                     {
                        _canvas.set(y + top, i + top , colorfill1);
                     }
                     
                  }

               }
               if (F > 0)
               {
                  y++;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
         else if(y2 == y1)
         {
            // cout << "in y2 = y1" << endl;
            for (int i = x1; i <= x2 ; i++)
            {
               _canvas.set(y2, i, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(y2 - bottom > 0)
                     {
                         _canvas.set(y2 - bottom, i , colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(y2 + top < _canvas.height())
                     {
                        _canvas.set(y2 + top, i , colorfill1);
                     }
                     
                  }

               }
               
            }
         }
         else
         {
            cout << "in y2 < y1" << endl;
            int y = y1;
            int W = x2 - x1;
            int H = y1 - y2;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               _canvas.set(y, i, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(y - bottom > 0 && i - bottom > 0)
                     {
                         _canvas.set(y - bottom, i - bottom , colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(y + top < _canvas.height() && i + top < _canvas.width())
                     {
                        _canvas.set(y + top, i + top , colorfill1);
                     }
                     
                  }

               }
               if (F > 0)
               {
                  y--;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
      }
      else if (x2 == x1)
      {
         // cout << "in x2 == x1" << endl;
         if (y2 > y1)
         {
            for (int i = y1; i <= y2 ; i++)
            {
               _canvas.set(i, x2, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(x2 - bottom > 0)
                     {
                         _canvas.set(i, x2 - bottom, colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(x2 + top < _canvas.width())
                     {
                        _canvas.set(i , x2 + top,  colorfill1);
                     }
                  }

               }
            }
         }
         else
         {
            for (int i = y2; i <= y1; i++)
            {
               _canvas.set(i, x2, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(x2 - bottom > 0)
                     {
                         _canvas.set(i, x2 - bottom, colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(x2 + top < _canvas.width())
                     {
                        _canvas.set(i , x2 + top,  colorfill1);
                     }
                  }

               }
            }
         }
      }
      else
      {
         cout << "x1 > x2 case" <<endl;
         if (y1 > y2)
         {
            cout << "in y1 > y2" << endl;
            int temp = 0;
            temp = x2;
            x2 = x1;
            x1 = temp;
            cout << x1 << x2 <<endl;
            temp = y2;
            y2 = y1 ;
            y1 = temp;
            cout << y1 << y2<<endl;

            int y = y1;
            int W = x2 - x1;
            int H = y2 - y1;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               _canvas.set(y, i, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(y - bottom > 0 && i - bottom > 0)
                     {
                         _canvas.set(y - bottom, i - bottom , colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(y + top < _canvas.height() && i + top < _canvas.width())
                     {
                        _canvas.set(y + top, i + top , colorfill1);
                     }
                     
                  }

               }
               if (F > 0)
               {
                  y++;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
         else if(y2 == y1)
         {
            // cout << "in y2 == y1" << endl;
               for (int i = x2; i <= x1 ; i++)
               {
                  _canvas.set(y2, i, colorfill1);
                  if (widthLine > 0)
                  {
                     for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                     {
                        if(x2 - bottom > 0)
                        {
                           _canvas.set(y2 - bottom, i, colorfill1);
                        }
                    
                     }

                     for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                     {
                        if(x2 + top < _canvas.width())
                        {
                           _canvas.set(y2 + top , i,  colorfill1);
                        }
                     }

                  }
               }
         }
         else
         {
            // cout << "in y2 > y1" << endl;
            int temp = 0;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2 ;
            y2 = temp;
      
            int y = y1;
            int W = x2 - x1;
            int H = y1 - y2;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               _canvas.set(y, i, colorfill1);
               if (widthLine > 0)
               {
                  for (int bottom = 0; bottom < (int) (widthLine/2) + 1; bottom++)
                  {
                     if(x2 - bottom > 0)
                     {
                         _canvas.set(y - bottom, i - bottom, colorfill1);
                     }
                    
                  }

                  for (int top = 0; top < (int) (widthLine/2) + 1; top++)
                  {
                     if(x2 + top < _canvas.width())
                     {
                        _canvas.set(y + top , i + top,  colorfill1);
                     }
                  }

               }
               if (F > 0)
               {
                  y--;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
      }
   }
   else
   {
      cout << "inside interpolation lines" <<endl;
      // when the colors are different we do interpolation
      if (x2 > x1)
      {
         cout << "x2 > x1" <<endl;
         if (y2 > y1)
         {
            cout << "workning on diagonal lines" <<endl;
            int y = y1;
            int W = x2 - x1;
            int H = y2 - y1;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               float tt = ( (float) y1 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) y2 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               _canvas.set(y, i, colorfill);
               if (F > 0)
               {
                  y++;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
         else if(y2 == y1)
         {
            // cout << "in y2 == y1 interpolation" <<endl;
            int y = y1;
            int W = x2 - x1;
            int H = y2 - y1;
            for (int i = x1; i <= x2 ; i++)
            {
               float tt = ( (float) x1 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) x2 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/W);
               _canvas.set(y2, i, colorfill1);
            }
         }
         else
         {
            int y = y1;
            int W = x2 - x1;
            int H = y1 - y2;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               float tt = ( (float) y2 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) y1 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               _canvas.set(i, x2, colorfill);
               if (F > 0)
               {
                  y--;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
      }
      else if (x2 == x1)
      {
         // cout << "in x2 == x1 interpolation" <<endl;
         int y = y1;
         int W = x2 - x1;
         int H = y2 - y1;
         if (y2 > y1)
         {
            for (int i = y1; i <= y2 ; i++)
            {
               float tt = ( (float) y1 * (1 - ( ( (float) i - (float) x1) / (float) H) ) ) + ( (float) y2 * ( ((float) i - (float) x1)  / (float) H) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               _canvas.set(i, x2, colorfill);
            }
         }
         else
         {
            int y = y1;
            int W = x2 - x1;
            int H = y1 - y2;
            for (int i = y2; i <= y1; i++)
            {
               float tt = ( (float) y2 * (1 - ( ( (float) i - (float) x1) / (float) H) ) ) + ( (float) y1 * ( ((float) i - (float) x1)  / (float) H ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               _canvas.set(i, x2, colorfill);
            }
         }
      }
      else
      {
         cout << "x1 > x2" <<endl;
         if (y1 > y2)
         {
            cout << "y1 > y2" <<endl;
            int y = y2;
            int W = x1 - x2;
            int H = y1 - y2;
            int F = 2*H- W;
            for (int i = x2; i <= x1 ; i++)
            {
               float tt = ( (float) y2 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) y1 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               cout << i << y <<endl;
               _canvas.set(i, y, colorfill);
               if (F > 0)
               {
                  y++;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
         else if(y2 == y1)
         {
            int y = y1;
            int W = x1 - x2;
            int H = y1 - y2;
            for (int i = x2; i <= x1 ; i++)
            {
               float tt = ( (float) x2 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) x1 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/W);
               _canvas.set(i, y, colorfill);
            }
         }
         else
         {
            int y = y1;
            int W = x2 - x1;
            int H = y1 - y2;
            int F = 2*H- W;
            for (int i = x1; i <= x2 ; i++)
            {
               float tt = ( (float) y2 * (1 - ( ( (float) i - (float) x1) / (float) W ) ) ) + ( (float) y1 * ( ((float) i - (float) x1)  / (float) W ) );
               ppm_pixel colorfill = interpolationColor(colorfill1, colorfill2, tt/H);
               _canvas.set(i, y, colorfill);
               if (F > 0)
               {
                  y--;
                  F = F + 2 * (H-W);
               }
               else
               {
                  F = F + 2 * H;
               }
            }
         }
      }
   }
}

ppm_pixel canvas::interpolationColor(ppm_pixel& color1,ppm_pixel& color2, float point)
{
   int newRed = (int) (color1.r)  * (1 - point) + (int) color2.r * point;
   int newGreen = (int) ( color1.g)  * (1 - point) + (int) color2.g * point;
   int newBlue = (int)  (color1.b)  * (1 - point) + (int) color2.b * point;
   ppm_pixel result{(unsigned char) newRed, (unsigned char) newGreen, (unsigned char) newBlue};
   return result;
}

void canvas::barycentricFill(point& a, point& b,  point& c)
{
   int xCordinates [3] = {a.x, b.x, c.x};
   int yCordinates [3]= {a.y, b.y, c.y};
   int xMin = a.x;
   int xMax = a.x;
   int yMin = a.y;
   int yMax = a.y;
   // finding above mentioned variables
   for (int j = 0; j<3 ;j++)
   {
      //updating xMin and xMax
      if(xCordinates[j]< xMin)
      {
         xMin = xCordinates[j];
      }
      else 
      {
         if (xCordinates[j] > xMax)
         {
            xMax = xCordinates[j];
         }
          
      }
      //updating yMin and yMax
      if(yCordinates[j]< yMin)
      {
         yMin = yCordinates[j];
      }
      else 
      {
         if (yCordinates[j] > yMax)
         {
            yMax = yCordinates[j];
         }   
      }
   }

   float fAlpha = (c.y - b.y)*(a.x -  b.x) - (c.x - b.x) * (a.y - b.y); //bc equation and point a
   float fBeta = (c.y - a.y) * (b.x - a.x) - (c.x - a.x) * (b.y - a.y); //ac equation and point b
   float fGamma = (b.y - a.y)*(c.x -  a.x) - (b.x - a.x) * (c.y - a.y); //ab equation and point c

   float mAlpha = (c.y - b.y)*(-1 -  b.x) - (c.x - b.x) * (-1 - b.y); //bc equation and point a
   float mBeta = (c.y - a.y) * (-1 - a.x) - (c.x - a.x) * (-1 - a.y); //ac equation and point b
   float mGamma = (b.y - a.y)*(-1 -  a.x) - (b.x - a.x) * (-1 - a.y); //ab equation and point c


   for (int i = yMin; i <yMax; i++)
   {
      for (int j = xMin; j <xMax ;j++)
      {
         int p_x = j;
         int p_y = i;
         float alpha = ((c.y - b.y) * (p_x -  b.x) - (c.x - b.x) * (p_y - b.y)) / fAlpha;
         float beta = ((c.y - a.y) * (p_x - a.x) - (c.x - a.x) * (p_y - a.y)) / fBeta;
         float gamma = ((b.y - a.y)*(p_x -  a.x) - (b.x - a.x) * (p_y - a.y)) / fGamma;

         if (alpha >= 0 && beta >=0 && gamma >=0)
         {
            if(alpha > 0 || fAlpha * mAlpha > 0)
            {
               ppm_pixel tempPixel;
               tempPixel.r = alpha * a.colorPoint.r + beta * b.colorPoint.r + gamma * c.colorPoint.r;
               tempPixel.g = alpha * a.colorPoint.g + beta * b.colorPoint.g + gamma * c.colorPoint.g;
               tempPixel.b = alpha * a.colorPoint.b + beta * b.colorPoint.b + gamma * c.colorPoint.b;
               _canvas.set(i, j, tempPixel);

            }
            if(alpha > fBeta * mBeta > 0)
            {
               ppm_pixel tempPixel;
               tempPixel.r = alpha * a.colorPoint.r + beta * b.colorPoint.r + gamma * c.colorPoint.r;
               tempPixel.g = alpha * a.colorPoint.g + beta * b.colorPoint.g + gamma * c.colorPoint.g;
               tempPixel.b = alpha * a.colorPoint.b + beta * b.colorPoint.b + gamma * c.colorPoint.b;
               _canvas.set(i, j, tempPixel);
            }
            if(alpha > fGamma * mGamma > 0)
            {
               ppm_pixel tempPixel;
               tempPixel.r = alpha * a.colorPoint.r + beta * b.colorPoint.r + gamma * c.colorPoint.r;
               tempPixel.g = alpha * a.colorPoint.g + beta * b.colorPoint.g + gamma * c.colorPoint.g;
               tempPixel.b = alpha * a.colorPoint.b + beta * b.colorPoint.b + gamma * c.colorPoint.b;
               _canvas.set(i, j, tempPixel);
            }
         }

      }
   }

}

void canvas::barycentricUnFill(point& a, point& b,  point& c)
{
   point clampedA = clampPoint(a.x, a.y);
   point clampedB = clampPoint(b.x, b.y);
   point clampedC = clampPoint(c.x, c.y);
   drawLine(clampedA.x, clampedA.y, clampedB.x, clampedB.y, clampedA.colorPoint, clampedB.colorPoint);
   drawLine(clampedB.x, clampedB.y, clampedC.x, clampedC.y, clampedB.colorPoint, clampedC.colorPoint);
   drawLine(clampedC.x, clampedC.y, clampedA.x, clampedA.y, clampedC.colorPoint, clampedA.colorPoint);

}

//the edge color and center color can be same and different which allows to have interpolation or single coloring
void canvas::drawCircle(point& corcenter, int rcircle, ppm_pixel& colorEdge)
{
   int numSlices = 1000;
   float deltaTheta = ( 2 * 3.14 ) / numSlices;
   int r_x = corcenter.x;
   int r_y = corcenter.y;
   
   point point1;
   point1.x = r_x + rcircle;
   point1.y = r_y;
   point clampedP1 = clampPoint(point1.x, point1.y);
   // drawLine(r_x, r_y, point1.x, point1.y, corcenter.colorPoint, colorEdge);

   float theta =  deltaTheta;
   point point2;
   point2.x = (int) (rcircle *  cos(theta));
   point2.y = (int) (rcircle *  sin(theta));


   if(point2.x < 0)
   {
      point2.x = r_x + point2.x;
   }
   else
   {
      point2.x = r_x + point2.x;
   }

   if(point2.y < 0)
   {
      point2.y = r_y + point2.y;
   }
   else
   {
      point2.y = r_y + point2.y;
   }
   point clampedP2 = clampPoint(point2.x, point2.y);
   // drawLine(r_x, r_y, clampedP2.x, clampedP2.y, corcenter.colorPoint, colorEdge);
   
   barycentricFill(corcenter, clampedP1,clampedP2);
  
   
   for (int i = 1 ; i < numSlices; i++)
   {
      float theta1 = (i ) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p3, p4;
      p3.x = (int) (rcircle *  cos(theta1));
      p3.y = (int) (rcircle *  sin(theta1));

      p4.x = (int) (rcircle *  cos(theta2));
      p4.y = (int) (rcircle *  sin(theta2));

      if(p3.x < 0)
      {
         p3.x = r_x + p3.x;
         
      }
      else
      {
         p3.x = r_x + p3.x;
      }

      if(p3.y < 0)
      {
         p3.y = r_y + p3.y;
      }
      else
      {
         p3.y = r_y + p3.y;
      }


      if(p4.x < 0)
      {
         p4.x = r_x + p4.x;
      }
      else
      {
         p4.x = r_x + p4.x;
      }

      if(p4.y < 0)
      {
         p4.y = r_y + p4.y;
      }
      else
      {
         p4.y = r_y + p4.y;
      }
      point clampedP3 = clampPoint(p3.x, p3.y);
      point clampedP4 = clampPoint(p4.x, p4.y);
      clampedP3.colorPoint = colorEdge;
      clampedP4.colorPoint = colorEdge;
      // drawLine(r_x, r_y, clampedP3.x, clampedP3.y, corcenter.colorPoint, colorEdge);
      // drawLine(r_x, r_y, clampedP4.x, clampedP4.y, corcenter.colorPoint, colorEdge);
      barycentricFill(corcenter, clampedP3,clampedP4);
   }
  
}

void canvas::drawUnfilledCircle(point& corcenter, int rcircle, ppm_pixel& colorEdge)
{
   int numSlices = 1000;
   float deltaTheta = ( 2 * 3.14 ) / numSlices;
   int r_x = corcenter.x;
   int r_y = corcenter.y;
   
   point point1;
   point1.x = r_x + rcircle;
   point1.y = r_y;
   point clampedP1 = clampPoint(point1.x, point1.y);
   // drawLine(r_x, r_y, point1.x, point1.y, corcenter.colorPoint, colorEdge);

   float theta =  deltaTheta;
   point point2;
   point2.x = (int) (rcircle *  cos(theta));
   point2.y = (int) (rcircle *  sin(theta));


   if(point2.x < 0)
   {
      point2.x = r_x + point2.x;
   }
   else
   {
      point2.x = r_x + point2.x;
   }

   if(point2.y < 0)
   {
      point2.y = r_y + point2.y;
   }
   else
   {
      point2.y = r_y + point2.y;
   }
   point clampedP2 = clampPoint(point2.x, point2.y);
   // drawLine(r_x, r_y, clampedP2.x, clampedP2.y, corcenter.colorPoint, colorEdge);
   
   drawLine(clampedP1.x,clampedP1.y, clampedP2.x,clampedP2.y, clampedP1.colorPoint,clampedP2.colorPoint);
  
   
   for (int i = 1 ; i < numSlices; i++)
   {
      float theta1 = (i ) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p3, p4;
      p3.x = (int) (rcircle *  cos(theta1));
      p3.y = (int) (rcircle *  sin(theta1));

      p4.x = (int) (rcircle *  cos(theta2));
      p4.y = (int) (rcircle *  sin(theta2));

      if(p3.x < 0)
      {
         p3.x = r_x + p3.x;
         
      }
      else
      {
         p3.x = r_x + p3.x;
      }

      if(p3.y < 0)
      {
         p3.y = r_y + p3.y;
      }
      else
      {
         p3.y = r_y + p3.y;
      }


      if(p4.x < 0)
      {
         p4.x = r_x + p4.x;
      }
      else
      {
         p4.x = r_x + p4.x;
      }

      if(p4.y < 0)
      {
         p4.y = r_y + p4.y;
      }
      else
      {
         p4.y = r_y + p4.y;
      }
      point clampedP3 = clampPoint(p3.x, p3.y);
      point clampedP4 = clampPoint(p4.x, p4.y);
      clampedP3.colorPoint = colorEdge;
      clampedP4.colorPoint = colorEdge;
      // drawLine(r_x, r_y, clampedP3.x, clampedP3.y, corcenter.colorPoint, colorEdge);
      // drawLine(r_x, r_y, clampedP4.x, clampedP4.y, corcenter.colorPoint, colorEdge);
      // barycentricFill(corcenter, clampedP3,clampedP4);
      drawLine(clampedP3.x,clampedP3.y, clampedP4.x,clampedP4.y, clampedP3.colorPoint,clampedP4.colorPoint);
   }
  
}

void canvas::drawUnFilledRectangle(point& reccenter, int width, int height, ppm_pixel& coloredges)
{
   point pLB, pRB, pLH, pRH;
   pLB.x = reccenter.x - (width/2);
   pLB.y = reccenter.y - (height/2);
   pLB= clampPoint(pLB.x, pLB.y);

   pRB.x = reccenter.x + (width/2);
   pRB.y = reccenter.y - (height/2);
   pRB = clampPoint(pRB.x, pRB.y);
   
   pLH.x = reccenter.x - (width/2);
   pLH.y = reccenter.y + (height/2);
   pLH = clampPoint(pLH.x, pLH.y);

   pRH.x = reccenter.x + (width/2);
   pRH.y = reccenter.y + (height/2);
   pRH = clampPoint(pRH.x, pRH.y);

   drawLine(pLB.x,pLB.y,pRB.x, pRB.y, pLB.colorPoint, pRB.colorPoint);
   drawLine(pLB.x,pLB.y,pLH.x, pLH.y, pLB.colorPoint, pLH.colorPoint);
   drawLine(pRH.x,pRH.y,pLH.x, pLH.y, pRH.colorPoint, pLH.colorPoint);
   drawLine(pRH.x,pRH.y,pRB.x, pRB.y, pRH.colorPoint, pRB.colorPoint);
   // barycentricUnFill(reccenter, pLB, pRB);
   // barycentricUnFill(reccenter, pLH, pLB);
   // barycentricUnFill(reccenter, pLH, pRH);
   // barycentricUnFill(reccenter, pRB, pRH);

}

void canvas::drawRectangle(point& reccenter, int width, int height, ppm_pixel& edgecolors)
{
   point pLB, pRB, pLH, pRH;
   pLB.x = reccenter.x - (width/2);
   pLB.y = reccenter.y - (height/2);
   pLB= clampPoint(pLB.x, pLB.y);

   pRB.x = reccenter.x + (width/2);
   pRB.y = reccenter.y - (height/2);
   pRB = clampPoint(pRB.x, pRB.y);
   
   pLH.x = reccenter.x - (width/2);
   pLH.y = reccenter.y + (height/2);
   pLH = clampPoint(pLH.x, pLH.y);

   pRH.x = reccenter.x + (width/2);
   pRH.y = reccenter.y + (height/2);
   pRH = clampPoint(pRH.x, pRH.y);

   barycentricFill(reccenter, pLB, pRB);
   barycentricFill(reccenter, pLH, pLB);
   barycentricFill(reccenter, pLH, pRH);
   barycentricFill(reccenter, pRB, pRH);

}

//the edge color and center color can be same and different which allows to have interpolation or single coloring
void canvas::drawStar(point& corcenter, int rcircle)
{
   ppm_pixel fill {255, 255, 0};
   int numSlices = 5;
   float deltaTheta = ( 2 * 3.14 ) / numSlices;
   int r_x = corcenter.x;
   int r_y = corcenter.y;
   corcenter.colorPoint = fill;
   
   point point1;
   point1.x = r_x + rcircle;
   point1.y = r_y;
   point clampedP1 = clampPoint(point1.x, point1.y);
   clampedP1.colorPoint = fill;
   // drawLine(r_x, r_y, point1.x, point1.y, corcenter.colorPoint, colorEdge);

   float midTheta =  deltaTheta/2;
   point midPoint;
   midPoint.x = (int) (rcircle/2 *  cos(midTheta));
   midPoint.y = (int) (rcircle/2 *  sin(midTheta));

   if(midPoint.x < 0)
   {
      midPoint.x = r_x + midPoint.x;
   }
   else
   {
      midPoint.x = r_x + midPoint.x;
   }

   if(midPoint.y < 0)
   {
      midPoint.y = r_y + midPoint.y;
   }
   else
   {
      midPoint.y = r_y + midPoint.y;
   }
   point clampedMidPoint = clampPoint(midPoint.x, midPoint.y);
   clampedMidPoint.colorPoint = fill;
   
   float theta =  deltaTheta;
   point point2;
   point2.x = (int) (rcircle *  cos(theta));
   point2.y = (int) (rcircle *  sin(theta));


   if(point2.x < 0)
   {
      point2.x = r_x + point2.x;
   }
   else
   {
      point2.x = r_x + point2.x;
   }

   if(point2.y < 0)
   {
      point2.y = r_y + point2.y;
   }
   else
   {
      point2.y = r_y + point2.y;
   }
   point clampedP2 = clampPoint(point2.x, point2.y);
   clampedP2.colorPoint = fill;
   // drawLine(r_x, r_y, clampedP2.x, clampedP2.y, corcenter.colorPoint, colorEdge);
   
   barycentricFill(corcenter, clampedP1,clampedMidPoint);
   barycentricFill(corcenter, clampedMidPoint,clampedP2);

   for (int i = 1 ; i < numSlices; i++)
   {
      float theta1 = (i ) * deltaTheta;
      float midtheta12 = (i + .5) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p3, p4;
      p3.x = (int) (rcircle *  cos(theta1));
      p3.y = (int) (rcircle *  sin(theta1));

      point midPoint;
      midPoint.x = (int) (rcircle/2 *  cos(midtheta12));
      midPoint.y = (int) (rcircle/2 *  sin(midtheta12));

      if(midPoint.x < 0)
      {
         midPoint.x = r_x + midPoint.x;
      }
      else
      {
         midPoint.x = r_x + midPoint.x;
      }

      if(midPoint.y < 0)
      {
         midPoint.y = r_y + midPoint.y;
      }
      else
      {
         midPoint.y = r_y + midPoint.y;
      }
      point clampedMidPoint = clampPoint(midPoint.x, midPoint.y);
      clampedMidPoint.colorPoint = fill;
      

      p4.x = (int) (rcircle *  cos(theta2));
      p4.y = (int) (rcircle *  sin(theta2));

      if(p3.x < 0)
      {
         p3.x = r_x + p3.x;
         
      }
      else
      {
         p3.x = r_x + p3.x;
      }
      cout << p3.x << "   p3.x" <<endl;

      if(p3.y < 0)
      {
         p3.y = r_y + p3.y;
      }
      else
      {
         p3.y = r_y + p3.y;
      }
      cout << p3.y << "   p3.y" <<endl;


      if(p4.x < 0)
      {
         p4.x = r_x + p4.x;
      }
      else
      {
         p4.x = r_x + p4.x;
      }
      cout << p4.x << "   p4.x" <<endl;

      if(p4.y < 0)
      {
         p4.y = r_y + p4.y;
      }
      else
      {
         p4.y = r_y + p4.y;
      }
      cout << p4.x << "   p4.x" <<endl;

      point clampedP3 = clampPoint(p3.x, p3.y);
      point clampedP4 = clampPoint(p4.x, p4.y);
      clampedP3.colorPoint = fill;
      clampedP4.colorPoint = fill;
      // drawLine(r_x, r_y, clampedP3.x, clampedP3.y, corcenter.colorPoint, colorEdge);
      // drawLine(r_x, r_y, clampedP4.x, clampedP4.y, corcenter.colorPoint, colorEdge);
      barycentricFill(corcenter, clampedP3,clampedMidPoint);
      barycentricFill(corcenter, clampedMidPoint,clampedP4);
   }
  
}

void canvas::drawUnfilledStar(point& corcenter, int rcircle)
{
   ppm_pixel fill {255, 255, 0};
   int numSlices = 5;
   float deltaTheta = ( 2 * 3.14 ) / numSlices;
   int r_x = corcenter.x;
   int r_y = corcenter.y;
   corcenter.colorPoint = fill;
   
   point point1;
   point1.x = r_x + rcircle;
   point1.y = r_y;
   point clampedP1 = clampPoint(point1.x, point1.y);
   clampedP1.colorPoint = fill;

   float midTheta =  deltaTheta/2;
   point midPoint;
   midPoint.x = (int) (rcircle/2 *  cos(midTheta));
   midPoint.y = (int) (rcircle/2 *  sin(midTheta));

   if(midPoint.x < 0)
   {
      midPoint.x = r_x + midPoint.x;
   }
   else
   {
      midPoint.x = r_x + midPoint.x;
   }

   if(midPoint.y < 0)
   {
      midPoint.y = r_y + midPoint.y;
   }
   else
   {
      midPoint.y = r_y + midPoint.y;
   }
   point clampedMidPoint = clampPoint(midPoint.x, midPoint.y);
   clampedMidPoint.colorPoint = fill;

   drawLine(clampedP1.x, clampedP1.y, clampedMidPoint.x, clampedMidPoint.y, clampedP1.colorPoint, clampedMidPoint.colorPoint);
   
   
   float theta =  deltaTheta;
   point point2;
   point2.x = (int) (rcircle *  cos(theta));
   point2.y = (int) (rcircle *  sin(theta));


   if(point2.x < 0)
   {
      point2.x = r_x + point2.x;
   }
   else
   {
      point2.x = r_x + point2.x;
   }

   if(point2.y < 0)
   {
      point2.y = r_y + point2.y;
   }
   else
   {
      point2.y = r_y + point2.y;
   }
   point clampedP2 = clampPoint(point2.x, point2.y);
   clampedP2.colorPoint = fill;
   
   drawLine( clampedMidPoint.x, clampedMidPoint.y, clampedP2.x, clampedP2.y, clampedMidPoint.colorPoint , clampedP2.colorPoint);
   cout << "in drawStar unfilled" <<endl;
   cout << clampedMidPoint.x << clampedMidPoint.y << clampedP2.x <<  clampedP2.y << endl;

   for (int i = 1 ; i < numSlices; i++)
   {
      float theta1 = (i ) * deltaTheta;
      float midtheta12 = (i + .5) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p3, p4;
      p3.x = (int) (rcircle *  cos(theta1));
      p3.y = (int) (rcircle *  sin(theta1));

      point midPoint;
      midPoint.x = (int) (rcircle/2 *  cos(midtheta12));
      midPoint.y = (int) (rcircle/2 *  sin(midtheta12));

      if(midPoint.x < 0)
      {
         midPoint.x = r_x + midPoint.x;
      }
      else
      {
         midPoint.x = r_x + midPoint.x;
      }

      if(midPoint.y < 0)
      {
         midPoint.y = r_y + midPoint.y;
      }
      else
      {
         midPoint.y = r_y + midPoint.y;
      }
      point clampedMidPoint = clampPoint(midPoint.x, midPoint.y);
      clampedMidPoint.colorPoint = fill;
      

      p4.x = (int) (rcircle *  cos(theta2));
      p4.y = (int) (rcircle *  sin(theta2));

      if(p3.x < 0)
      {
         p3.x = r_x + p3.x;
         
      }
      else
      {
         p3.x = r_x + p3.x;
      }

      if(p3.y < 0)
      {
         p3.y = r_y + p3.y;
      }
      else
      {
         p3.y = r_y + p3.y;
      }


      if(p4.x < 0)
      {
         p4.x = r_x + p4.x;
      }
      else
      {
         p4.x = r_x + p4.x;
      }

      if(p4.y < 0)
      {
         p4.y = r_y + p4.y;
      }
      else
      {
         p4.y = r_y + p4.y;
      }

      point clampedP3 = clampPoint(p3.x, p3.y);
      point clampedP4 = clampPoint(p4.x, p4.y);
      clampedP3.colorPoint = fill;
      clampedP4.colorPoint = fill;
      drawLine(clampedP3.x, clampedP3.y, clampedMidPoint.x, clampedMidPoint.y, clampedP3.colorPoint, clampedMidPoint.colorPoint);
      drawLine(clampedP4.x, clampedP4.y, clampedMidPoint.x, clampedMidPoint.y, clampedP4.colorPoint, clampedMidPoint.colorPoint);
      
   }

}

void canvas::drawCurves(point& centerCur, int radius, int k, float angle,  ppm_pixel& colorEdge)
{
   int numSlices = 1000;
   float deltaTheta = ( angle) / numSlices;
   int r_x = centerCur.x;
   int r_y = centerCur.y;
   
   for (int i = 0 ; i < numSlices; i++)
   {
      float theta1 = (i) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p1, p2;
      p1.x = (int) (radius *  cos(theta1) * cos(k *theta1));
      p1.y = (int) (radius *  cos(k* theta1)* sin(theta1));

      p2.x = (int) (radius *  cos(theta2) * cos(k*theta2));
      p2.y = (int) (radius *  cos(k*theta2)* sin(theta2));

      if(p1.x < 0)
      {
         p1.x = r_x + p1.x;
         
      }
      else
      {
         p1.x = r_x + p1.x;
      }

      if(p1.y < 0)
      {
         p1.y = r_y + p1.y;
      }
      else
      {
         p1.y = r_y + p1.y;
      }


      if(p2.x < 0)
      {
         p2.x = r_x + p2.x;
      }
      else
      {
         p2.x = r_x + p2.x;
      }

      if(p2.y < 0)
      {
         p2.y = r_y + p2.y;
      }
      else
      {
         p2.y = r_y + p2.y;
      }
      point clampedP1 = clampPoint(p1.x, p1.y);
      point clampedP2 = clampPoint(p2.x, p2.y);
      clampedP1.colorPoint = colorEdge;
      clampedP2.colorPoint = colorEdge;
      // drawLine(r_x, r_y, clampedP3.x, clampedP3.y, corcenter.colorPoint, colorEdge);
      // drawLine(r_x, r_y, clampedP4.x, clampedP4.y, corcenter.colorPoint, colorEdge);
      barycentricFill(centerCur, clampedP1,clampedP2);
   }
  
}

void canvas::drawUnfilledCurves(point& centerCur, int radius, int k,  float angle,  ppm_pixel& colorEdge)
{
   int numSlices = 1000;
   float deltaTheta = ( angle) / numSlices;
   int r_x = centerCur.x;
   int r_y = centerCur.y;
   
   for (int i = 0 ; i < numSlices; i++)
   {
      float theta1 = (i) * deltaTheta;
      float theta2 = (i + 1) * deltaTheta;
      point p1, p2;
      p1.x = (int) (radius *  cos(theta1) * cos(k *theta1));
      p1.y = (int) (radius *  cos(k* theta1)* sin(theta1));

      p2.x = (int) (radius *  cos(theta2) * cos(k*theta2));
      p2.y = (int) (radius *  cos(k*theta2)* sin(theta2));

      if(p1.x < 0)
      {
         p1.x = r_x + p1.x;
         
      }
      else
      {
         p1.x = r_x + p1.x;
      }

      if(p1.y < 0)
      {
         p1.y = r_y + p1.y;
      }
      else
      {
         p1.y = r_y + p1.y;
      }


      if(p2.x < 0)
      {
         p2.x = r_x + p2.x;
      }
      else
      {
         p2.x = r_x + p2.x;
      }

      if(p2.y < 0)
      {
         p2.y = r_y + p2.y;
      }
      else
      {
         p2.y = r_y + p2.y;
      }
      point clampedP1 = clampPoint(p1.x, p1.y);
      point clampedP2 = clampPoint(p2.x, p2.y);
      clampedP1.colorPoint = colorEdge;
      clampedP2.colorPoint = colorEdge;
      drawLine(clampedP2.x, clampedP2.y, clampedP1.x, clampedP1.y, clampedP1.colorPoint, clampedP1.colorPoint);
      // drawLine(clampedP2.y, clampedP2.x, clampedP2.y, centerCur.colorPoint, clampedP2.colorPoint);
      // barycentricUnFill(centerCur, clampedP1,clampedP2);
   }

}

 