//
//  Tag.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "Promotion.h"

NS_ASSUME_NONNULL_BEGIN

@interface Tag : NSObject

@property(nonatomic) NSString *name;
@property(nonatomic) NSMutableArray<Promotion*> *promotions;

-(NSInteger) totalAllDisplay;

-(NSArray<Promotion*>*) serialDisplay;

@end

NS_ASSUME_NONNULL_END
