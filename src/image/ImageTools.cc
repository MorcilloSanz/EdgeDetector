#include "ImageTools.h"

#define STB_IMAGE_IMPLEMENTATION
#include "../vendor/stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../vendor/stb_image_write.h"

ImageTools::Image::Image(const std::string& _path, const std::vector<unsigned char>& _buffer, int _width, int _height, int _bpp)
    : path(_path), buffer(_buffer), width(_width), height(_height), bpp(_bpp) { 
}

ImageTools::Image::Image(int _width, int _height, int _bpp)
    : width(_width), height(_height), bpp(_bpp) {
    buffer.resize(width * height * 4);
}

void ImageTools::toGrey(ImageTools::Image& image) {
    unsigned int index = 0;
    for(int i = 0; i < image.buffer.size(); i += 4) {
        unsigned char r = image.buffer[i];
        unsigned char g = image.buffer[i + 1];
        unsigned char b = image.buffer[i + 2];
        // Grey filter
        unsigned char grey = 0.3 * r + 0.59 * g + 0.11 * b;
        image.buffer[i] = grey;
        image.buffer[i + 1] = grey;
        image.buffer[i + 2] = grey;
    }
}

ImageTools::Image ImageTools::loadPNG(const std::string& path) {
    std::vector<unsigned char> buffer;
    // Load image
    int width, height, bpp;
    unsigned char* buff = stbi_load(path.c_str(), &width, &height, &bpp, STBI_rgb_alpha);
    // Copy to buffer
    size_t bufferSize = width * height * 4;
    buffer.resize(bufferSize);
    memcpy(&buffer[0], buff, bufferSize);
    // Free first buffer
    stbi_image_free(buff);
    // Return image
    return Image(path, buffer, width, height, bpp);
}

void ImageTools::savePNG(const Image& image, const std::string& path) {
    stbi_write_png(path.c_str(), image.width, image.height, STBI_rgb_alpha, &image.buffer[0], image.width * STBI_rgb_alpha);
}