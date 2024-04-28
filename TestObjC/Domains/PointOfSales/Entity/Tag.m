//
//  Tag.m
//  TestObjC
//
//  Created by Syahrizal Akbar on 27/04/24.
//

#import "Tag.h"

@implementation Tag


- (NSInteger)totalAllDisplay {
    NSInteger total = 0;
    for (Promotion *p in _promotions) {
        total += [p totalDisplay];
    }
    return total;
}


- (NSArray<Promotion*>*) serialDisplay {
    NSMutableArray<Promotion*>* serialized = [[NSMutableArray alloc] init];
    for (Promotion *p in _promotions) {
        switch (p.type) {
            case Combo:
                for (ProductCombo *c in p.productCombo) {
                    Promotion *temp = [[Promotion alloc] init];
                    temp.type = p.type;
                    temp.name = p.name;
                    temp.productCombo = [@[c] copy];
                    [serialized addObject:temp];
                }
                break;
            case BOGO:
                for (ProductBOGO *c in p.productBogo) {
                    Promotion *temp = [[Promotion alloc] init];
                    temp.type = p.type;
                    temp.name = p.name;
                    temp.productBogo = [@[c] copy];
                    [serialized addObject:temp];
                }
                break;
            case Vc:
                for (Voucher *c in p.vouchers) {
                    Promotion *temp = [[Promotion alloc] init];
                    temp.type = p.type;
                    temp.name = p.name;
                    temp.vouchers = [@[c] copy];
                    [serialized addObject:temp];
                }
                break;
            default:
                break;
        }
    }
    return serialized;
}

@end
