#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    Mat image = imread("imagem_original.jpg");
    if(image.empty()) {
        cout << "Erro ao abrir a imagem!" << endl;
        return -1;
    }

    Mat result;
    // Aplicando o filtro de média (kernel 3x3)
    blur(image, result, Size(3, 3));

    // Exibindo e salvando o resultado
    namedWindow("Filtro de Média - 3x3", WINDOW_AUTOSIZE);
    imshow("Filtro de Média - 3x3", result);
    imwrite("media_3x3.jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
