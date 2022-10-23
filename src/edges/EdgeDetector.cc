#include "EdgeDetector.h"

EdgeDetector::EdgeDetector(const ImageTools::Image& _image, double _tau) 
    : image(_image), outputImage(image.width, image.height, image.bpp), tau(_tau) {
    ImageTools::toGrey(image);
}

void EdgeDetector::set(ImageTools::Image& image, unsigned char value, int x, int y) {
    image.buffer[4 * (x + y * image.width)] = value;
    image.buffer[4 * (x + y * image.width) + 1] = value;
    image.buffer[4 * (x + y * image.width) + 2] = value;
    image.buffer[4 * (x + y * image.width) + 3] = 255;
}

double EdgeDetector::get(ImageTools::Image& image, int x, int y) {
    return image.buffer[4 * (x + y * image.width)];
}

void EdgeDetector::applyFilter() {

    const double nablaMax [] = {255, 255};
    const int incrementX = 1, incrementY = 1;

    for(int i = 0; i < image.width; i ++) {
        for(int j = 0; j < image.height; j ++) {
            // Boundary conditions
            if (i == 0 || i == image.width - 1 || j == 0 || j == image.height - 1) {
                set(outputImage, 0, i, j);
                continue;
            }
                
            // Partial derivatives
            double xDerivative = (get(image, i + incrementX, j) - get(image, i - incrementX, j)) / (2 * incrementX);
            double yDerivative = (get(image, i, j + incrementY) - get(image, i, j - incrementY)) / (2 * incrementY);
            
            // Inequation
            if(xDerivative * xDerivative + yDerivative * yDerivative >= tau * tau * (nablaMax[0] * nablaMax[0] + nablaMax[1] * nablaMax[1]))
                set(outputImage, 255, i, j);
            else set(outputImage, 0, i, j);
        }
    }
}