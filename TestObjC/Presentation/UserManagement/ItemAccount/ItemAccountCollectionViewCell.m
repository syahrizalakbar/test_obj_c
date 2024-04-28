//
//  ItemAccountCollectionViewCell.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "ItemAccountCollectionViewCell.h"

@implementation ItemAccountCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    
    [self.layer setBorderWidth:1];
    [self.layer setCornerRadius:10];
    [self.layer setBorderColor:[UIColor grayColor].CGColor];
}

- (void)setView:(nonnull NSString *)name phone:(nonnull NSString *)phone {
    [_name setText:name];
    [_phone setText:phone];
}

@end
