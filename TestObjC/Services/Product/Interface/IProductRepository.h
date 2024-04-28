//
//  IProductRepository.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//

#import "Tag.h"

@protocol IProductRepository

-(NSArray<Tag*>*) getCatalog;


@end
