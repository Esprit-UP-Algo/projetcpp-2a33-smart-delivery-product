// qgiflabel.cpp
#include "qgiflabel.h"

QGifLabel::QGifLabel(QWidget *parent)
    : QLabel(parent), gifMovie(new QMovie(this))
{
    setMovie(gifMovie);
}

void QGifLabel::setGif(const QString &filePath)
{
    gifMovie->setFileName(filePath);
    gifMovie->start();
}
void QGifLabel::setGifAlignment(Qt::Alignment alignment)
{
    setAlignment(alignment);
}
void QGifLabel::setGifSize(int width, int height)
{
    setFixedSize(width, height);
}
