// qgiflabel.h
#ifndef QGIFLABEL_H
#define QGIFLABEL_H

#include <QLabel>
#include <QMovie>

class QGifLabel : public QLabel {
    Q_OBJECT

public:
    explicit QGifLabel(QWidget *parent = nullptr);
 void setGifAlignment(Qt::Alignment alignment);
    void setGif(const QString &filePath);
    void setGifSize(int width, int height);

private:
    QMovie *gifMovie;
};

#endif // QGIFLABEL_H
