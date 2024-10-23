#include <opencv2/opencv.hpp>
#include <iostream>
#include <boost/lexical_cast.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {
    int kernel;
    if (argc == 2) {
        kernel = boost::lexical_cast<int>(argv[1]);
    }
    else {
        kernel = 3;
    }
    string kernel_str = to_string(kernel) + "x" + to_string(kernel);

    Mat image = imread("../lab01/foto_grupo.jpg");
    if(image.empty()) {
        cout << "Erro ao abrir a imagem!" << endl;
        return -1;
    }

    Mat result;
    // Aplicando o filtro mediano (kernel 3x3)
    medianBlur(image, result, kernel);

    // Exibindo e salvando o resultado
    namedWindow("Filtro Mediano - " + kernel_str, WINDOW_AUTOSIZE);
    imshow("Filtro Mediano - " + kernel_str, result);
    imwrite("mediana_" + kernel_str + ".jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
