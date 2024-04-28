//
//  TagViewCollectionViewCell.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "TagViewCollectionViewCell.h"

@implementation TagViewCollectionViewCell

- (void)awakeFromNib {
    [super awakeFromNib];
    [_masterView.layer setBorderWidth:1];
    [_masterView.layer setCornerRadius:10];
}

- (void)setTag:(nonnull NSString *)tag {
    [_tagName setText:tag];
}

@end
