//
//  ProductService.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import <Foundation/Foundation.h>
#import "IProductService.h"
#import "IProductRepository.h"

NS_ASSUME_NONNULL_BEGIN

@interface ProductService : NSObject<IProductService> {
    id<IProductRepository> _productRepository;
}

@end

NS_ASSUME_NONNULL_END
