//
//  Voucher.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "Voucher.h"

@implementation Voucher

- (nonnull id)initWithValue:(NSInteger)promotionId name:(nonnull NSString *)name type:(nonnull NSString *)type isAbailable:(BOOL)isAvailable minSpending :(NSInteger)minSpending {
    _promotionid = promotionId;
    _name =name;
    _type = type;
    _isAvailable = isAvailable;
    _minSpending = minSpending;
    
    return self;
}

@end
