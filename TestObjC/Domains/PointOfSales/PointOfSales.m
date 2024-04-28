//
//  PointOfSales.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "PointOfSales.h"
#import "ProductService.h"

@implementation PointOfSales

- (instancetype)init
{
    self = [super init];
    _lineCart = [[NSMutableArray alloc] init];
    _productService = [[ProductService alloc] init];
    return self;
}

- (CGFloat)grandTotal {
    CGFloat total = 0;
    for (NSInteger i = 0; i < _lineCart.count; i++) {
        total += [_lineCart[i] calculateTotalPrice];
    }
    return total;
}

- (void)getTags {
    _tags = [[_productService getCatalog] mutableCopy];
}

- (void)setTagActive:(Tag *)tagActive {
    _tagActive = tagActive;
}

- (void)addCartBogo:(nonnull ProductBOGO *)productBogo index1:(NSInteger)index1 promoType:(PromoType)promoType{
    LineCart *newLine = [[LineCart alloc] init];
    BOOL duplicate = false;
    NSInteger i = 0;
    LineCart *updatedCart;
    for (LineCart *l in _lineCart) {
        if (l.indexDisplay1 == index1 && l.promoType == promoType) {
            duplicate = true;
            l.qty = l.qty + 1;
            updatedCart = l;
            break;
        }
        i++;
    }
    
    if (!duplicate) {
        [_lineCart addObject:[newLine addBogo:productBogo qty:1 index1:index1 promoType:promoType]];
    } else {
        _lineCart[i] = updatedCart;
    }
}

- (void)addCartCombo:(nonnull ProductCombo *)productCombo index1:(NSInteger)index1 promoType:(PromoType)promoType{
    LineCart *newLine = [[LineCart alloc] init];
    BOOL duplicate = false;
    NSInteger i = 0;
    LineCart *updatedCart;
    for (LineCart *l in _lineCart) {
        if (l.indexDisplay1 == index1 && l.promoType == promoType) {
            duplicate = true;
            l.qty = l.qty + 1;
            updatedCart = l;
            break;
        }
        i++;
    }
    if (!duplicate) {
        [_lineCart addObject:[newLine addCombo:productCombo qty:1 index1:index1 promoType:promoType]];
    } else {
        _lineCart[i] = updatedCart;
    }
}

- (void)addCartVoucher:(nonnull Voucher *)voucher index1:(NSInteger)index1 promoType:(PromoType)promoType {
    LineCart *newLine = [[LineCart alloc] init];
    BOOL duplicate = false;
    NSInteger i = 0;
    LineCart *updatedCart;
    for (LineCart *l in _lineCart) {
        if (l.indexDisplay1 == index1 && l.promoType == promoType) {
            duplicate = true;
            l.qty = l.qty + 1;
            updatedCart = l;
            break;
        }
        i++;
    }
    if (!duplicate) {
        [_lineCart addObject:[newLine addVoucher:voucher qty:1 index1:index1 promoType:promoType]];
    } else {
        _lineCart[i] = updatedCart;
    }
}

- (void)removeChart:(nonnull NSInteger *)removeItemFromCart {
    [_lineCart removeObjectAtIndex:*removeItemFromCart];
}

- (nonnull NSArray<Promotion *> *)serializedDisplay {
    NSMutableArray<Promotion*>* serialized = [[NSMutableArray alloc] init];
    for (Tag *t in _tags) {
        [serialized addObjectsFromArray:[t serialDisplay]];
    }
    
    return serialized;
}

@end
