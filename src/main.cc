#include <iostream>

#include "edges/EdgeDetector.h"

int main() {

    // Input
    ImageTools::Image image = ImageTools::loadPNG("test.png");

    // Edges
    double tau = 0.05; // 0 <= tau <= 1
    EdgeDetector edgeDetector(image, tau);
    edgeDetector.applyFilter();

    // Save output
    ImageTools::savePNG(edgeDetector.getOutputImage(), "output.png");

    return 0;
}