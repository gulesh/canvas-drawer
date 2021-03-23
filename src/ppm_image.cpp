#include "ppm_image.h"
#include <cassert>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb/stb_image_write.h"
using namespace agl;
using namespace std;
ppm_image::ppm_image() : myData(0), myWidth(0), myHeight(0)
{
}
ppm_image::ppm_image(int width, int height) : myWidth(width), myHeight(height)
{
    myData = new ppm_pixel[width*height];
}
ppm_image::ppm_image(const ppm_image& orig)
{
    myWidth = orig.myWidth;
    myHeight = orig.myHeight;
    myData = new ppm_pixel[myWidth*myHeight];
    for (int i = 0; i < myWidth*myHeight; i++){
            myData[i] =  orig.myData[i];
    }
}
ppm_image& ppm_image::operator=(const ppm_image& orig)
{
    if (&orig == this)
    {
        return *this;
    }
    myWidth = orig.myWidth;
    myHeight = orig.myHeight;
    myData = new ppm_pixel[myWidth*myHeight];
    for (int i = 0; i < myWidth*myHeight; i++){
            myData[i] =  orig.myData[i];
    }
    return *this;
}
ppm_image::~ppm_image()
{
    delete[] myData;
}
bool ppm_image::save(const std::string& filename) const
{
    int result = stbi_write_png(filename.c_str(), myWidth, myHeight,
        3, (unsigned char*) myData, myWidth*3);
    return (result == 1);
}
ppm_pixel ppm_image::get(int row, int col) const
{
    assert(row >= 0 && row < myHeight);
    assert(col >= 0 && col < myWidth);
    return myData[row*myWidth + col];
}
void ppm_image::set(int row, int col, const ppm_pixel& color)
{
    assert(row >= 0 && row < myHeight);
    assert(col >= 0 && col < myWidth);
    myData[row*myWidth + col] = color;
}

ppm_image ppm_image::multiply(const ppm_image& other) const
{
   ppm_image result = ppm_image(myWidth,myHeight);
   for (int i = 0 ; i < myHeight; i++)
    {
       for (int j = 0; j < myWidth ;j++)
       {
           result.myData[i*myWidth + j].r = std::min(255, myData[i*myWidth + j].r * other.myData[i*myWidth + j].r);
           result.myData[i*myWidth + j].g = std::min(255, myData[i*myWidth + j].g * other.myData[i*myWidth + j].g);
           result.myData[i*myWidth + j].b = std::min(255, myData[i*myWidth + j].b * other.myData[i*myWidth + j].b);
        //  result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].r * other.pixelArray[i][j].r);
        //  result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].g * other.pixelArray[i][j].g);
        //  result.pixelArray[i][j].r = std::max(255, pixelArray[i][j].b * other.pixelArray[i][j].b);
       }
    }
    return result;
}

ppm_image ppm_image::difference(const ppm_image& other) const
{
   ppm_image result = ppm_image(myWidth,myHeight);
   for (int i = 0 ; i < myHeight; i++)
    {
       for (int j = 0; j < myWidth ;j++)
       {
           result.myData[i*myWidth + j].r = std::min(0, myData[i*myWidth + j].r - other.myData[i*myWidth + j].r);
           result.myData[i*myWidth + j].g = std::min(0, myData[i*myWidth + j].g - other.myData[i*myWidth + j].g);
           result.myData[i*myWidth + j].b = std::min(0, myData[i*myWidth + j].b - other.myData[i*myWidth + j].b);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
       }
    }
    return result;
}

ppm_image ppm_image::add(const ppm_image& other) const
{
   ppm_image result = ppm_image(myWidth,myHeight);
   for (int i = 0 ; i < myHeight; i++)
    {
       for (int j = 0; j < myWidth ;j++)
       {
           result.myData[i*myWidth + j].r = std::min(255, myData[i*myWidth + j].r + other.myData[i*myWidth + j].r);
           result.myData[i*myWidth + j].g = std::min(255, myData[i*myWidth + j].g + other.myData[i*myWidth + j].g);
           result.myData[i*myWidth + j].b = std::min(255, myData[i*myWidth + j].b + other.myData[i*myWidth + j].b);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
        //  result.pixelArray[i][j].r = std::min(0, pixelArray[i][j].r - other.pixelArray[i][j].r);
       }
    }
    return result;
}

ppm_image ppm_image::alpha_blend(const ppm_image& other, float alpha) const
{
   int blendedR, blendedG, blendedB;
   ppm_image result = ppm_image(myWidth,myHeight);
   for (int i = 0 ; i < myHeight; i++)
   {
      for (int j = 0; j < myWidth ;j++)
      {

        blendedR = (int) ( ((float) (myData[i*myWidth + j].r)) * (1 - alpha) + ((float) ( other.myData[i*myWidth + j].r) * alpha ) );
        blendedR = (int) ( ((float) (myData[i*myWidth + j].g)) * (1 - alpha) + ((float) ( other.myData[i*myWidth + j].g) * alpha ) );
        blendedR = (int) ( ((float) (myData[i*myWidth + j].b)) * (1 - alpha) + ((float) ( other.myData[i*myWidth + j].b) * alpha ) );
        //  //setting new pixel color
        result.myData[i*myWidth + j].r = (unsigned char) blendedR;
        result.myData[i*myWidth + j].g = (unsigned char) blendedG;
        result.myData[i*myWidth + j].b = (unsigned char) blendedB;
      }
   }
   return result;
}