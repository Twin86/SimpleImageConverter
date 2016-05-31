#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QFileDialog>
#include <QGraphicsScene>
#include <QImage>
#include <QPixelFormat>
#include <QPixmap>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void loafImageAfterFiltr();


private slots:
    void loadOnClick();
    void loadImage();

    void imageToBlackAndWhite();
    void imageToGrayscaleAv();
    void imageToInvertColors();
    void imageToBW();

    void saveImage();

    void on_mirrorButton_clicked();

    void on_scaledButton_clicked();

    void on_bgrButton_clicked();


    void on_sectionButton_clicked();

    void on_pushButton_clicked();

signals:

    void imageLoadMakePrew();

private:
    Ui::Widget *ui;

    QString fileName;
    QImage imgAfterEdit;

};

#endif // WIDGET_H
