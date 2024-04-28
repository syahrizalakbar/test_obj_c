//
//  ProductCollectionViewCell.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "ProductCollectionViewCell.h"

@implementation ProductCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (void)setHidden:(BOOL)hidden {
        [_counter setHidden:hidden];
}

- (void)setView:(nonnull NSString *)name desc:(nonnull NSString *)desc priceLeft:(nonnull NSString *)priceLeft priceRight:(nonnull NSString *)priceRight qtyTotal:(nonnull NSString *)qtyTotal {
    [_name setText:name];
    [_desc setText:desc];
    [_priceLeft setText:priceLeft];
    [_priceRight setText:priceRight];
    [_qtyTotal.titleLabel setText:qtyTotal];
    if ([qtyTotal  isEqual: @"0"]) {
        [_counter setHidden:true];
    } else {
        [_counter setHidden:false];
    }
}

@end
