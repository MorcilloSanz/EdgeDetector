#pragma once

#include "../image/ImageTools.h"

class EdgeDetectorColor {
private:
    ImageTools::Image image, outputImage;
    double tau;
public:
    EdgeDetectorColor(const ImageTools::Image& _image, double _tau);
    EdgeDetectorColor() = default;
    ~EdgeDetectorColor() = default;
private:
    void set(ImageTools::Image& image, unsigned char r, unsigned char g, unsigned char b, int x, int y);
    void set(ImageTools::Image& image, unsigned char value, int x, int y);
    double get(ImageTools::Image& image, int x, int y);
public:
    void applyFilter(unsigned char r, unsigned char g, unsigned char b);
public:
    inline ImageTools::Image& getImage() { return image; }
    inline ImageTools::Image& getOutputImage() { return outputImage; }
    inline double getTau() const { return tau; }
};