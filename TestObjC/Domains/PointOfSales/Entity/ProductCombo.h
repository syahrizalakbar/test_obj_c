//
//  ProductCombo.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "Product.h"

NS_ASSUME_NONNULL_BEGIN

@interface ProductCombo : NSObject

@property(nonatomic) NSInteger price;
@property(nonatomic) NSMutableArray<Product*> *products;

@end

NS_ASSUME_NONNULL_END
