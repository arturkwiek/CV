#include "cvitae.h"
#include "ui_cvitae.h"

#include <QDebug>

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

CVitae::CVitae(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CVitae),
    bFace(false),
    bEye(false)
{
    ui->setupUi(this);
    vcVideo.open(0);

    ui->gvFrame->setScene(new QGraphicsScene(this));
    ui->gvFrame->scene()->addItem(&pixmapItem);

}

CVitae::~CVitae()
{
    delete ui;
}

void CVitae::showFrame() {
    /** Code for displaying video frames on QGraphicsView widget */

    if(!matVideoFrame.empty())
    {
        QImage qimg(matVideoFrame.data,
                    matVideoFrame.cols,
                    matVideoFrame.rows,
                    matVideoFrame.step,
                    QImage::Format_RGB888);

        ui->gvFrame->resetMatrix();
        pixmapItem.setPixmap( QPixmap::fromImage(qimg.rgbSwapped()));
        ui->gvFrame->fitInView(&pixmapItem, Qt::KeepAspectRatio);
    }
}

void CVitae::detectObjects(dtype_t type) {
    /** In this function must placed code which makes great job for eyes detection */

    if(type == FACE_DETECTION)
        ;// something to do
    else if(type == EYES_DETECTION)
        ;// something to do

}

void CVitae::drawDetectedObjects() {

    /** Draw rectangle on every founded object */

    if(detectFace())
        for(size_t i=0;i<vFace.size();i++)
            rectangle(matVideoFrame,vFace[i].br(),vFace[i].tl(),Scalar(0,0,255),2,LINE_8,0);
    if(detectEye())
        for(size_t i=0;i <vEyes.size();i++)
            rectangle(matVideoFrame,vEyes[i].br(),vEyes[i].tl(),Scalar(255,0,0),2,LINE_8,0);

}

bool CVitae::loadFaceData()
{
    /** Load the data for matching them to objects on input video stream */

    // something to do
}

bool CVitae::loadEyeData()
{
    /** Load the data for matching them to objects on input video stream */

    // something to do
}

void CVitae::on_chbDetectObjects_clicked(bool checked)
{
    bDetectObjects = checked;
}

void CVitae::on_rbFaceDetection_clicked(bool checked)
{
    bFace = checked;
    bEye = !checked;
}

void CVitae::on_rbEyeDetection_clicked(bool checked)
{
    bEye = checked;
    bFace = !checked;
}

void CVitae::on_rbFaceAndEyesDetection_clicked(bool checked)
{
    bFace = bEye = checked;
}

