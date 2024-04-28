//
//  IProductService.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 28/04/24.
//
#import "Tag.h"

@protocol IProductService

-(NSArray<Tag*>*) getCatalog;

@end
