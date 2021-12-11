#include "cproductmanager.h"

CProductManager::CProductManager()
{

}

bool CProductManager::appendProduct(QString barcode, QString name, long price)
{
    // create new product.
    product *newProduct = createProduct(barcode, name, price);
    if (!newProduct)
        return false;

    // append new product.
    m_productList.append(newProduct);

    // return result.
    return true;
}

product *CProductManager::createProduct(QString barcode, QString name, long price)
{
    // check barcode.
    if (barcode.isEmpty())
        return NULL;

    product *newProduct = new product;
    newProduct->init();
    newProduct->m_barcode = barcode;
    newProduct->m_name = name;
    newProduct->m_price = price;

    return newProduct;
}
