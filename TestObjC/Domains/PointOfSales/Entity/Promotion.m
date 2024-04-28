//
//  Promotion.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "Promotion.h"
#import "PromoType.h"

@implementation Promotion

- (nonnull id)initWithValue:(NSInteger)promotionId name:(nonnull NSString *)name type:(PromoType*)type isAvailable:(BOOL)isAvailable minSpending:(NSInteger)minSpending {
    _promotionid = promotionId;
    _name = name;
    _type = type;
    _isAvailable = isAvailable;
    _minSpending = minSpending;
    _productCombo = [[NSMutableArray alloc] init];
    _productBogo = [[NSMutableArray alloc] init];
    _vouchers= [[NSMutableArray alloc] init];
    
    return self;
}

- (NSInteger)totalDisplay {
    NSInteger total = 0;
    switch (_type) {
        case Combo:
            return _productCombo.count;
            break;
        case BOGO:
            return _productBogo.count;
            break;
        case Vc:
            return _vouchers.count;
            break;
            
        default:
            break;
    }
}


@end
