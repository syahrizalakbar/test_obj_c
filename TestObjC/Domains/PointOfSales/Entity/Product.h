//
//  Product.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Product : NSObject

@property(nonatomic) NSInteger productId;
@property(nonatomic) NSInteger categoryId;
@property(nonatomic) NSInteger priceType;
@property(nonatomic) NSInteger status;
@property(nonatomic) NSString *name;
@property(nonatomic) NSString *code;
@property(nonatomic) NSString *unitPrice;
@property(nonatomic) NSInteger qty;

-(id) initWithValue:(NSInteger)productId categoryId:(NSInteger)categoryId priceType:(NSInteger)priceType status:(NSInteger)status name:(NSString*)name code:(NSString*)code unitPrice:(NSString*)unitPrice qty:(NSInteger)qty;

@end

NS_ASSUME_NONNULL_END
