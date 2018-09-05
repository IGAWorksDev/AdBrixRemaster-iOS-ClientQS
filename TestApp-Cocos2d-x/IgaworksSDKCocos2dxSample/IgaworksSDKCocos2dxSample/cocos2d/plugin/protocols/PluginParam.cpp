/****************************************************************************
Copyright (c) 2012-2013 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#include "PluginParam.h"
#include "json.h"

namespace cocos2d { namespace plugin {

PluginParam::PluginParam()
{
    _type = kParamTypeNull;
}

PluginParam::PluginParam(int nValue)
: _intValue(nValue)
{
	_type = kParamTypeInt;
}

PluginParam::PluginParam(float fValue)
: _floatValue(fValue)
{
	_type = kParamTypeFloat;
}

PluginParam::PluginParam(bool bValue)
: _boolValue(bValue)
{
	_type = kParamTypeBool;
}

PluginParam::PluginParam(const char* strValue)
: _strValue(strValue)
{
	_type = kParamTypeString;
}

PluginParam::PluginParam(std::map<std::string, PluginParam*> mapValue)
: _mapValue(mapValue)
{
	_type = kParamTypeMap;
}

PluginParam::PluginParam(StringMap strMapValue)
: _strMapValue(strMapValue)
{
    _type = kParamTypeStringMap;
}

    
AdBrixRmCommerceProductAttrModel::AdBrixRmCommerceProductAttrModel(std::map<std::string, std::string> attrData)
{
    
    
    int count = 0;
    for (int i = 0; i < 5; i ++)
    {
        this->Key[i] = NULL;
        this->Value[i] = NULL;
    }
    
    for (const auto& kv : attrData)
    {
        this->Key[count] = kv.first.c_str();
        this->Value[count] = kv.second.c_str();
        count++;
    }
}
 
    AdBrixRmCommerceProductAttrModel* AdBrixRmCommerceProductAttrModel::create(std::map<std::string , std::string> attrData)
{
    AdBrixRmCommerceProductAttrModel *pObj = new AdBrixRmCommerceProductAttrModel(attrData);
    return pObj;
}
    
const char* AdBrixRmCommerceProductAttrModel::getValue(int pIndex)
{
    return Value[pIndex];
}

const char* AdBrixRmCommerceProductAttrModel::getKey(int pIndex)
{
    return Key[pIndex];
}
    
    AdBrixRmCommerceProductCategoryModel * AdBrixRmCommerceProductCategoryModel::create(std::string category1)
    {
        AdBrixRmCommerceProductCategoryModel *pObj = new AdBrixRmCommerceProductCategoryModel();
        pObj->category1 = category1;
        pObj->category2 = "";
        pObj->category3 = "";
        pObj->category4 = "";
        pObj->category5 = "";
        pObj->categoryFullString = pObj->category1;
        return pObj;
    }
    
    AdBrixRmCommerceProductCategoryModel * AdBrixRmCommerceProductCategoryModel::create(std::string category1, std::string category2)
    {
        AdBrixRmCommerceProductCategoryModel *pObj = new AdBrixRmCommerceProductCategoryModel();
        pObj->category1 = category1;
        pObj->category2 = category2;
        pObj->category3 = "";
        pObj->category4 = "";
        pObj->category5 = "";
        pObj->categoryFullString = pObj->category1 + "." + pObj->category2;
        return pObj;
    }
    
    AdBrixRmCommerceProductCategoryModel * AdBrixRmCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3)
    {
        AdBrixRmCommerceProductCategoryModel *pObj = new AdBrixRmCommerceProductCategoryModel();
        pObj->category1 = category1;
        pObj->category2 = category2;
        pObj->category3 = category3;
        pObj->category4 = "";
        pObj->category5 = "";
        pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3;
        return pObj;
    }
    
    AdBrixRmCommerceProductCategoryModel * AdBrixRmCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3, std::string category4)
    {
        AdBrixRmCommerceProductCategoryModel *pObj = new AdBrixRmCommerceProductCategoryModel();
        pObj->category1 = category1;
        pObj->category2 = category2;
        pObj->category3 = category3;
        pObj->category4 = category4;
        pObj->category5 = "";
        pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3 + "." + pObj->category4;
        return pObj;
    }
    
    AdBrixRmCommerceProductCategoryModel * AdBrixRmCommerceProductCategoryModel::create(std::string category1, std::string category2, std::string category3, std::string category4, std::string category5)
    {
        AdBrixRmCommerceProductCategoryModel *pObj = new AdBrixRmCommerceProductCategoryModel();
        pObj->category1 = category1;
        pObj->category2 = category2;
        pObj->category3 = category3;
        pObj->category4 = category4;
        pObj->category5 = category5;
        pObj->categoryFullString = pObj->category1 + "." + pObj->category2 + "." + pObj->category3 + "." + pObj->category4 + "." + pObj->category5;
        return pObj;
    }
    
AdBrixRmCommerceProductModel::AdBrixRmCommerceProductModel(std::string productId, std::string productName, double price, double discount, int quantity, std::string currencyString, AdBrixRmCommerceProductCategoryModel *category, AdBrixRmCommerceProductAttrModel *extraAttrs)
{

    
    _productID = productId;
    _productName = productName;
    _price = price;
    _discount = discount;
    _quantity = quantity;
    _currencyString = currencyString;
    _category = category->categoryFullString;
}
    
std::string AdBrixRmCommerceProductModel::create(std::string productId, std::string productName, double price, double discount, int quantity, std::string currencyString, AdBrixRmCommerceProductCategoryModel* category, AdBrixRmCommerceProductAttrModel* extraAttrs)
    
    {
        //return *new AdBrixCommerceProductModel(productId, productName, price, discount, quantity, currencyString, category, extraAttrs);
    
        auto sPrice = std::to_string(price);
        auto sDiscount = std::to_string(discount);
        auto sQuantity = std::to_string(quantity);
        
        Json::Value root;
        
        root["product_id"] = productId;
        root["product_name"] = productName;
        root["price"] = sPrice;
        root["currency"] = currencyString;
        root["discount"] = sDiscount;
        root["quantity"] = sQuantity;
        root["category"] = category->categoryFullString;
        
        Json::Value extra_attrs;
        
        if(extraAttrs != NULL)
        {
            for (int i = 0; i < 5; i ++) {
                if((extraAttrs->getKey(i) != NULL) && (extraAttrs->getValue(i) != NULL)) {
                    extra_attrs[extraAttrs->getKey(i)] = extraAttrs->getValue(i);
                }
                
            }
        }
        root["extra_attrs"] = extra_attrs;
        
//        std::string jsonString = "{\"product_id\": ";
//
//        jsonString = jsonString +
//        "\"" + productId  + "\"" + ", " +
//        "\"product_name\": " + "\"" + productName + "\"" + ", " +
//        "\"price\": " + sPrice + ", " +
//        "\"currency\": " + "\"" + currencyString + "\"" + ", " +
//        "\"discount\": " + sDiscount + ", " +
//        "\"quantity\": " + "\"" + sQuantity + "\"" + ", " +
//        "\"category\": " + "\"" + category->categoryFullString + "\"" + ", ";
//
//        std::string jsonAttrString = "\"extra_attrs\":{";
//        if(extraAttrs != NULL)
//        {
//            for (int i = 0; i < 5; i ++)
//            {
//
//                if((extraAttrs->getKey(i) != NULL) && (extraAttrs->getValue(i) != NULL)) {
//                    if (i == 4) {
//                        jsonAttrString = jsonAttrString + "\"" + extraAttrs->getKey(i) + "\":" + "\"" + extraAttrs->getValue(i) + "\"" + "}";
//                    } else {
//                        jsonAttrString = jsonAttrString + "\"" + extraAttrs->getKey(i) + "\":" + "\"" + extraAttrs->getValue(i) + "\"" + ",";
//                    }
//                }
//
//            }
//        }
//        else {
//            jsonAttrString = jsonAttrString + "}";
//        }
//        jsonString = jsonAttrString +"}";
//        return jsonString;
        
        Json::StreamWriterBuilder builder;
        const std::string output = Json::writeString(builder, root);
        
        return output;
    }

   
    
}} //namespace cocos2d { namespace plugin {
