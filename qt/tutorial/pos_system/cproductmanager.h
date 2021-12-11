#ifndef CPRODUCTMANAGER_H
#define CPRODUCTMANAGER_H

#include <QObject>

struct product
{
    void init()
    {
        m_barcode = QString();
        m_name = QString();
        m_price = 0;
    }

    // product barcode.
    QString m_barcode;

    // product name.
    QString m_name;

    // product price.
    long m_price;

};

class CProductManager : public QObject
{
    Q_OBJECT

public:
    CProductManager();

    // append product function.
    Q_INVOKABLE bool appendProduct(QString barcode, QString name, long price);

    // create product structure.
    product* createProduct(QString barcode, QString name, long price);

private:
    QList<product *> m_productList;
};

#endif // CPRODUCTMANAGER_H
