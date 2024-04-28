//
//  LineCart.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "LineCart.h"
#import "PromoType.h"

@implementation LineCart

- (CGFloat)calculateTotalPrice {
    switch (_type) {
        case Combo:
            return (CGFloat)_qty * _productCombo.price;
            break;
            
        case BOGO:
            return (CGFloat)_qty * [_productBogo.product.unitPrice floatValue];
            break;
        case Vc:
            return 0;
            break;
    }
}

- (nonnull id)addBogo:(nonnull ProductBOGO *)product qty:(NSInteger)qty  index1:(NSInteger)index1 promoType:(PromoType)promoType {
    _productBogo = product;
    _qty = 1;
    _type = BOGO;
    _indexDisplay1 = index1;
    _promoType = promoType;
    return self;
}

- (nonnull id)addVoucher:(nonnull Voucher *)product qty:(NSInteger)qty  index1:(NSInteger)index1 promoType:(PromoType)promoType {
    _voucher = product;
    _qty = 1;
    _type = Vc;
    _indexDisplay1 = index1;
    _promoType = promoType;
    return self;
}
- (nonnull id)addCombo:(nonnull ProductCombo *)product qty:(NSInteger)qty  index1:(NSInteger)index1 promoType:(PromoType)promoType {
    _productCombo = product;
    _qty = 1;
    _type = Combo;
    _indexDisplay1 = index1;
    _promoType = promoType;
    return self;
}

@end
