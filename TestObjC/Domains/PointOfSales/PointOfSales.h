//
//  PointOfSales.h
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import <Foundation/Foundation.h>
#import "Tag.h"
#import "LineCart.h"
#import "IProductService.h"

NS_ASSUME_NONNULL_BEGIN

@interface PointOfSales : NSObject {
    id<IProductService> _productService;
}

@property(nonatomic, readonly) NSMutableArray<Tag*> *tags;
@property(nonatomic, readonly) Tag *tagActive;
@property(nonatomic, readonly) NSMutableArray<LineCart*> *lineCart;

-(void) getTags;
-(void) setTagActive:(Tag *)tagActive;
-(CGFloat) grandTotal;
-(void) addCartCombo:(ProductCombo *)productCombo index1:(NSInteger)index1 promoType:(PromoType)promoType;
-(void) addCartBogo:(ProductBOGO *)productBogo index1:(NSInteger)index1 promoType:(PromoType)promoType;
-(void) addCartVoucher:(Voucher *)voucher index1:(NSInteger)index1 promoType:(PromoType)promoType;
-(void) removeChart:(NSInteger *)removeItemFromCart;
-(NSArray<Promotion*>*) serializedDisplay;
@end

NS_ASSUME_NONNULL_END
