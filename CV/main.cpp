#include "cvitae.h"
#include <QApplication>

#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

#include <opencv2/highgui.hpp>
#include <opencv2/calib3d.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/videostab.hpp>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CVitae w;
    w.show();

    if(!w.loadFaceData()) exit(0);
    if(!w.loadEyeData()) exit(0);

    while(1) {

        w.captureFrame();

        a.processEvents();

        if(w.detectObjects()) {
            if(w.detectFace())
                w.detectObjects(CVitae::FACE_DETECTION);

            if(w.detectEye())
                w.detectObjects(CVitae::EYES_DETECTION);

            w.drawDetectedObjects();
        }
        w.showFrame();

    }

}
