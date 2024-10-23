#include <opencv2/opencv.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    int kernel_x, kernel_y;
    if (argc == 2) {
        kernel_x = boost::lexical_cast<int>(argv[1]);
        kernel_y = kernel_x;
    }
    else if (argc == 3) {
        kernel_x = boost::lexical_cast<int>(argv[1]);
        kernel_y = boost::lexical_cast<int>(argv[2]);
    }
    else {
        kernel_x = kernel_y = 3;
    }
    string kernel_str = to_string(kernel_x) + "x" + to_string(kernel_y);

    Mat image = imread("../lab01/foto_grupo.jpg");
    if(image.empty()) {
        cout << "Erro ao abrir a imagem!" << endl;
        return -1;
    }

    Mat result;
    // Aplicando o filtro Gaussiano (kernel 3x3, sigmaX = 0)
    GaussianBlur(image, result, Size(kernel_x, kernel_y), 0);

    // Exibindo e salvando o resultado
    namedWindow("Filtro Gaussiano - " + kernel_str, WINDOW_AUTOSIZE);
    imshow("Filtro Gaussiano - " + kernel_str, result);
    imwrite("gaussian_" + kernel_str + ".jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
