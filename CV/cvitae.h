#ifndef CVITAE_H
#define CVITAE_H

#include <QMainWindow>
#include <QGraphicsPixmapItem>

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

namespace Ui {
class CVitae;
}

class CVitae : public QMainWindow
{
    Q_OBJECT

public:

    typedef enum {
        FACE_DETECTION,
        EYES_DETECTION
    } dtype_t;

    explicit CVitae(QWidget *parent = nullptr);
    ~CVitae();
    void captureFrame() {vcVideo >> matVideoFrame; waitKey(30);}
    void showFrame();
    void detectObjects(dtype_t type);
    void drawDetectedObjects();
    bool loadFaceData();
    bool loadEyeData();
    bool detectObjects() {return bDetectObjects;}
    bool detectFace() { return bFace;}
    bool detectEye() { return bEye;}


private slots:

    void on_chbDetectObjects_clicked(bool checked);
    void on_rbFaceDetection_clicked(bool checked);
    void on_rbEyeDetection_clicked(bool checked);
    void on_rbFaceAndEyesDetection_clicked(bool checked);


private:
    Ui::CVitae *ui;

    VideoCapture vcVideo; //! VideoCapture object for capturing video frames
    Mat matVideoFrame; //!< Matrix for image processing
    QGraphicsPixmapItem pixmapItem; //!< Item to show in QGraphicsView
    vector <Rect> vEyes; //!< Vector conteining found objects
    vector <Rect> vFace; //!< Vector conteining found objects
    //!< Here we need some object to do whole job of face detection process */
    //!< Here we need some object to do whole job of eyes detection process */
    bool bDetectObjects; //!< Enable objects detection
    bool bFace; //!< Face data's load status
    bool bEye; //!< Eye data's load status
};

#endif // CVITAE_H
