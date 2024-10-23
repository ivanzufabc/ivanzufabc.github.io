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
    // Aplicando o filtro bilateral (d = 9, sigmaColor = 75, sigmaSpace = 75)
    bilateralFilter(image, result, 9, 75, 75);

    // Exibindo e salvando o resultado
    namedWindow("Filtro Bilateral", WINDOW_AUTOSIZE);
    imshow("Filtro Bilateral", result);
    imwrite("bilateral.jpg", result); // Salvando o resultado

    waitKey(0);
    return 0;
}
