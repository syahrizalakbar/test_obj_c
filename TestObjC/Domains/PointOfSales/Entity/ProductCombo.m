//
//  ProductCombo.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "ProductCombo.h"

@implementation ProductCombo

- (instancetype)init
{
    self = [super init];
    if (self) {
        _products = [[NSMutableArray alloc] init];
    }
    return self;
}

@end
