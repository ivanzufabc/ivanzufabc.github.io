#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("../lab01/foto_grupo.jpg");
    if(image.empty()) {
        cout << "Erro ao abrir a imagem!" << endl;
        return -1;
    }

    Mat result;
    // Aplicando o filtro Gaussiano (kernel 3x3, sigmaX = 0)
    GaussianBlur(image, result, Size(3, 3), 0);

    // Exibindo e salvando o resultado
    namedWindow("Filtro Gaussiano - 3x3", WINDOW_AUTOSIZE);
    imshow("Filtro Gaussiano - 3x3", result);
    imwrite("gaussian_3x3.jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
