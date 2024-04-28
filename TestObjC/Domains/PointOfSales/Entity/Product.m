//
//  Product.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "Product.h"

@implementation Product

- (id)initWithValue:(NSInteger)productId categoryId:(NSInteger)categoryId priceType:(NSInteger)priceType status:(NSInteger)status name:(nonnull NSString *)name code:(nonnull NSString *)code unitPrice:( NSString *)unitPrice qty:(NSInteger)qty {
    _productId = productId;
    _priceType =priceType;
    _status = status;
    _name = name;
    _code = code;
    _unitPrice = unitPrice;
    _qty = qty;
    
    return self;
}

@end
