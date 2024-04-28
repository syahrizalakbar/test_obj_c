//
//  ProductService.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "ProductService.h"
#import "ProductRepository.h"
#import "Tag.h"

@implementation ProductService

- (instancetype)init
{
    self = [super init];
    if (self) {
        _productRepository = [[ProductRepository alloc] init];
    }
    return self;
}

- (NSArray<Tag*> *)getCatalog { 
    return [_productRepository getCatalog];
}

@end
