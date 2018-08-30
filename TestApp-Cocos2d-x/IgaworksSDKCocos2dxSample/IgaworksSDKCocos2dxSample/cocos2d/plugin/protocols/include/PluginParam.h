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
#ifndef __CCX_PLUGIN_PARAM_H__
#define __CCX_PLUGIN_PARAM_H__

#include <map>
#include <string>

typedef std::map<std::string, std::string>   StringMap;

typedef struct Item_Model
{
    char                            orderId;
    char                            productId;
    char                            productName;
    double                          price;
    int                             quantity;
    char                            currencyString;
    char                            categories;
}ITEM_MODEL;

enum
{
    AdBrixCurrencyKRW = 1,
    AdBrixCurrencyUSD = 2,
    AdBrixCurrencyJPY = 3,
    AdBrixCurrencyEUR = 4,
    AdBrixCurrencyGBP = 5,
    AdBrixCurrencyCNY = 6,
    AdBrixCurrencyTWD = 7,
    AdBrixCurrencyHKD = 8
};

enum
{
    AdBrixPaymentCreditCard         = 1,
    AdBrixPaymentBankTransfer       = 2,
    AdBrixPaymentMobilePayment      = 3,
    AdBrixPaymentETC                = 4
};

enum
{
    AdBrixSharingFacebook       = 1,
    AdBrixSharingKakaoTalk      = 2,
    AdBrixSharingKakaoStory     = 3,
    AdBrixSharingLine           = 4,
    AdBrixSharingWhatsApp       = 5,
    AdBrixSharingQQ             = 6,
    AdBrixSharingWeChat         = 7,
    AdBrixSharingSMS            = 8,
    AdBrixSharingEmail          = 9,
    AdBrixSharingCopyUrl        = 10,
    AdBrixSharingETC            = 11
};

enum
{
    AdBrixSignUpKakaoChannel           = 1
    ,AdBrixSignUpNaverChannel           = 2
    ,AdBrixSignUpLineChannel            = 3
    ,AdBrixSignUpGoogleChannel          = 4
    ,AdBrixSignUpFacebookChannel        = 5
    ,AdBrixSignUpTwitterChannel         = 6
    ,AdBrixSignUpWhatsAppChannel        = 7
    ,AdBrixSignUpQQChannel              = 8
    ,AdBrixSignUpWeChatChannel          = 9
    ,AdBrixSignUpUserIdChannel          = 10
    ,AdBrixSignUpETCChannel             = 11
};

enum
{
    AdBrixInviteKakaoChannel            = 1
    ,AdBrixInviteNaverChannel           = 2
    ,AdBrixInviteLineChannel            = 3
    ,AdBrixInviteGoogleChannel          = 4
    ,AdBrixInviteFacebookChannel        = 5
    ,AdBrixInviteTwitterChannel         = 6
    ,AdBrixInviteWhatsAppChannel        = 7
    ,AdBrixInviteQQChannel              = 8
    ,AdBrixInviteWeChatChannel          = 9
    ,AdBrixInviteETCChannel             = 10
};



namespace cocos2d { namespace plugin {
    
    class PluginProtocol;
    class PluginParam
    {
    public:
        PluginParam();
        PluginParam(int nValue);
        PluginParam(float fValue);
        PluginParam(bool bValue);
        PluginParam(const char* strValue);
        PluginParam(StringMap strMapValue);
        PluginParam(ITEM_MODEL mdValue);
        
        typedef enum{
            kParamTypeNull = 0,
            kParamTypeInt,
            kParamTypeFloat,
            kParamTypeBool,
            kParamTypeString,
            kParamTypeStringMap,
            kParamTypeMap,
        } ParamType;
        
        inline ParamType getCurrentType() {
            return _type;
        }
        
        inline int getIntValue() {
            return _intValue;
        }
        
        inline float getFloatValue() {
            return _floatValue;
        }
        
        inline bool getBoolValue() {
            return _boolValue;
        }
        
        inline const char* getStringValue() {
            return _strValue.c_str();
        }
        
        inline ITEM_MODEL getItem()
        {
            return _item_medelValue;
        }
        
        inline std::map<std::string, PluginParam*> getMapValue() {
            return _mapValue;
        }
        
        inline StringMap getStrMapValue() {
            return _strMapValue;
        }
        
    private:
        friend class PluginProtocol;
        PluginParam(std::map<std::string, PluginParam*> mapValue);
        
    private:
        ParamType _type;
        
        int _intValue;
        float _floatValue;
        bool _boolValue;
        ITEM_MODEL _item_medelValue;
        std::string _strValue;
        std::map<std::string, PluginParam*> _mapValue;
        StringMap _strMapValue;
    };
    
    class AdBrixRmCommerceProductAttrModel
    {
    public:
        AdBrixRmCommerceProductAttrModel(std::map<std::string, std::string> attrData);
        AdBrixRmCommerceProductAttrModel();
        static AdBrixRmCommerceProductAttrModel* create(std::map<std::string, std::string> attrData);
        
        const char* getValue (int pIndex);
        const char* getKey (int pIndex);
        
    private:
        
        const char * Key[5];
        const char * Value[5];
    };
    
    class AdBrixRmCommerceProductCategoryModel
    {
    public:
        static AdBrixRmCommerceProductCategoryModel* create(std::string category1);
        static AdBrixRmCommerceProductCategoryModel* create(std::string category1, std::string category2);
        static AdBrixRmCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3);
        static AdBrixRmCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3, std::string category4);
        static AdBrixRmCommerceProductCategoryModel* create(std::string category1, std::string category2, std::string category3, std::string category4, std::string category5);
        
        std::string categoryFullString;
    private:
        std::string category1;
        std::string category2;
        std::string category3;
        std::string category4;
        std::string category5;
        
    };
    
    class AdBrixRmCommerceProductModel: public AdBrixRmCommerceProductAttrModel, AdBrixRmCommerceProductCategoryModel
    {
        
    public:
        
        AdBrixRmCommerceProductModel(std::string productId, std::string productName, double price, double discount, int quantity, std::string currencyString, AdBrixRmCommerceProductCategoryModel *category, AdBrixRmCommerceProductAttrModel *extraAttrs);
        
        //std::string create(const char *productId, const char *productName, double price, double discount, int quantity, const char *currencyString, AdBrixCommerceProductCategoryModel category, AdBrixCommerceProductAttrModel *extraAttrs);
        
        std::string create(std::string productId, std::string productName, double price, double discount, int quantity, std::string currencyString, AdBrixRmCommerceProductCategoryModel *category, AdBrixRmCommerceProductAttrModel *extraAttrs);
    private:
        
        std::string _productID;
        double _price;
        double _discount;
        std::string _currencyString;
        std::string _category;
        int _quantity;
        std::string _productName;
        std::map<std::string, std::string> _extraAttrs;
    };
    
}} //namespace cocos2d { namespace plugin {

#endif /* __CCX_PLUGIN_PARAM_H__ */
