//
//  LineCart.h
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

@interface LineCart : NSObject

@property(nonatomic, readonly) PromoType type;
@property(nonatomic) NSInteger qty;
@property(nonatomic, readonly) ProductCombo *productCombo;
@property(nonatomic, readonly) ProductBOGO *productBogo;
@property(nonatomic, readonly) Voucher *voucher;
@property(nonatomic) NSInteger indexDisplay1;
@property(nonatomic) PromoType promoType;

-(CGFloat) calculateTotalPrice;

-(id)addCombo:(ProductCombo*)product qty:(NSInteger)qty index1:(NSInteger)index1 promoType:(PromoType)promoType;
-(id)addBogo:(ProductBOGO*)product qty:(NSInteger)qty index1:(NSInteger)index1 promoType:(PromoType)promoType;
-(id)addVoucher:(Voucher*)product qty:(NSInteger)qty index1:(NSInteger)index1 promoType:(PromoType)promoType;

@end

NS_ASSUME_NONNULL_END
