#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <math.h>

using namespace std;
using namespace cv;

void lineBresenham(Mat &img, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int val);

int main(int argc, char *argv[])
{
    Mat M(20, 20, CV_8UC1, Scalar(0));

    lineBresenham(M, 0, 0, 15, 19, 255);

    cout << "M = " << endl << M << endl;
    namedWindow("win");
    imshow("win", M);
    waitKey(0);
}

void lineBresenham(Mat &img, unsigned int x0, unsigned int y0, unsigned int x1, unsigned int y1, unsigned int val)
{
    int dx, dy, dy2, dx2, dy2dx2, p;


    if(abs(x1 - x0) > abs(y1 - y0)){

        if(x0 > x1){
            int tmp = x0;
            x0 = x1;
            x1 = tmp;

            tmp = y0;
            y0 = y1;
            y1 = tmp;
        }

        dx = x1 - x0;
        dy = y1 - y0;


        dy2 = 2 * dy;
        dy2dx2 = 2 * dy - 2 * dx ;

        p = dy2 - dx;

        int x = x0, y = y0;

        img.at<unsigned char>(y,x) = val;
        for(int i = 0; i < dx; ++i){

            if(p < 0){
                x++;
                p = p + dy2;
            }else{
                y++;
                x++;
                p = p + dy2dx2;
            }
            img.at<unsigned char>(y,x) = val;
        }

    }else{

        if(y0 > y1){
            int tmp = x0;
            x0 = x1;
            x1 = tmp;

            tmp = y0;
            y0 = y1;
            y1 = tmp;
        }

        dx = x1 - x0;
        dy = y1 - y0;


        dx2 = 2 * dx;
        dy2dx2 = 2 * dx - 2 * dy ;

        p = dx2 - dx;

        int x = x0, y = y0;

        img.at<unsigned char>(y,x) = val;
        for(int i = 0; i < dy; ++i){

            if(p < 0){
                y++;
                p = p + dx2;
            }else{
                y++;
                x++;
                p = p + dy2dx2;
            }
            img.at<unsigned char>(y,x) = val;
        }
    }
}
