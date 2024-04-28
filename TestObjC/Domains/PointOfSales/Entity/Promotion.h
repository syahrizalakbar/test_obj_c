//
//  Promotion.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "PromoType.h"
#import "ProductCombo.h"
#import "ProductBOGO.h"
#import "Voucher.h"

NS_ASSUME_NONNULL_BEGIN

@interface Promotion : NSObject

@property(nonatomic) NSInteger promotionid;
@property(nonatomic) NSString *name;
@property(nonatomic) PromoType type;
@property(nonatomic) BOOL isAvailable;
@property(nonatomic) NSInteger minSpending;
@property(nonatomic) NSMutableArray<ProductCombo *> *productCombo;
@property(nonatomic) NSMutableArray<ProductBOGO *> *productBogo;
@property(nonatomic) NSMutableArray<Voucher *> *vouchers;

-(id) initWithValue:(NSInteger)promotionId name:(NSString*)name type:(PromoType)type isAvailable:(BOOL)isAvailable minSpending:(NSInteger)minSpending;

-(NSInteger) totalDisplay;

@end

NS_ASSUME_NONNULL_END
