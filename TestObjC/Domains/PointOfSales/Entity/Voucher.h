//
//  Voucher.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Voucher : NSObject

@property(nonatomic, readonly) NSInteger promotionid;
@property(nonatomic, readonly) NSString *name;
@property(nonatomic, readonly) NSString *type;
@property(nonatomic, readonly) BOOL isAvailable;
@property(nonatomic, readonly) NSInteger minSpending;

-(id) initWithValue:(NSInteger)promotionId name:(NSString*)name type:(NSString*)type isAbailable:(BOOL)isAbailable minSpending:(NSInteger)minSpending;

@end

NS_ASSUME_NONNULL_END
