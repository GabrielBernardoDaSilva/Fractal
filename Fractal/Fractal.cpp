#include <iostream>
#include <fstream>
#include <ccomplex>


const float width = 600;
const float height = 600;

int values(int x, int y) {
    const std::complex<float> point((float)x / width - 1.5, (float)y / height - .5);
    
    std::complex<float> z;

    std::uint16_t nb_iter = 0;
    while (abs(z) < 2 && nb_iter <= 34) {
        z = z * z + point;
        nb_iter++;
    }
    if (nb_iter < 34) 
        return (255* nb_iter) / 33;
    return 0;
}


int main(int argc, char* agrv) {

    std::ofstream image("mandelbrot.ppm");
    if (image.is_open()) {
        image << "P3\n" << width << " " << height << " 255\n";
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                int val = values(i, j);
                image << val << ' ' << 0 << ' ' << 0 << "\n";
            }
        }
        image.close();
    }
    else std::cout << "Could not open the file";
    return 0;
}