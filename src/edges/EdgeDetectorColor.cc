#include "EdgeDetectorColor.h"

EdgeDetectorColor::EdgeDetectorColor(const ImageTools::Image& _image, double _tau) 
    : image(_image), outputImage(_image), tau(_tau) {
    ImageTools::toGrey(image);
}

void EdgeDetectorColor::set(ImageTools::Image& image, unsigned char r, unsigned char g, unsigned char b, int x, int y) {
    image.buffer[4 * (x + y * image.width)] = r;
    image.buffer[4 * (x + y * image.width) + 1] = g;
    image.buffer[4 * (x + y * image.width) + 2] = b;
    image.buffer[4 * (x + y * image.width) + 3] = 255;
}

void EdgeDetectorColor::set(ImageTools::Image& image, unsigned char value, int x, int y) {
    set(image, value, value, value, x, y);
}

double EdgeDetectorColor::get(ImageTools::Image& image, int x, int y) {
    return image.buffer[4 * (x + y * image.width)];
}

void EdgeDetectorColor::applyFilter(unsigned char r, unsigned char g, unsigned char b) {

    const double nablaMax [] = {255, 255};
    const int incrementX = 1, incrementY = 1;

    for(int i = 0; i < image.width; i ++) {
        for(int j = 0; j < image.height; j ++) {
            // Boundary conditions
            if (i == 0 || i == image.width - 1 || j == 0 || j == image.height - 1) continue;
                
            // Partial derivatives
            double xDerivative = (get(image, i + incrementX, j) - get(image, i - incrementX, j)) / (2 * incrementX);
            double yDerivative = (get(image, i, j + incrementY) - get(image, i, j - incrementY)) / (2 * incrementY);
            
            // Inequation
            if(xDerivative * xDerivative + yDerivative * yDerivative >= tau * tau * (nablaMax[0] * nablaMax[0] + nablaMax[1] * nablaMax[1]))
                set(outputImage, r, g, b, i, j);
        }
    }
}