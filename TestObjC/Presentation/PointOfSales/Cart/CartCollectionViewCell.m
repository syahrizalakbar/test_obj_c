//
//  CartCollectionViewCell.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "CartCollectionViewCell.h"


@implementation CartCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    // Initialization code
}

- (IBAction)onRemove:(id)sender {
    _completionHandler(_index);
}

- (void)setView:(nonnull NSString *)title index:(NSInteger)index desc:(nonnull NSString *)desc total:(nonnull NSString *)total {
    [_title setText:title];
    [_desc setText:desc];
    [_total setText:total];
    _index = index;
}


@end
