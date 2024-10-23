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
    // Aplicando o filtro mediano (kernel 3x3)
    medianBlur(image, result, 3);

    // Exibindo e salvando o resultado
    namedWindow("Filtro Mediano - 3x3", WINDOW_AUTOSIZE);
    imshow("Filtro Mediano - 3x3", result);
    imwrite("mediana_3x3.jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
