#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("ImageChanger");
    connect(ui->loadImgButton, SIGNAL(clicked(bool)),this,SLOT(loadOnClick()));
    connect(this,SIGNAL(imageLoadMakePrew()),this,SLOT(loadImage()));
    connect(ui->changeToGrayButton,SIGNAL(clicked(bool)),this,SLOT(imageToBlackAndWhite()));
    connect(ui->changeToGrayscaleAv,SIGNAL(clicked(bool)),this,SLOT(imageToGrayscaleAv()));
    connect(ui->InvertColorButton,SIGNAL(clicked(bool)),this,SLOT(imageToInvertColors()));
    connect(ui->changeToBwButton,SIGNAL(clicked(bool)),this,SLOT(imageToBW()));
    connect(ui->savebutton,SIGNAL(clicked(bool)),this,SLOT(saveImage()));
}

Widget::~Widget()
{
    delete ui;
}


//sekcja sloty
void Widget::loadOnClick(){

    fileName = QFileDialog::getOpenFileName(this,
        tr("Open Image"), "/home/", tr("Image Files (*.png *.jpg *.bmp)"));

    if(fileName != NULL){
        imageLoadMakePrew();
    }
}


void Widget::loadImage(){

    QPixmap img(fileName);
    QGraphicsScene * Scena = new QGraphicsScene(this);
    img.scaledToWidth(ui->graphicsView_2->width(),Qt::FastTransformation);
    Scena->addPixmap(img);

    ui->graphicsView_2->setScene(Scena);

}

void Widget::imageToBlackAndWhite(){
    qDebug()<<"Kolor pixeli !";
    QImage img (fileName);

    for(int i= 0; i < img.width();i++){
        for(int j = 0; j < img.height();j++){

           QRgb color = img.pixel(i,j);

           int r = qRed(color);
           int g = qGreen(color);
           int b = qBlue(color);



           img.setPixel(i,j,qRgb(r*0.3, g*0.2, b*0.1));

        }
    }

    QPixmap temp = QPixmap::fromImage(img);
    QGraphicsScene * Scena = new QGraphicsScene(this);
    temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
    Scena->addPixmap(temp);

    ui->graphicsView->setScene(Scena);

    imgAfterEdit =  img;
}


void Widget::imageToGrayscaleAv(){
    qDebug()<<"Kolor pixeli !";
    QImage img (fileName);

    for(int i= 0; i < img.width();i++){
        for(int j = 0; j < img.height();j++){

           QRgb color = img.pixel(i,j);

           int r = qRed(color);
           int g = qGreen(color);
           int b = qBlue(color);

           int c = (r+g+b)/3;

           img.setPixel(i,j,qRgb(c, c, c));

        }
    }

    QPixmap temp = QPixmap::fromImage(img);
    QGraphicsScene * Scena = new QGraphicsScene(this);
    temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
    Scena->addPixmap(temp);

    ui->graphicsView->setScene(Scena);
    imgAfterEdit = img;
}


void Widget::imageToInvertColors(){
    qDebug()<<"Kolor pixeli !";
    QImage img (fileName);

    img.invertPixels();


    QPixmap temp = QPixmap::fromImage(img);
    QGraphicsScene * Scena = new QGraphicsScene(this);
    temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
    Scena->addPixmap(temp);

    ui->graphicsView->setScene(Scena);
    imgAfterEdit = img;
}

void Widget::imageToBW(){

            qDebug()<<"Kolor pixeli !";
            QImage img(fileName);

            img = img.convertToFormat(QImage::Format_Indexed8);


            QPixmap temp = QPixmap::fromImage(img);
            QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = img;
}


void Widget::saveImage(){


    QString savefileName = QFileDialog::getSaveFileName(this, tr("Save File"),
                               "/",
                               tr("Images (*.png *.xpm *.jpg)"));

    imgAfterEdit.save(savefileName);
}

//by piotr łuszczak
void Widget::on_mirrorButton_clicked()
{
    qDebug()<<"Kolor pixeli !";
    QImage img(fileName);

    QPixmap temp = QPixmap::fromImage(img.mirrored(true,false));
    QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = temp.toImage();
}


void Widget::on_scaledButton_clicked()
{
    qDebug()<<"Kolor pixeli !";
    QImage img(fileName);


    QPixmap temp = QPixmap::fromImage(img.smoothScaled(ui->graphicsView_2->width(),(int((ui->graphicsView_2->width()/(img.width()*1.0f)) * img.height()))));
    QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = temp.toImage();
}

void Widget::on_bgrButton_clicked()
{
    qDebug()<<"Kolor pixeli !";
    QImage img(fileName);
    QPixmap temp = QPixmap::fromImage(img.rgbSwapped());
    QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = temp.toImage();
}

void Widget::on_sectionButton_clicked()
{
    qDebug()<<"Kolor pixeli !";
    QImage img(fileName);
    QPixmap temp = QPixmap::fromImage(img.copy(0,0,400,400));
    QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = temp.toImage();
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<"Kolor pixeli !";
    QImage img(fileName);
    //QPixmap temp = QPixmap::fromImage(img.smoothScaled(ui->graphicsView->width(),static_cast<int>((ui->graphicsView_2->width()/img.width()) * img.height())));
    QPixmap temp = QPixmap::fromImage(img.smoothScaled(60,60));
    QGraphicsScene * Scena = new QGraphicsScene(this);
            temp.scaledToWidth(ui->graphicsView->width(),Qt::FastTransformation);
            Scena->addPixmap(temp);

            ui->graphicsView->setScene(Scena);

            imgAfterEdit = temp.toImage();

}
